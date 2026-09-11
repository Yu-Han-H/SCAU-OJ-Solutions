#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int sx, sy, ex, ey; // 起始点
int a[105][105];    // 地图
int vis[105][105];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct Point
{
    int x, y, step;
};

int bfs()
{
    queue<Point> q;
    memset(vis, 0, sizeof(vis));

    q.push({sx, sy, 0});
    vis[sx][sy] = 1;

    while (!q.empty())
    {
        Point now = q.front();
        q.pop();

        // 到达终点，返回当前步数
        if (now.x == ex && now.y == ey)
            return now.step;

        for (int i = 0; i < 4; i++)
        {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            // 判断是否越界、是否是墙、是否走过
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == 0 && !vis[nx][ny])
            {
                vis[nx][ny] = 1;
                q.push({nx, ny, now.step + 1});
            }
        }
    }
    return 0; // 队列空了还没到，走不到
}

int main()
{
    cin >> n >> m;
    cin >> sx >> sy >> ex >> ey;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    cout << bfs() << endl;
    return 0;
}
