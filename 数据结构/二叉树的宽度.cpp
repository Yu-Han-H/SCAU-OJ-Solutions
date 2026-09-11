#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> left(51, 0), right(51, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        if (left[x] == 0)
            left[x] = y;
        else
            right[x] = y;
    }

    int maxWidth = 0;
    queue<int> q;
    q.push(1); // 从根节点开始
    while (!q.empty())
    {
        int levelsize = q.size(); // 当前层的节点数量
        if (levelsize > maxWidth)
            maxWidth = levelsize;

        for (int i = 0; i < levelsize; i++)
        {
            int u = q.front();
            q.pop();
            if (left[u] != 0)
                q.push(left[u]); // 将左子节点加入队列
            if (right[u] != 0)
                q.push(right[u]); // 将右子节点加入队列
        }
    }
    cout << maxWidth;
    return 0;
}