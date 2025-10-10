#include <iostream>

#include "algorithms.hpp"

void print_array(const std::vector<int>& array)
{
    for (const auto& element : array) { std::cout << element << " "; }
    std::cout << std::endl;
}

int main()
{
    // 1
    std::vector<int> array_1 = {1, 2, 3, 5, 9};
    auto result = twosum(array_1, 11);
    std::cout << result.first << " " << result.second << std::endl;

    // 2
    std::vector<int> array_2 = {1, 2, 3, 4, 5};  
    reverse_array(array_2);
    print_array(array_2);

    // 3
    std::vector<int> array_3 = {1, 2, 3, 4, 5};  
    rotate(array_3, 3);
    print_array(array_3);

    // 4
    std::vector<int> array_4_1 = {1, 3, 5, 7};
    std::vector<int> array_4_2 = {2, 4, 6, 8};
    print_array(megre_sorted_arrays(array_4_1, array_4_2));

    // 5
    std::vector<int> array_5_1 = {3, 8, 10, 11, 0, 0, 0};
    std::vector<int> array_5_2 = {1, 7, 9};
    merge(array_5_1, 4, array_5_2, 3);
    print_array(array_5_1);

    // 6
    std::vector<int> array_6 = {0, 1, 1, 0, 1, 0, 1, 0};
    sort_binary_array(array_6);
    print_array(array_6);

    // 7
    std::vector<int> array_7 = {2, 0, 1, 0, 0, 1, 2};
    sortColors(array_7);
    print_array(array_7);

    // 8
    std::vector<int> array_8 = {3, 2, 4, 1, 11, 8, 9};
    even_first(array_8);
    print_array(array_8);

    // 9
    std::vector<int> array_9_1 = {0, 0, 1, 0, 3, 12};
    std::vector<int> array_9_2 = {0, 33, 57, 88, 60, 0, 0, 80, 99};
    std::vector<int> array_9_3 = {0, 0, 0, 18, 16, 0, 0, 77, 99};

    move_zero_to_end(array_9_1);
    move_zero_to_end(array_9_2);
    move_zero_to_end(array_9_3);

    print_array(array_9_1);
    print_array(array_9_2);
    print_array(array_9_3);
}