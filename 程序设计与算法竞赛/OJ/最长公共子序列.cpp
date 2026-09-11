/*18308 最长公共子序列长度

Description
给定两个字符串，请输出这两个字符串的最大公共子序列

输入格式
两行，一行一个字符串（不包括空格，Tab键）,长度不超过1000

输出格式
输出最大公共子序列的长度

输入样例
abbca
aba

输出样例
3
*/
#include <iostream>
#include <cstring>
using namespace std;
char a[1000];
char b[1000];
int maxLen[1000][1000];
int main()
{
    cin >> a >> b;

    int len1 = strlen(a);
    int len2 = strlen(b);
    int i, j;
    for (i = 0; i <= len1; i++)
        maxLen[i][0] = 0;
    for (j = 0; j <= len2; j++)
        maxLen[0][j] = 0;

    for (i = 1; i <= len1; i++)
    {
        for (j = 1; j <= len2; j++)
        {
            if (a[i - 1] == b[j - 1])
                maxLen[i][j] = maxLen[i - 1][j - 1] + 1;
            else
            {
                maxLen[i][j] = max(maxLen[i - 1][j], maxLen[i][j - 1]);
            }
        }
    }
    cout << maxLen[len1][len2] << endl;

    return 0;
}