/*18705 01背包问题

Description
有一个容积为C的背包和N件物品。第i件物品的体积W[i]，价值是V[i]。求解将哪些物品装入背包可使价值总和最大。每种物品只有一件，
可以选择放或者不放入背包。

输入格式
第一行：两个整数，C(背包容量，C<=200)和N(物品数量，N<=30)；
第2..N+1行：每行二个整数Wi，Vi，表示每个物品的重量和价值。

输出格式
一个数，表示最大总价值。

输入样例
10 4
2 1
3 3
4 5
7 9

输出样例
12*/
#include <cstdio>
#include <algorithm>

using namespace std;

int w[40], v[40];     // 记录各个物体的重量和价值
int m[40][240] = {0}; // 记录子问题的解

int main()
{
    int n, C; // n是个数，C是最大重量

    scanf("%d%d", &C, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &w[i], &v[i]);
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j <= C; j++)
        {
            if (j >= w[i])
                m[i][j] = max(m[i + 1][j], m[i + 1][j - w[i]] + v[i]); // 取或不取
            else
                m[i][j] = m[i + 1][j]; // 只能不取
        }
    }

    printf("%d\n", m[1][C]);
    return 0;
}
