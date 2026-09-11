#include "stdio.h"
#include "stdlib.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASLBLE -1
#define OVERFLOW -2
#define MAXSTRLEN 255                         // 用户可在255以内定义最大串长
typedef unsigned char SString[MAXSTRLEN + 1]; // 0号单元存放串的长度

void get_next(SString T, int next[])
{
    // 算法4.7
    // 求模式串T的next函数值并存入数组next
    // 请补全代码
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T[0])
    {
        if (j == 0 || T[i] == T[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

int Index_KMP(SString S, SString T, int pos)
{
    // 算法4.6
    // 利用模式串T的next函数求T在主串S中第pos个字符之后的位置
    // KMP算法。请补全代码
    int next[MAXSTRLEN];
    get_next(T, next);
    int i = pos, j = 1;
    while (i <= S[0] && j <= T[0])
    {
        if (j == 0 || S[i] == T[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if (j > T[0])
        return i - T[0];
    else
        return 0;
}

int main()
{
    SString T, S;
    int i, j, n;
    char ch;
    int pos;
    scanf("%d", &n); // 指定n对需进行模式匹配的字符串
    ch = getchar();
    for (j = 1; j <= n; j++)
    {
        ch = getchar();
        for (i = 1; i <= MAXSTRLEN && (ch != '\n'); i++) // 录入主串
        {
            S[i] = ch;
            ch = getchar();
        }
        S[0] = i - 1; // S[0]用于存储主串中字符个数
        ch = getchar();
        for (i = 1; i <= MAXSTRLEN && (ch != '\n'); i++) // 录入模式串
        {
            T[i] = ch;
            ch = getchar();
        }
        T[0] = i - 1; // T[0]用于存储模式串中字符个数
        pos = Index_KMP(S, T, 1);
        printf("%d\n", pos);
    }
    return 0;
}

/*输入格式
第一行：输入n，表示有n对字符串需要匹配
第二行：输入第1个主串
第三行：输入第1个模式串
第四行：输入第2个主串
第五行：输入第2个模式串
……
倒数二行：输入第n个主串
最后一行：输入第n个模式串


输出格式
第一至第n行：输出每相应模式串的匹配值


输入样例
4
oadhifgoarhglkdsa
oar
abcdefg
dec
algeojflas
ojf
jfaweiof
of


输出样例
8
0
5
7
*/