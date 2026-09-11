/*19010 最小的特殊数字

Description
用全部N(N<=10)个0-9的数字组成一个“有效”整数（即没有前置0的整数），
求这些组成的数中能被K(0<K<10^10)整除的最小数字。

输入格式
输入分两行，第一行输入N, K，第二行输入N个数字。

输出格式
输出满足条件的最小的数（不含前置0），如果没有满足条件的数输出 -1。

输入样例
4 7
4 0 1 3

输出样例
1043

提示
413 % 7 = 0， 但是有前置0，所以满足条件的最小数是 1043 % 7 = 0。
此类题目需注意特殊情况，比如n=1时,提供的数字是0，答案只能是0。
注意long long*/
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n, P[100], m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", P + i);
    sort(P, P + n);
    if (n == 1 && P[0] == 0)
    {
        printf("0");
        return 0;
    }
    int ok = 0;
    do
    {
        long long ret = 0;
        for (int i = 0; i < n; i++)
            ret = ret * 10 + P[i];

        if (ret % m == 0 && P[0] != 0)
        {
            for (int i = 0; i < n; i++)
                printf("%d", P[i]);
            ok = 1;
            break;
        }
    } while (next_permutation(P, P + n));
    if (!ok)
        printf("-1");
    return 0;
}