#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int sx, sy, ex, ey;
int a[105][105];
int vis[105][105];
int ans;

// 四个方向：上、下、左、右
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int step)
{
    if (step >= ans)
        return;

    if (x == ex && y == ey)
    {
        if (step < ans)
            ans = step;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == 0 && !vis[nx][ny])
        {
            vis[nx][ny] = 1;
            dfs(nx, ny, step + 1);
            vis[nx][ny] = 0; // 回溯
        }
    }
}

int main()
{
    cin >> n >> m;
    cin >> sx >> sy >> ex >> ey;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    ans = 999999;
    vis[sx][sy] = 1;
    dfs(sx, sy, 0);

    if (ans == 999999)
        cout << "Error" << endl;
    else
        cout << ans << endl;
    return 0;
}
