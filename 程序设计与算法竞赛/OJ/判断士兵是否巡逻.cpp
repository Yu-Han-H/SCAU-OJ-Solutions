/*19144 判断士兵是否会被选中巡逻

Description
有N个士兵站成一队列, 现在需要选择几个士兵派去侦察。
为了选择合适的士兵, 多次进行如下操作: 如果队列超过三个士兵, 那么去除掉所有站立位置为奇数的士兵,
或者是去除掉所有站立位置为偶数的士兵。直到不超过三个战士，他们将被送去侦察。现有一个“聪明”的士兵，
经常通过选择站在合适的初始位置，成功避免被选中去侦察。这引起了陈教官的注意。陈教官希望你编写一个程序，
当给定士兵数，以及位置编号，判断站在该位置编号的战士是否可能被抽中巡逻。

注: 按上法得到少于三士兵的情况不用去巡逻。

1 <= N <= 100000

输入格式
有多行（不多于10000行），每行两个数字，第一个数字是士兵人数，第二个数字是位置编号，最后一行是两个0，表示结束

输出格式
对每一行输入，输出一行结果，能被抽中输出Y，不能抽中输出N

最后一行两个0不需要

输入样例
4 1
5 1
0 0

输出样例
N
Y
*/
#include <iostream>
#include <cstdio>

using namespace std;

int judge(int n, int a, int step, int f)
{
    if (n < 3)
        return 0;
    if (n == 3)
        return 1;
    if ((f - a) % (2 * step) == 0)
        return judge((n + 1) / 2, a, step * 2, f);
    else
        return judge(n / 2, a + step, step * 2, f);
}

int main()
{
    int n, loc;
    while (scanf("%d%d", &n, &loc), n != 0 || loc != 0)
        if (judge(n, 1, 1, loc))
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    return 0;
}