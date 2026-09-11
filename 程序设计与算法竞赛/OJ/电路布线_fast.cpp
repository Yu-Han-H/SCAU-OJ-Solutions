/*
 * 电路布线问题 —— O(n log n) 二分优化版
 *
 * 核心思想：
 *   维护数组 d，d[len] = 长度为 len 的上升子序列的最小末尾值
 *   遍历 p[i]，在 d 中二分查找第一个 ≥ p[i] 的位置，替换掉
 *   最终 d 的长度就是 LIS 长度
 */

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int p[10005];
int d[10005];  // d[len] = 长度为 len 的上升子序列的最小末尾值

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    int len = 0;
    d[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        // 在 d[1..len] 中找第一个 ≥ p[i] 的位置
        int pos = lower_bound(d + 1, d + len + 1, p[i]) - d;

        d[pos] = p[i];
        if (pos > len) len = pos;  // 扩展了序列长度
    }

    cout << len << endl;

    return 0;
}
