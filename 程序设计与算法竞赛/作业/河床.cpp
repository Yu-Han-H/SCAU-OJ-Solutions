/*
河床
地理学家们经常要对一段河流进行测量分析。他们从上游开始向下游方向等距离地选择了n (≤30000)个点测量水位深度。得到一组数据d1, d2,..., dn,到实验室后数据分析员根据需要对数据进行分析，发掘隐藏在数据背后的规律。最近，乌龙博士发现某种水文现象与河床地势有关，于是他指示分析员要找出一段河流中最大高低起伏差不超过k(≤100)的最长一段。这看似一个复杂的问题，由于任务紧急，分析员来求助于你，并告诉你博士的所有数据都精确到个位。
输入格式
输入文件有2行。第1行是整数n和k，分别表示测量点的个数和博士要求的最大水深差(也就是河床地势差)。第2行有n个整数，表示从上游开始依次得到的水位深度di(1≤i≤n, 0≤di≤32767)。
输出格式
输出文件只有1行，是整数m，表示最长一段起伏不超过k的河流长度，用测量点个数表示。
输入样例
6 2 5 3 2 2 4 5
输出样例
4
Hint
从第2个测量点到第5个测量点之间的一段，即3 2 2 4，起伏最大为4-2=2
*/
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int n, k;
int a[30005];
deque<int> qmax;
deque<int> qmin;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int l = 1;
    int ans = 0;

    for (int r = 1; r <= n; r++)
    {
        while (!qmax.empty() && a[qmax.back()] <= a[r])
            qmax.pop_back();
        qmax.push_back(r);

        while (!qmin.empty() && a[qmin.back()] >= a[r])
            qmin.pop_back();
        qmin.push_back(r);

        while (a[qmax.front()] - a[qmin.front()] > k)
        {
            l++;
            if (qmax.front() < l)
                qmax.pop_front();
            if (qmin.front() < l)
                qmin.pop_front();
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
    return 0;
}
