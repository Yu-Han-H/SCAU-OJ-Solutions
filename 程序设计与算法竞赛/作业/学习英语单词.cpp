/*
学习英语单词
    我们都知道，学习英语单词最好的方法就是在相应的句子和语言环境中学习。小W最近定下了一个学习单词的计划，他要背n个单词，但他想通过背一篇文章中的一段来记住这些单词。
假定现在小W手中有一篇包含m个单词的文章，他想在文章中找出连续的一段，其中包含最多的他所要背的单词(重复的只算一个)，并且使这段连续的单词长度最短。这样他就可以用尽量短的时间学习尽可能多的单词了。
输入格式
    第1行一个数n (1≤n≤1000)。接下来n行每行是一个长度不超过10的字符串，表示一个要背的单词。接着是一个数m (1≤m≤100000 )然后是m行长度不超过10的字符串，每个表示文章中的一个单词。
输出格式
    输出文件共2行。第1行为文章中最多包含的要背的单词数，第2行表示在文章中包含最多要背单词的最短的连续段的长度。
输入样例
3 hot dog milk 5 hot dog dog milk hot
输出样例
3 3
*/
#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
map<string, int> book; // 要背的单词及对应编号
int id[100005];        // 文章中每个单词对应的编号
int cnt[1005];         // 当前窗口内要背单词出现的次数

int main()
{
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        book[s] = i;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> s;
        if (book.count(s))
            id[i] = book[s];
        else
            id[i] = 0;
    }

    int l = 1;
    int unique = 0;
    int maxUnique = 0;
    memset(cnt, 0, sizeof(cnt));

    for (int r = 1; r <= m; r++)
    {
        if (id[r] != 0)
        {
            if (cnt[id[r]] == 0)
                unique++;
            cnt[id[r]]++;
        }

        while (l <= r)
        {
            if (id[l] != 0 && cnt[id[l]] == 1)
                break;
            if (id[l] != 0)
                cnt[id[l]]--;
            l++;
        }
        if (unique > maxUnique)
            maxUnique = unique;
    }
    l = 1;
    unique = 0;
    memset(cnt, 0, sizeof(cnt));
    int minLen = m + 1;

    if (maxUnique == 0)
    {
        cout << 0 << endl
             << 0 << endl;
        return 0;
    }

    for (int r = 1; r <= m; r++)
    {
        if (id[r] != 0)
        {
            if (cnt[id[r]] == 0)
                unique++;
            cnt[id[r]]++;
        }
        while (unique == maxUnique)
        {
            if (r - l + 1 < minLen)
                minLen = r - l + 1;

            if (id[l] != 0)
            {
                cnt[id[l]]--;
                if (cnt[id[l]] == 0)
                    unique--;
            }
            l++;
        }
    }
    cout << maxUnique << endl;
    cout << minLen << endl;
    return 0;
}
