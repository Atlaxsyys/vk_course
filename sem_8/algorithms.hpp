#pragma once

#include <vector>
#include <unordered_map>
#include <numeric>
#include <string>
#include <algorithm>

// 1
long long maxSubarraySum(const std::vector<int>& arr, int k)
{
    if (arr.size() < k) { return -1; }

    long long currentSum = 0;
    for (int i = 0; i < k; ++i)
    {
        currentSum += arr[i];
    }

    long long maxSum = currentSum;

    for (size_t i = k; i < arr.size(); ++i)
    {
        currentSum += arr[i] - arr[i - k];
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
        }
    }

    return maxSum;
}

// 2
int subarraySumEqualsK(const std::vector<int>& nums, int k)
{
    std::unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    
    int count = 0;
    int prefixSum = 0;

    for (int num : nums)
    {
        prefixSum += num;
        
        if (prefixCount.find(prefixSum - k) != prefixCount.end())
        {
            count += prefixCount[prefixSum - k];
        }
        
        prefixCount[prefixSum]++;
    }
    
    return count;
}

// 3
int findMaxLength(const std::vector<int>& nums)
{
    std::unordered_map<int, int> indexMap;
    indexMap[0] = -1;
    
    int maxLen = 0;
    int prefixSum = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        prefixSum += (nums[i] == 0 ? -1 : 1);

        if (indexMap.find(prefixSum) != indexMap.end())
        {
            maxLen = std::max(maxLen, i - indexMap[prefixSum]);
        }
        else
        {
            indexMap[prefixSum] = i;
        }
    }

    return maxLen;
}

// 4
int pivotIndex(const std::vector<int>& nums)
{
    long long totalSum = 0;
    for (int num : nums) totalSum += num;

    long long leftSum = 0;
    for (size_t i = 0; i < nums.size(); ++i)
    {
        if (leftSum == totalSum - leftSum - nums[i])
        {
            return static_cast<int>(i);
        }
        leftSum += nums[i];
    }

    return -1; // Pivot not found
}

// 5
bool canMakeValidWithDeletions(const std::string& s, int k)
{
    int balance = 0;
    int extraClosed = 0;

    for (char c : s)
    {
        if (c == '(')
        {
            balance++;
        }
        else
        {
            if (balance > 0)
            {
                balance--;
            }
            else
            {
                extraClosed++;
            }
        }
    }

    int totalNeededDeletions = balance + extraClosed;

    return totalNeededDeletions <= k;
}
