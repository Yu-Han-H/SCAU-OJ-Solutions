/*19648 分数拆分

描述：
输入一个正整数，找到所有的正整数x>=y,使得1/k=1/x+1/y

输入格式：
一个正整数n，n<=100000

输出格式：
一行一个分式等式
小的分数显示在前面；多个等式，等式右边第一个分数小的先输出

输入样例：
2

输出样例：
1/2=1/6+1/3
1/2=1/4+1/4*/
#include <stdio.h>

int main()
{
    long long k;
    scanf("%lld", &k);

    for (long long y = k + 1; y <= k * 2; y++)
    {
        if ((k * y) % (y - k) == 0)
        {
            long long x = (k * y) / (y - k);
            printf("1/%lld=1/%lld+1/%lld\n", k, x, y);
        }
    }

    return 0;
}