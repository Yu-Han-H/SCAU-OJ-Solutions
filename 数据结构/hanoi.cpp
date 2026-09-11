#include <iostream>
using namespace std;

// 汉诺塔标准递归：n个盘子，从ori源 → tar目标，temp辅助
void hanoi(int n, char ori, char temp, char tar)
{
    if (n == 1)
    {
        cout << ori << "->" << n << "->" << tar << endl;
        return;
    }
    // 1. 把n-1个 从源 → 辅助
    hanoi(n - 1, ori, tar, temp);
    // 2. 把第n个 从源 → 目标
    cout << ori << "->" << n << "->" << tar << endl;
    // 3. 把n-1个 从辅助 → 目标
    hanoi(n - 1, temp, ori, tar);
}

int main()
{
    int n;
    char a, b, c;
    // 输入：盘子数 + 源柱子 + 目标柱子 + 辅助柱子
    cin >> n >> a >> b >> c;
    // 调用：n个盘子从a移到b，c辅助
    hanoi(n, a, c, b);
    return 0;
}