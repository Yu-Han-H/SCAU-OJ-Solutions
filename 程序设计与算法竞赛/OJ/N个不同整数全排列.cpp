/*19412 N个不同整数全排列

描述：
由键盘输入N个不同的整数，输出这N个数的全部排列。

输入格式：
第一行一个正整数。N<=5
每二行N个整数，以空格分隔。

输出格式：
每行一个排列，数之间由一个空格分隔，要求排列按由小到大输出，不允许重复。

输入样例：
3
3 9 1

输出样例：
1 3 9
1 9 3
3 1 9
3 9 1
9 1 3
9 3 1*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n, P[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", P + i);
    sort(P, P + n);
    do
    {
        for (int i = 0; i < n; i++)
            printf("%d ", P[i]);
        printf("\n");
    } while (next_permutation(P, P + n));

    return 0;
}