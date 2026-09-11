/*19650 有重复元素排列问题

描述：
从键盘输入N个整数N<=10,要求输出这N个整数的全排列，且每一个排列当中，相邻两个数不能同为奇数。

输入格式：
第一行一个正整数N
第二行N个整数，以空格分隔

输出格式：
一行一个排列，按小到大的顺序输出

输入样例：
3
1 1 2

输出样例：
1 2 1*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
typedef long long ll;
using namespace std;

int main()
{
    int n, P[100];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> P[i];
    sort(P, P + n);
    do
    {
        int ok = 1;
        for (int i = 1; i < n; i++)
            if (P[i - 1] % 2 == 1 && P[i] % 2 == 1)
                ok = 0;
        if (ok)
        {
            for (int i = 0; i < n; i++)
                cout << P[i] << " ";
            cout << "\n";
        }
    } while (next_permutation(P, P + n));
    return 0;
}