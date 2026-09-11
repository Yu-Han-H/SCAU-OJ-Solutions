/*给定一个整数数组，找到一个具有最大和的连续子数组，返回其最大和，请使用分治的解法完成填空。
（注：分治法并不是解这题最快的算法，更快的DP算法能达到O(N)的复杂度，请自行了解相关知识。）*/
#include <iostream>
#include <vector>
#include <algorithm>
// 查找跨越中点的最大子数组和
int maxCrossingSum(const std::vector<int> &arr, int low, int mid, int high)
{
    // 计算包含中点向左的最大和
    int leftSum = 0;
    int maxLeftSum = -999999;
    for (int i = mid; i >= low; --i)
    {
        leftSum += arr[i];
        if (leftSum > maxLeftSum)
        {
            maxLeftSum = leftSum;
        }
    }
    // 计算包含中点向右的最大和
    int rightSum = 0;
    int maxRightSum = -999999;
    for (int i = mid + 1; i <= high; ++i)
    {
        rightSum += arr[i];
        if (rightSum > maxRightSum)
        {
            maxRightSum = rightSum;
        }
    }
    return maxLeftSum + maxRightSum;
}
// 分治法求解最大子数组和
int maxSubArraySum(const std::vector<int> &arr, int low, int high)
{
    if (low == high)
    {
        return arr[low];
    }
    // 填空
    int mid = (low + high) / 2;
    int leftMax = maxSubArraySum(arr, low, mid);
    int rightMax = maxSubArraySum(arr, mid + 1, high);
    int crossMax = maxCrossingSum(arr, low, mid, high);
    //
    return std::max({leftMax, rightMax, crossMax});
}
int main()
{
    std::vector<int> arr;
    int n, data;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> data;
        arr.push_back(data);
    }
    int maxSum = maxSubArraySum(arr, 0, n - 1);
    std::cout << maxSum << std::endl;
    return 0;
}