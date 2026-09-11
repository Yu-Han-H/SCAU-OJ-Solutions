#include <stdio.h>
#include <string.h>

int n;
int tot;
int vis[3][30];

void search(int cur)
{
    if (cur == n)
    {
        tot++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n])
        {
            vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
            search(cur + 1);
            vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0; // 回溯
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        tot = 0;
        memset(vis, 0, sizeof(vis));
        search(0);
        printf("%d\n", tot);
    }
    return 0;
}