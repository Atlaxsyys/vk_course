#include <iostream>
#include <vector>
#include <string>
#include "algorithms.hpp"

void printVector(const std::vector<int>& v)
{
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << (i < v.size() - 1 ? ", " : "");
    }
    std::cout << "]" << std::endl;
}

int main()
{
    // 1
    std::cout << "--- 1 ---" << std::endl;
    std::cout << "Recursive (N=3): " << b_sequence(3) << std::endl;
    std::cout << "DP (N=3): " << solveDP(3) << std::endl;

    // 2
    std::cout << "\n--- 2 ---" << std::endl;
    std::cout << "Count (N=3): " << count_sequence(3) << std::endl;

    // 3
    std::cout << "\n--- 3 ---" << std::endl;
    std::vector<int> nums = {1, 3, 5, 4, 7};
    std::cout << "Nums: "; printVector(nums);
    std::cout << "Length: " << findLISDP(nums) << std::endl;

    // 4
    std::cout << "\n--- 4 ---" << std::endl;
    auto triangle = generatePascalTriangleIterative(4);
    for (const auto& row : triangle)
    {
        printVector(row);
    }

    // 5
    std::cout << "\n--- 5 ---" << std::endl;
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    std::cout << "Prices: "; printVector(prices);
    std::cout << "Max Profit: " << maxProfit(prices) << std::endl;

    // 6
    std::cout << "\n--- 6 ---" << std::endl;
    std::vector<int> coins = {1, 2, 5};
    int amount = 11;
    std::cout << "Min coins (Iterative): " << coinChangeIterative(coins, amount) << std::endl;

    // 7
    std::cout << "\n--- 7 ---" << std::endl;
    std::string s = "babad";
    std::cout << "String: " << s << std::endl;
    std::cout << "Result (Center expansion): " << longestPalindrome(s) << std::endl;
    std::cout << "Result (DP): " << longestPalindromeDP(s) << std::endl;

    return 0;
}
