// 最长递增序列 <动态规划> <复杂度0(NlogN)>
#include <iostream>
#include <vector>
using namespace std;
vector<int> getdp2(vector<int> &arr);
vector<int> generateLIS(vector<int> &arr, vector<int> &dp);

int main()
{
    vector<int> arr;
    int temp;
    while (cin >> temp)
        arr.push_back(temp);
    vector<int> dp = getdp2(arr);
    vector<int> lis = generateLIS(arr, dp);
    for (int i = 0; i < lis.size(); i++)
        cout << lis[i] << " ";
    return 0;
}

vector<int> getdp2(vector<int> &arr)
{
    vector<int> dp(arr.size(), 0);
    vector<int> ends(arr.size(), 0);
    ends[0] = arr[0];
    dp[0] = 1;
    int right = 0;
    int l = 0;
    int r = 0;
    int m = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        l = 0;
        r = right; // 在有效区 ends[0..right] 里找
        while (l <= r)
        { // 二分法
            m = (l + r) / 2;
            if (arr[i] > ends[m])
            {
                l = m + 1; // 位于ends[m + 1,right]之间
            }
            else
            {
                r = m - 1; // 位于ends[l,m - 1]之间
            }
        }
        right = max(right, l);
        ends[l] = arr[i];
        dp[i] = l + 1;
    }
    return dp;
}

vector<int> generateLIS(vector<int> &arr, vector<int> &dp)
{
    int len = 0;
    int index = 0;
    for (int i = 0; i < dp.size(); i++)
    { // 寻最长递增子序列末尾的位置和值
        if (dp[i] > len)
        {
            len = dp[i];
            index = i;
        }
    }
    vector<int> lis(len, 0);
    lis[--len] = arr[index];
    for (int i = index; i >= 0; i--)
    {
        if (arr[i] < arr[index] && dp[i] == dp[index] - 1)
        { // 从后往前找子序列
            lis[--len] = arr[i];
            index = i;
        }
    }
    return lis;
}
/* input
2 1 5 3 6 4 8 9 7
*/
/* output
1 3 4 8 9


核心思想:同样长度的递增序列,结尾越小越值钱。所以我们只记每种长度"最小的结尾"。
为什么结尾小就值钱?举个例子。假设你现在有两条长度都是 3 的递增序列:
A: 2 5 8   结尾是 8
B: 2 3 4   结尾是 4
接下来不管来什么数,B 能接的,A 不一定能接;A 能接的,B 一定能接。比如来个 6:B 可以变成 2 3 4 6(长度4),A 接不了(6<8)。结尾小的 B 完全碾压 A。
所以 A 这条序列我们根本不用留,留着也没用——任何时候 B 都比它强。对每一种长度,我们只保留结尾最小的那一条就够了。
ends 数组就是干这个的:
ends[0] = 长度1的序列里,最小的结尾
ends[1] = 长度2的序列里,最小的结尾
ends[2] = 长度3的序列里,最小的结尾
...
现在来了一个新数 x(就是 arr[i]),它能干两件事之一:
情况一:x 比所有结尾都大。 那它能接在最长的那条后面,造出一条更长的序列。ends 多一位,LIS 变长了。
情况二:x 卡在中间。 比如 ends = [1, 3, 8],来了个 5。5 接不到 8 后面(造不出长度4),但它能造出一条新的长度3序列,结尾是 5——比原来的 8 小!根据"结尾越小越值钱",用 5 把 8 换掉:
ends: [1, 3, 8]  →  [1, 3, 5]
这次替换不让 LIS 变长,但它为将来铺路:以后来个 6、7,就能接在 5 后面了,而原来的 8 接不了。
整个算法就是这两件事反复做:每个新数,要么把序列接长,要么把某个长度的结尾换得更小。 仅此而已。
那为什么这能算出 LIS 长度?因为 ends 的长度(有效区多长),始终等于"目前能造出的最长递增序列有多长"。每发生一次"情况一",长度就 +1。所以扫完整个数组,ends 有多长,LIS 就有多长。
二分查找只是个加速手段——ends 天然是从小到大排好序的(这是它的性质),所以找"x 该插在哪个位置"可以用二分,不用一个个比。这是为什么复杂度能降到 NlogN,但它不是核心思想,只是实现技巧。
*/
