#pragma once

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <iostream>

// 1
long long binarySearchSqrt (long long target)
{
    long long left = 0;
    long long right = target / 2;

    
    while (left <= right)
    {
        long long middle = left  + (right - left) / 2;

        if (middle > target / middle)
        {
            right = middle - 1;
            continue;
        }
        
        if (middle < target / middle)
        {
            left = middle + 1;
            continue;
        }

        return middle;
    }

    return right;

}

// 2
long long copyTime (long long n, long long x, long long y)
{
    long long left = 0;
    long long right = (n - 1) * std::max(x, y);

    while (left + 1 < right)
    {
        long long middle = left + (right - left) / 2;

        if (middle / x + middle / y < n - 1) { left = middle; }

        else { right = middle; }
    }

    return right + std::min(x, y);
}

// 2
long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

long long copyTimeAnalitycal (long long n, long long x, long long y)
{
    if (n == 1) return std::min(x, y);
    
    long long remaining = n - 1;
    
    long long cycle = lcm(x, y);
    
    long long copies_per_cycle = cycle / x + cycle / y;
    
    long long full_cycles = remaining / copies_per_cycle;
    
    long long leftover = remaining % copies_per_cycle;
    
    long long cycles_time = full_cycles * cycle;
    
    long long time_x = 0;
    long long time_y = 0;
    long long leftover_time = 0;
    
    for (int i = 0; i < leftover; i++)
    {
        if (time_x + x <= time_y + y)
        {
            time_x += x;
            leftover_time = std::max(leftover_time, time_x);
        }

        else
        {
            time_y += y;
            leftover_time = std::max(leftover_time, time_y);
        }
    }
    
    return std::min(x, y) + cycles_time + leftover_time;
}

// 3
int feedAnimals (std::vector<int> animals, std::vector<int> food)
{
    if (animals.empty() || food.empty()) { return 0; }
    
    std::sort(animals.begin(), animals.end());
    std::sort(food.begin(), food.end());
    
    int count = 0;

    for (int f : food)
    {
        if (f >= animals[count]) { count++; }

        if (count == animals.size()) { break; }
    }

    return count;
}

// 4
char extraLetters (const std::string a, const std::string b)
{
    std::unordered_map<char, int> map_a;

    for (char c : a) { map_a[c]++; }

    for (char c : b)
    {
        if (map_a.find(c) != map_a.end())
        {
            map_a[c]--;

            if (map_a[c] == 0) { map_a.erase(c); }
        }

        else
        {
            return c;
        }
    }

    return ' ';
}

// 5
std::vector<int> twoSum (std::vector<int>& data, int target)
{
    std::unordered_map<int, int> cache;

    for (int i = 0; i < data.size(); i++) { cache[data[i]] = i; }

    for (int i = 0; i < data.size(); i++)
    {
        int diff = target - data[i];

        if (cache.find(diff) != cache.end() && cache[diff] != i)
        {
            return {i, cache[diff]};
        }
    }

    return {};
}

// 6
std::vector<std::vector<std::string>> group_anagrams (std::vector<std::string>& strs)
{
    std::unordered_map<std::string, std::vector<std::string>> anagram_g;
    
    for (const std::string& str : strs)
    {
        std::string key = str;
        std::sort(key.begin(), key.end());
        anagram_g[key].push_back(str);
    }
    
    std::vector<std::vector<std::string>> result;

    for (auto& group : anagram_g)
    {
        result.push_back(group.second);
    }
    
    return result;
}

void print_result(const std::vector<std::vector<std::string>>& result)
{
    std::cout << "[";
    for (size_t i = 0; i < result.size(); ++i)
    {
        std::cout << "[";

        for (size_t j = 0; j < result[i].size(); ++j)
        {
            std::cout << "\"" << result[i][j] << "\"";
            
            if (j < result[i].size() - 1)
            {
                std::cout << ",";
            }
        }

        std::cout << "]";

        if (i < result.size() - 1)
        {
            std::cout << ",";
        }
    }

    std::cout << "]" << std::endl;
}

