#include <iostream>
using namespace std;

int n;
int a[1001];
int temp[1001];

void merge_sort(int *A, int x, int y, int *T)
{
    if (y - x > 1)
    { // 填空
        int mid = x + (y - x) / 2;
        merge_sort(A, x, mid, T);
        merge_sort(A, mid, y, T);
        //
        int p = x, q = mid, i = x;
        while (p < mid || q < y)
        {
            if (q >= y || (p < mid && A[p] <= A[q]))
                T[i++] = A[p++];
            else
                T[i++] = A[q++];
        }
        for (i = x; i < y; i++)
            A[i] = T[i];
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    merge_sort(a, 0, n, temp);
    for (int i = 0; i < n; i++)
        cout << a[i] << endl;
}