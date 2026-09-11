/*18107 校赛排名

Description
校赛结束了，每一个参赛选手由3个数据项构成（通过题数，用时分钟数，姓名），排名按照通过题数排序
通过题数多的排前，同题数的，罚时少的排前。如果题数相同，罚时也相同，而按数据读取的先后排。
给你N个参赛选手的数据，按排序先后，输出姓名

输入格式
第一个数为N，（N<=500000）
此后，每行一个参赛选手的数据，通过题数，用时分钟数，姓名，前两者为整型数，姓名为字符串（不多于20个字符）

输出格式
姓名排名

输入样例
4
3 5 Jon
5 100 Smith
3 5 Tom
6 95 Hel

输出样例
Hel
Smith
Jon
Tom*/
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Node
{
    int ac;
    int time;
    string name;
    int idx;
};

bool cmp(const Node &a, const Node &b)
{
    if (a.ac != b.ac)
        return a.ac > b.ac;
    if (a.time != b.time)
        return a.time < b.time;
    return a.idx < b.idx;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<Node> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].ac >> v[i].time >> v[i].name;
        v[i].idx = i;
    }
    sort(v.begin(), v.end(), cmp);
    for (auto it = v.begin(); it != v.end(); it++)
        cout << it->name << '\n';
    return 0;
}