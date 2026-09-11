/*有n个头的恶龙，你希望雇一些骑士把它杀死（即砍掉所有头）。村里有ｍ个骑士可以雇佣，一个能力值为x的骑士可以砍掉恶龙
一个直径不超过x的头，且需要支付x个金币。如何雇佣骑士才能砍掉恶龙的所有头，且需要支付的金币最少？注意，一个骑士只
能砍一个头（且不能被雇佣两次）*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        vector<int> dragons(n), knights(m);
        for (int i = 0; i < n; i++)
            cin >> dragons[i];
        for (int i = 0; i < m; i++)
            cin >> knights[i];
        sort(knights.begin(), knights.end());
        sort(dragons.begin(), dragons.end());
        int cost = 0, i = 0, j = 0;
        while (i < n && j < m)
        {
            if (dragons[i] <= knights[j])
            {
                cost += knights[j];
                i++;
                j++;
            }
            else
                j++;
        }
        if (i == n)
            cout << cost << endl;
        else
            cout << "Loowater is doomed!" << endl;
    }
    return 0;
}