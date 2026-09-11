#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, max = 0, end = 0;
    cin >> n;
    vector<int> p(n), dp(n, 1), pre(n, -1);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            if (p[j] < p[i] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                pre[i] = j;
            }
        if (dp[i] > max)
        {
            max = dp[i];
            end = i;
        }
    }
    cout << max << endl;
    vector<int> rev;
    for (int i = end; i != -1; i = pre[i])
        rev.push_back(p[i]);
    for (int i = rev.size() - 1; i >= 0; i--)
        cout << rev[i] << " ";
    return 0;
}