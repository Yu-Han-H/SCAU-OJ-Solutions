#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

struct node
{
    int arr;
    int level;
    char name[20];
    int idx;
};

struct cmp
{
    bool operator()(const node &a, const node &b)
    {
        if (a.level != b.level)
            return a.level < b.level;
        if (a.arr != b.arr)
            return a.arr > b.arr;
        return a.idx > b.idx;
    }
};

int main()
{
    int n, close, current = 0;
    cin >> n >> close;
    vector<node> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].arr >> v[i].level >> v[i].name;
        v[i].idx = i;
    }
    priority_queue<node, vector<node>, cmp> pq;
    int ptr = 0;
    while (current < close)
    {
        while (ptr < n && v[ptr].arr <= current)
        {
            pq.push(v[ptr]);
            ptr++;
        }

        if (!pq.empty())
        {
            cout << pq.top().name << '\n';
            pq.pop();
        }

        current += 5;
    }
    return 0;
}