#include <iostream>
#include <vector>
#include <cassert>

#include "algorithms.hpp"

int main()
{
    // 1
    {
        std::cout << "Running test 1";
        std::vector<int> arr = {3, 8, 6, 9, 9, 8, 6, 11};
        assert(maxSubarraySum(arr, 3) == 26);
        assert(maxSubarraySum({1, 2}, 3) == -1);
        std::cout << "PASSED\n";
    }

    // 2
    {
        std::cout << "Running test 2";
        assert(subarraySumEqualsK({1, 1, 1}, 2) == 2);
        assert(subarraySumEqualsK({1, 2, 3}, 3) == 2);
        std::cout << "PASSED\n";
    }

    // 3
    {
        std::cout << "Running test 3";
        assert(findMaxLength({0, 1}) == 2);
        assert(findMaxLength({0, 1, 0}) == 2);
        assert(findMaxLength({0, 1, 0, 0, 1}) == 4);
        std::cout << "PASSED\n";
    }

    // 4
    {
        std::cout << "Running test 4";
        assert(pivotIndex({1, 7, 3, 6, 5, 6}) == 3);
        assert(pivotIndex({1, 2, 3}) == -1);
        assert(pivotIndex({2, 1, -1}) == 0);
        std::cout << "PASSED\n";
    }

    // 5
    {
        std::cout << "Running test 5";
        assert(canMakeValidWithDeletions("())", 1) == true);
        assert(canMakeValidWithDeletions("())", 0) == false);
        assert(canMakeValidWithDeletions(")(", 2) == true);
        assert(canMakeValidWithDeletions("(()", 1) == true);
        std::cout << "PASSED\n";
    }

    return 0;
}
