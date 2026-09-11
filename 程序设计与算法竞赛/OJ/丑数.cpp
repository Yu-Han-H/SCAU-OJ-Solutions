/*
19116 丑数

Description
“丑数”是指除了质因子2,3，5，不含其它质因子的正整数，例如由小到大前10个“丑数”为
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, ...
现要求编写一个程序，输出指定第几位的“丑数”。

输入格式
第一行为正整数T（T<=10000）, 表示case的数目。
此后T行，每行一个正整数 n (确定该第n个凑数不超过1000000000).

输出格式
每一个n，输出第n个“丑数”

输入样例
3
1
2
9

输出样例
1
2
10
*/
#include <iostream>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;

const int MAX = 10005;
ll ugly[MAX]; // 预处理好所有丑数

void init()
{
    priority_queue<ll, vector<ll>, greater<ll>> q;
    set<ll> s;

    q.push(1);
    s.insert(1);

    for (int i = 1; i < MAX; i++)
    {
        ll top = q.top();
        q.pop();
        ugly[i] = top;

        // 乘2
        if (!s.count(top * 2))
        {
            s.insert(top * 2);
            q.push(top * 2);
        }
        // 乘3
        if (!s.count(top * 3))
        {
            s.insert(top * 3);
            q.push(top * 3);
        }
        // 乘5
        if (!s.count(top * 5))
        {
            s.insert(top * 5);
            q.push(top * 5);
        }
    }
}

int main()
{
    init();

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << ugly[n] << '\n';
    }
    return 0;
}