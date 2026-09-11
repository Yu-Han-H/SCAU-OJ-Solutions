/*18441 不巡逻的士兵

Description
有N个士兵站成一队列, 现在需要选择几个士兵派去侦察。
为了选择合适的士兵, 多次进行如下操作: 如果队列超过三个士兵, 那么去除掉所有站立位置为奇数的士兵,
或者是去除掉所有站立位置为偶数的士兵。直到不超过三个战士，他们将被送去侦察。现有一个“聪明”的士兵，
经常通过选择站在合适的初始位置，成功避免被选中去侦察。这引起了陈教官的注意。陈教官希望你编写一个程序，
当给定士兵数之后，输出有多少个位置上的士兵是不可能被选中去巡逻的。

注: 按上法得到少于三士兵的情况不用去巡逻。

1 <= N <= 21亿

输入格式
有多行（可能有上百行，请尽量优化代码），每行一个数字N，最后一行是0

输出格式
对每一行的数字N，不可能被选中去巡逻的位置数,直到没有数字

输入样例
10
6
0


输出样例
4
0*/
#include <iostream>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
map<ll, ll> fa;
ll f(int i)
{
    if (i < 3)
        return i;
    if (i == 3)
        return 0;
    else if (fa.find(i) != fa.end())
        return fa[i];
    else
        return fa[i] = f(i / 2) + f((i + 1) / 2);
}

int main()
{
    int n;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        printf("%lld\n", f(n));
    }
}