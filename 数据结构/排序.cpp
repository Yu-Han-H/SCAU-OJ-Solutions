#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;

void InsertSort(vector<int> &v)
{
    // 注意：v[0] 用作哨兵，有效元素从 v[1] 到 v[n]
    int n = v.size() - 1; // v.size() 实际为 n+1
    for (int i = 2; i <= n; i++)
    {
        if (v[i] < v[i - 1])
        {
            v[0] = v[i]; // 哨兵暂存待插入元素
            int j;
            for (j = i - 1; v[0] < v[j]; j--)
                v[j + 1] = v[j]; // 后移元素
            v[j + 1] = v[0];     // 插入正确位置
        }
        // 输出当前排序结果（从 v[1] 开始）
        for (int k = 1; k <= n; k++)
            cout << v[k] << " ";
        cout << endl;
    }
}

void BInsertSort(vector<int> &v)
{
    int n = v.size() - 1;
    for (int i = 2; i <= n; i++)
    {
        if (v[i] < v[i - 1])
        {
            v[0] = v[i];
            int low = 1, high = i - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (v[0] < v[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            for (int j = i - 1; j >= high + 1; j--)
                v[j + 1] = v[j];
            v[high + 1] = v[0];
        }
        for (int i = 1; i <= n; i++)
            cout << v[i] << " ";
        cout << endl;
    }
}

void ShellSort(vector<int> &v)
{
    int n = v.size() - 1;
    int d = n / 2; // 初始增量为元素数/2
    while (d > 0)
    {
        for (int i = d + 1; i <= n; i++)
        {
            v[0] = v[i];
            int j = 0;
            for (j = i - d; j > 0 && v[0] < v[j]; j -= d)
                v[j + d] = v[j];
            v[j + d] = v[0];
        }
        d /= 2;
        for (int i = 1; i <= n; i++)
            cout << v[i] << " ";
        cout << endl;
    }
}

void BubbleSort(vector<int> &v)
{
    int len = v.size(), flag = 1;
    for (int i = 0; i < len - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < len - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                flag = 1;
                swap(v[j], v[j + 1]);
            }
        }

        for (auto x : v)
            cout << x << " ";
        cout << endl;

        if (!flag)
            return;
    }
}

void QuickSort(vector<int> &v, int low, int high)
{
    if (low >= high)
        return;
    int i = low, j = high;
    int pivot = v[low];
    while (i < j)
    {
        while (i < j && v[j] >= pivot)
            j--;
        v[i] = v[j];
        while (i < j && v[i] <= pivot)
            i++;
        v[j] = v[i];
    }
    v[i] = pivot;
    for (auto x : v)
        cout << x << " ";
    cout << endl;
    QuickSort(v, low, i - 1);
    QuickSort(v, i + 1, high);
}

void SelectSort(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[k])
                k = j;
        }
        if (k != i)
        {
            swap(v[i], v[k]);
        }
        for (auto x : v)
            cout << x << " ";
        cout << endl;
    }
}

void HeapAdjust(vector<int> &v, int s, int m)
{
    int rc = v[s];
    for (int j = 2 * s; j <= m; j *= 2)
    {
        if (j < m && v[j] < v[j + 1])
            j++;
        if (rc >= v[j])
            break;
        v[s] = v[j];
        s = j;
    }
    v[s] = rc;
}

void CreatHeap(vector<int> &v)
{
    int n = v.size() - 1;
    for (int i = n / 2; i > 0; i--)
        HeapAdjust(v, i, n);
}

void HeapSort(vector<int> &v)
{
    CreatHeap(v);

    for (int i = 1; i <= v.size() - 1; i++)
        cout << v[i] << " ";
    cout << endl;

    for (int i = v.size() - 1; i > 1; i--)
    {
        swap(v[1], v[i]);
        HeapAdjust(v, 1, i - 1);
        for (int j = 1; j <= v.size() - 1; j++)
            cout << v[j] << " ";
        cout << endl;
    }
}

void Merge(vector<int> &v, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    // 合并两个有序子数组 [left, mid] 和 [mid+1, right]
    vector<int> temp(high - low + 1);
    while (i <= mid && j <= high)
    {
        if (v[i] <= v[j])
            temp[k++] = v[i++];
        else
            temp[k++] = v[j++];
    }
    while (i <= mid)
        temp[k++] = v[i++];
    while (j <= high)
        temp[k++] = v[j++];
    for (int a = 0; a < temp.size(); a++)
        v[low + a] = temp[a];
}

void MergeSort(vector<int> &v)
{
    int n = v.size();
    for (int step = 1; step < n; step <<= 1)
    {
        for (int left = 0; left < n - step; left += step * 2)
        {
            int mid = left + step - 1;
            int right = min(left + step * 2 - 1, n - 1);
            Merge(v, left, mid, right);
        }
        for (auto x : v)
            cout << x << " ";
        cout << endl;
    }
}

void distribute(const vector<int> &arr, vector<queue<int>> &buckets, int divisor)
{
    for (int num : arr)
    {
        int digit = (num / divisor) % 10; // 获取当前位的数字
        buckets[digit].push(num);
    }
}

void collect(vector<int> &arr, vector<queue<int>> &buckets)
{
    int index = 0;
    for (int i = 0; i < 10; ++i)
    {
        while (!buckets[i].empty())
        {
            arr[index++] = buckets[i].front();
            buckets[i].pop();
        }
    }
}

void radixSort(vector<int> &arr, int maxDigit)
{
    int n = arr.size();
    for (int digit = 1; digit <= maxDigit; ++digit)
    {
        int divisor = pow(10, digit - 1);  // 个位为1，十位为10，百位为100...
        vector<queue<int>> buckets(10);    // 10 个桶
        distribute(arr, buckets, divisor); // 分配
        collect(arr, buckets);             // 收集

        // 输出本趟排序结果（按最大宽度补前导零，保证与样例一致）
        for (int i = 0; i < n; ++i)
        {
            cout << setw(maxDigit) << setfill('0') << arr[i];
            if (i != n - 1)
                cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    int maxVal = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
        if (nums[i] > maxVal)
            maxVal = nums[i];
    }
    // 计算最大位数（若全为0则至少为1位）
    int maxDigit = 0;
    if (maxVal == 0)
        maxDigit = 1;
    else
    {
        while (maxVal > 0)
        {
            maxDigit++;
            maxVal /= 10;
        }
    }
    radixSort(nums, maxDigit);
    return 0;
}