/*19735 M皇后问题

描述：
有M*M的国际象棋棋盘，要求在上面放M个皇后，要求任意两个皇后不会互杀，除此之外，棋盘中有一个指定的特殊位置不能放置皇后，问符合要求的放置方法有多少种？

输入格式：
每一个数为T，代表CASE的数量，T<=13
此后，每行三个数M，X, Y（13>=M>0，M>=X>=1, M>=Y>=1），（X，Y）是不能放置皇后的位置。

输出格式：
每一个CASE，输出对应答案，一行一个数

输入样例：
2
4 1 3
5 2 2

输出样例：
1
8*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

int F(int m, int cur, int *A, int x, int y)
{
    if (cur == m)
        return 1;
    else
    {
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            int ok = 1;
            for (int j = 0; j < cur; j++)
                if (A[j] == i || abs(cur - j) == abs(A[j] - i))
                {
                    ok = 0;
                    break;
                }
            if (ok && !(cur + 1 == x && i + 1 == y))
            {
                A[cur] = i;
                res += F(m, cur + 1, A, x, y);
            }
        }
        return res;
    }
}

int main()
{
    int T, m, x, y, A[30];
    cin >> T;
    while (T--)
    {
        cin >> m >> x >> y;
        cout << F(m, 0, A, x, y) << endl;
    }
    return 0;
}