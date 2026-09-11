/*
 * 电路布线问题 (Circuit Wiring)
 *
 * 问题描述：
 *   在一块电路板的上、下两端各有 n 个接线柱。
 *   上端接线柱 i 与下端接线柱 π(i) 相连 (1 ≤ i ≤ n)
 *   要求选出最多的连线，使得这些连线互不相交。
 *
 * 思路：
 *   两根连线 (i, π(i)) 和 (j, π(j)) 相交的条件是：
 *     i < j 且 π(i) > π(j)
 *   所以从不交叉 -> 要求 π 的下标和值都递增
 *   -> 转化为求 π 的 最长上升子序列(LIS)
 *
 * 方法一：O(n²) DP
 *   dp[i] = 以 π[i] 结尾的最长上升子序列长度
 *   dp[i] = max{ dp[j] + 1 | j < i 且 π[j] < π[i] }
 *
 * 方法二：O(n log n) 贪心+二分（更快）
 *   维护一个数组 d，d[len] = 长度为 len 的上升子序列的最小末尾值
 */

#include <iostream>
#include <algorithm>
using namespace std;

int n;           // 接线柱个数
int p[10005];    // p[i] = 下端接线柱编号，表示上端 i 连到下端 p[i]
int dp[10005];   // dp[i] = 以 p[i] 结尾的最长上升子序列长度

int main()
{
    // ---- 输入 ----
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    // ---- 方法一：O(n²) DP 求LIS ----
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;  // 每个元素自己就是一个长度为1的序列
        for (int j = 1; j < i; j++)
        {
            if (p[j] < p[i])                    // 可以接在后面
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}
