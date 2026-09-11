#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

bool used[100];
int n = 0, target = 0;
vector<int> sticks;

bool dfs(int completed, int cur, int start, int need)
{
    if (completed == need)
        return true;

    for (int i = start; i < n; i++)
    {
        if (used[i])
            continue;
        if (cur + sticks[i] > target)
            continue;

        used[i] = true;

        if (cur + sticks[i] == target)
        {
            if (dfs(completed + 1, 0, 0, need))
                return true;
        }
        else if (dfs(completed, cur + sticks[i], i + 1, need))
            return true;

        used[i] = false;

        if (cur == 0)
            return false;

        if (cur + sticks[i] == target)
            return false;

        while (i + 1 < n && sticks[i + 1] == sticks[i])
            i++;
    }
    return false;
}

int main()
{
    while (cin >> n && n)
    {
        sticks.resize(n);
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> sticks[i];
            total += sticks[i];
        }

        sort(sticks.begin(), sticks.end(), greater<int>()); // 降序排列，便于剪枝

        bool ok = false;
        for (int L = sticks[0]; L <= total / 2; L++)
        {
            if (total % L != 0)
                continue;
            target = L;
            memset(used, 0, sizeof(used));
            if (dfs(0, 0, 0, total / L))
            {
                cout << L << endl;
                ok = true;
                break;
            }
        }
        if (!ok)
            cout << total << endl;
    }
    return 0;
}