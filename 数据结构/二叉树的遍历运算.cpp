#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

void post(const string& pre, const string& in)
{
    if (pre.empty())
        return;
    char root = pre[0];
    int pos = in.find(root);
    post(pre.substr(1, pos), in.substr(0, pos));
    post(pre.substr(pos + 1), in.substr(pos + 1));
    cout << root;
}

int main()
{
    string pre, in;
    cin >> pre >> in;
    post(pre, in);
    return 0;
}