#pragma once

#include <vector>
#include <climits>
#include <string>

// 1.1 ~ O(n^2)
long long b_sequence (int n)
{
    if (n == 1) { return 2; }
    if (n == 2) { return 3; }
    return b_sequence(n - 1) + b_sequence(n - 2);
}

// 1.2
long long solveDP(int n)
{
    std::vector<long long> dp = {1, 2}; 

    if (n < 2) return dp[n];

    for (int i = 2; i <= n; ++i)
    {
        long long next_val = dp[i - 1] + dp[i - 2];
        dp.push_back(next_val);
    }

    return dp[n];
}

// 2
long long count_sequence (int n)
{
    if (n == 0) { return 1; }
    if (n == 1) { return 2; }
    if (n == 2) { return 4; }

    std::vector<long long> dp = {1, 2, 4};

    for (int i = 3; i <= n; ++i)
    {
        long long next_val = dp[i - 1] + dp[i - 2] + dp[i - 3];
        dp.push_back(next_val);
    }

    return dp[n];
}

// 3
int findLISDP(std::vector<int>& nums)
{
    if (nums.empty()) { return 0; }
    
    int n = nums.size();
    std::vector<int> dp(n, 1);
    int maxLength = 1;

    for (int i = 1; i < n; ++i)
    {
        if (nums[i] > nums[i - 1])
        {
            dp[i] = dp[i - 1] + 1;
        }
        
        if (dp[i] > maxLength)
        {
            maxLength = dp[i];
        }
    }

    return maxLength;
}

// 4.1
int getPascalValue (int row, int col)
{
    if (col == 0 || col == row)
    {
        return 1;
    }

    return getPascalValue(row - 1, col - 1) + getPascalValue(row - 1, col);
}

std::vector<std::vector<int>> generatePascalTriangleRecursive (int numRows)
{
    std::vector<std::vector<int>> triangle;
    
    for (int i = 0; i < numRows; ++i)
    {
        std::vector<int> row;
        for (int j = 0; j <= i; ++j)
        {
            row.push_back(getPascalValue(i, j));
        }
        triangle.push_back(row);
    }
    
    return triangle;
}

// 4.2
std::vector<std::vector<int>> generatePascalTriangleIterative(int numRows)
{
    std::vector<std::vector<int>> triangle;
    
    if (numRows <= 0) return triangle;

    for (int i = 0; i < numRows; ++i)
    {

        std::vector<int> row(i + 1, 1);
        
        for (int j = 1; j < i; ++j)
        {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        
        triangle.push_back(row);
    }
    
    return triangle;
}

// 5
int maxProfit (const std::vector<int>& prices)
{
    if (prices.size() < 2) { return 0; }

    int max_profit = 0;

    int min_price = prices[0];

    for (size_t i = 1; i < prices.size(); ++i)
    {
        max_profit = std::max(max_profit, prices[i] - min_price);
        min_price = std::min(min_price, prices[i]);
    }

    return max_profit;
}

// 6.1 
std::vector<int> memo;

int coinChangeRecursive(const std::vector<int>& coins, int amount)
{
    if (amount == 0) return 0;
    if (amount < 0) return -1;
    
    if (memo[amount] != -2) { return memo[amount]; }

    int minCoins = INT_MAX;

    for (int coin : coins)
    {
        int res = coinChangeRecursive(coins, amount - coin);
        
        if (res >= 0 && res < minCoins)
        {
            minCoins = res + 1;
        }
    }
    memo[amount] = (minCoins == INT_MAX) ? -1 : minCoins;
    return memo[amount];
}

int coinChange(std::vector<int>& coins, int amount)
{
    memo.assign(amount + 1, -2);
    return coinChangeRecursive(coins, amount);
}

// 6.2
int coinChangeIterative(std::vector<int>& coins, int amount)
{
    std::vector<int> dp(amount + 1, amount + 1);

    dp[0] = 0;

    for (int i = 1; i <= amount; ++i)
    {
        for (int coin : coins)
        {
            if (coin <= i)
            {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    if (dp[amount] > amount)
    {
        return -1;
    }

    return dp[amount];
}

// 7.1
std::string longestPalindrome(std::string s)
{
    if (s.empty()) { return ""; }

    int start = 0;
    int end = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        int l1 = i, r1 = i;
        while (l1 >= 0 && r1 < s.length() && s[l1] == s[r1])
        {
            if ((r1 - l1) > (end - start))
            {
                start = l1;
                end = r1;
            }
            l1--;
            r1++;
        }

        int l2 = i, r2 = i + 1;
        while (l2 >= 0 && r2 < s.length() && s[l2] == s[r2])
        {
            if ((r2 - l2) > (end - start))
            {
                start = l2;
                end = r2;
            }
            l2--;
            r2++;
        }
    }

    return s.substr(start, end - start + 1);
}

// 7.2
std::string longestPalindromeDP(std::string s)
{
    int n = s.length();
    if (n == 0) { return ""; }

    std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));

    int maxLen = 1;
    int start = 0;

    for (int i = 0; i < n; ++i)
    {
        dp[i][i] = true;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] == s[i+1])
        {
            dp[i][i+1] = true;
            maxLen = 2;
            start = i;
        }
    }

    for (int len = 3; len <= n; ++len)
    {
        for (int i = 0; i < n - len + 1; ++i)
        {
            int j = i + len - 1;

            if (s[i] == s[j] && dp[i+1][j-1])
            {
                dp[i][j] = true;
                if (len > maxLen)
                {
                    maxLen = len;
                    start = i;
                }
            }
        }
    }

    return s.substr(start, maxLen);
}