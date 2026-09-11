/*输入正整数n,按从小到大的顺序输出所有形如abcde/fghij=n的表达式，
其中a~j恰好为数字0~9的一个排列，2<=n<=79。
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n;
    char a[100];
    while (scanf("%d", &n) == 1 && n)
    {
        for (int fghij = 1; fghij <= 99999; fghij++)
        {
            int ok = 1;
            int abcde = fghij * n;
            sprintf(a, "%05d%05d", abcde, fghij); // 将abcde和fghij转换成字符串，存储在a中，便与后续排序
            if (abcde > 99999)
                break;
            if (strlen(a) > 10)
                break;
            sort(a, a + 10);
            for (int i = 1; i < 10; i++)
            {
                if (a[i] != '0' && a[i] == a[i - 1])
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
                printf("%05d/%05d=%d\n", abcde, fghij, n);
        }
        printf("\n");
    }
    return 0;
}