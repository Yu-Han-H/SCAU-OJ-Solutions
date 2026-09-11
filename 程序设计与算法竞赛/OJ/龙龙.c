#include <stdio.h>

// H(n) = sum_{i=1}^{n} floor(n/i)
// 利用 floor(n/i) 只有 O(sqrt(n)) 种取值来加速
long long H(int n)
{
    long long res = 0;
    long long i;
    for (i = 1; i <= n;)
    {
        long long v = n / i;        // 当前段的商值
        long long next = n / v + 1; // 下一个商值变化的位置
        res += v * (next - i);
        i = next;
    }
    return res;
}

int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        printf("%lld\n", H(n));
    }
    return 0;
}
