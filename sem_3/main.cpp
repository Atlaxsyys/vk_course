#include <iostream>

#include "algorithms.hpp"
#include "Shellsort.hpp"

void print_array(const std::vector<int>& array)
{
    for (const auto& element : array) { std::cout << element << " "; }
    std::cout << std::endl;
}

int main()
{
	int a = 16;
	int b = 255; 

	// 1
	std::cout << "binarySearchSqrt(" << a << ") = " << binarySearchSqrt(a);
	std::cout << "binarySearchSqrt(" << b << ") = " << binarySearchSqrt(b);
    
	// 2
	std::cout << "copyTime(1, 5, 7) = " << copyTime(1, 5, 7) << '\n';
	std::cout << "copyTime(5, 1, 2) = " << copyTime(5, 1, 2) << '\n';
	// 3
	std::vector<int> animals = {8, 2, 3, 2};
	std::vector<int> food = {1, 4, 3, 8};

	std::cout << "feedAnimals: " << feedAnimals(animals, food) << '\n';

	// 4
	std::string a1 = "uio";
    std::string b1 = "oeiu";
    char result = extraLetters(a1, b1);
    std::cout << "result(charExtra): " << result << std::endl;

	// 5
	std::vector<int> data2 = {3, 2, 4};
    int target2 = 6;
    std::vector<int> result1 = twoSum(data2, target2);
	print_array(result1);


	Shellsort sorter;

    sorter.testSort();

    std::vector<std::string> input1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> result2 = group_anagrams(input1);

    print_result(result2);
	
	return 0;
}
