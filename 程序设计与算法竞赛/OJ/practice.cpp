#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    do
    {
        int ok = 1;
        for (int i = 1; i < n; i++)
        {
            if (v[i] % 2 == 1 && v[i - 1] % 2 == 1)
            {
                ok = 0;
                break;
            }
        }
        if (ok)
        {
            for (int i = 0; i < n; i++)
                cout << v[i] << " ";
            cout << endl;
        }
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}