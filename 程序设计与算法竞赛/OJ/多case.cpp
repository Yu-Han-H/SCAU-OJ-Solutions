/*有三批测试数据，第1批测试数据，开头会以一个数字告之该批CASE数量，每一个CASE是两个正整数(最大2的31次方)；
第1批测试数据结束后，紧接着是第2批数据，每一个CASE同样是两个正整数，第2批测试数据以两个0结束；
第2批测试数据结束后，紧接着是第3批数据，每一个CASE也是两个正整数，第3批测试数据一直到数据输入结束；*/
#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int m, int n)
{
    if (m % n == 0)
        return n;
    else
        return gcd(n, m % n);
}

int main()
{
    int m, n, t;
    long long result;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        result = m;
        result *= n;
        result /= gcd(m, n);
        cout << result << endl;
    }
    cout << "group 1 done" << endl;
    while (1)
    {
        cin >> m >> n;
        if (m == 0 && n == 0)
            break;
        result = m;
        result *= n;
        result /= gcd(m, n);
        cout << result << endl;
    }
    cout << "group 2 done" << endl;
    while (scanf("%d%d", &m, &n) > 0)
    {
        result = m;
        result *= n;
        result /= gcd(m, n);
        cout << result << endl;
    }
    cout << "group 3 done" << endl;
    return 0;
}