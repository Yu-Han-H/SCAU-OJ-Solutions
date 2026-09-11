// 最长递增序列 <动态规划> <复杂度0(N^2)>
#include <iostream>
#include <vector>
using namespace std;

vector<int> getdp1(vector<int> &arr);
vector<int> generateLIS(vector<int> &arr, vector<int> &dp);

int main()
{
    vector<int> arr;
    int temp;
    while (cin >> temp)
        arr.push_back(temp);
    vector<int> dp = getdp1(arr);
    vector<int> lis = generateLIS(arr, dp);
    for (int i = 0; i < lis.size(); i++)
    {
        cout << lis[i] << " ";
    }
    return 0;
}

vector<int> getdp1(vector<int> &arr)
{
    vector<int> dp(arr.size(), 0);
    for (int i = 0; i < arr.size(); i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
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
            len = dp[i]; // 最长序列长度
            index = i;   // 最长序列末位置
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
*/
