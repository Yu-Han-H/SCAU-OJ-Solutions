#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

typedef struct Bi
{
    int data;
    struct Bi *lchild, *rchild;
} BNode, *BTree;

void InsertTree(BTree &T, int val)
{
    if (T == nullptr)
    {
        T = new BNode;
        T->data = val;
        T->lchild = nullptr;
        T->rchild = nullptr;
        return;
    }
    if (val < T->data)
        InsertTree(T->lchild, val);
    else
        InsertTree(T->rchild, val);
}

void PreorderTraverse(BTree T)
{
    if (T != nullptr)
    {
        cout << T->data << " ";
        PreorderTraverse(T->lchild);
        PreorderTraverse(T->rchild);
    }
}

void InorderTraverse(BTree T)
{
    if (T != nullptr)
    {
        InorderTraverse(T->lchild);
        cout << T->data << " ";
        InorderTraverse(T->rchild);
    }
}

void PostorderTraverse(BTree T)
{
    if (T != nullptr)
    {
        PostorderTraverse(T->lchild);
        PostorderTraverse(T->rchild);
        cout << T->data << " ";
    }
}

bool SearchBtree(BTree T, int tar)
{
    if (T == nullptr)
        return false;
    if (tar == T->data)
    {
        cout << "1" << endl;
        return true;
    }
    else if (tar < T->data)
        return SearchBtree(T->lchild, tar);
    else
        return SearchBtree(T->rchild, tar);
}

void Non_InorderTraverse(BTree T)
{
    stack<BTree> s;
    BTree t = T;
    while (t || !s.empty())
    {
        while (t)
        {
            s.push(t);
            t = t->lchild;
        }
        t = s.top();
        s.pop();
        cout << t->data << " ";
        t = t->rchild;
    }
}

void LevelTraverse(BTree T)
{
    if (T == nullptr)
        return;
    queue<BTree> q;
    q.push(T);
    while (!q.empty())
    {
        BTree p = q.front();
        q.pop();
        cout << p->data << " ";
        if (p->lchild)
            q.push(p->lchild);
        if (p->rchild)
            q.push(p->rchild);
    }
}

void SwapTree(BTree T)
{
    if (T == nullptr)
        return;
    swap(T->lchild, T->rchild);
    SwapTree(T->lchild);
    SwapTree(T->rchild);
}

int Depth(BTree T)
{
    if (T == nullptr)
        return 0;
    return max(Depth(T->lchild), Depth(T->rchild)) + 1;
}

int LeafCount(BTree T)
{
    if (T == nullptr)
        return 0;
    if (T->lchild == nullptr && T->rchild == nullptr)
        return 1;
    return LeafCount(T->lchild) + LeafCount(T->rchild);
}

int main()
{
    BTree T = nullptr;
    int n;
    cin >> n;
    while (n--)
    {
        int val;
        cin >> val; 
        InsertTree(T, val);
    }

    PreorderTraverse(T);
    cout << endl;
    InorderTraverse(T);
    cout << endl;
    PostorderTraverse(T);
    cout << endl;

    int tar1, tar2;
    cin >> tar1;
    if (!SearchBtree(T, tar1))
        cout << "0" << endl;
    cin >> tar2;
    if (!SearchBtree(T, tar2))
        cout << "0" << endl;

    // 插入新结点
    int insVal;
    cin >> insVal;
    InsertTree(T, insVal);

    // 插入后的先、中、后序遍历
    PreorderTraverse(T);
    cout << endl;
    InorderTraverse(T);
    cout << endl;
    PostorderTraverse(T);
    cout << endl;

    // 中序遍历非递归
    Non_InorderTraverse(T);
    cout << endl;

    // 层次遍历
    LevelTraverse(T);
    cout << endl;

    // 第一次交换左右子树
    SwapTree(T);
    PreorderTraverse(T);
    cout << endl;
    InorderTraverse(T);
    cout << endl;
    PostorderTraverse(T);
    cout << endl;

    // 第二次交换左右子树（恢复原状）
    SwapTree(T);
    PreorderTraverse(T);
    cout << endl;
    InorderTraverse(T);
    cout << endl;
    PostorderTraverse(T);
    cout << endl;

    // 深度和叶子结点数
    cout << Depth(T) << endl;
    cout << LeafCount(T) << endl;

    return 0;
}