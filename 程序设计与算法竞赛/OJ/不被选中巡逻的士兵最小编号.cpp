/*不被选中巡逻的士兵最小编号

Description
有N个士兵站成一队列, 现在需要选择几个士兵派去侦察。
为了选择合适的士兵, 多次进行如下操作: 如果队列超过三个士兵, 那么去除掉所有站立位置为奇数的士兵, 
或者是去除掉所有站立位置为偶数的士兵。直到不超过三个战士，他们将被送去侦察。现有一个“聪明”的士兵，
经常通过选择站在合适的初始位置，成功避免被选中去侦察。这引起了陈教官的注意。陈教官希望你编写一个程序，
当给定士兵数之后，输出不可能被选中去巡逻的最少编号位置（如果不存在不可能被选中的位置，则输出0）。

注: 按上法得到少于三士兵的情况不用去巡逻。

1 <= N <= 100000

输入格式
有多行（不多于20行），每行一个数字N，最后一行是0

输出格式
对每一行的数字N，不可能被选中去巡逻的最小位置
直到没有数字

输入样例
9
6
0

输出样例
2
0
*/
#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool safe(int t, int b)
{
    if (t <= 2)
        return 1;
    if (t == 3)
        return 0;
    bool SO = (b % 2 == 1) ? 1 : safe(t / 2, b / 2);
    bool SE = (b % 2 == 0) ? 1 : safe((t + 1) / 2, (b + 1) / 2);
    return SO && SE;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    while (cin >> t && t != 0)
    {
        int s = 0;
        for (int i = 1; i <= t; i++)
        {
            if (safe(t, i))
            {
                s = i;
                break;
            }
        }
        cout << s << endl;
    }
    return 0;
}