#include <vector>

// 1
inline std::pair<std::size_t, std::size_t> twosum(const std::vector<int>& array, int target)
{
    std::size_t left = 0;
    std::size_t right = array.size() - 1;

    while (left < right)
    {
        int sum = array[left] + array[right];

        if (sum == target) { return {left, right}; }

        if (sum < target) { left++; }
        else { right--; }
    }

    return {array.size(), array.size()};
}

// 2
inline void reverse_array(std::vector<int>& array)
{
    std::size_t left = 0;
    std::size_t right = array.size() - 1;

    while (left < right)
    {
        std::swap(array[left], array[right]);
        left++;
        right--;
    }
}

// 3
inline void reverse_array(std::vector<int>& array, std::size_t left, std::size_t right)
{
    while (left < right)
    {
        std::swap(array[left], array[right]);
        left++;
        right--;
    }
}

inline void rotate(std::vector<int>& array, std::size_t k)
{
    reverse_array(array, 0, array.size() - 1);
    reverse_array(array, 0, k % array.size() - 1);
    reverse_array(array, k % array.size(), array.size() - 1);
}

// 4
inline std::vector<int> megre_sorted_arrays(const std::vector<int> array_1, const std::vector<int> array_2)
{
    std::vector<int> result;

    std::size_t i = 0;
    std::size_t j = 0;

    while (i < array_1.size() && j < array_2.size())
    {
        if (array_1[i] <= array_2[j])
        {
            result.push_back(array_1[i]);
            i++;
        }

        else
        {
            result.push_back(array_2[j]);
            j++;
        }
    }

    while (i < array_1.size())
    {
        result.push_back(array_1[i]);
        i++;
    }

    while (j < array_2.size())
    {
        result.push_back(array_2[j]);
        j++;
    }

    return result;
}

// 5
inline void merge(std::vector<int> &array_1, int m, const std::vector<int> array_2, int n)
{
    int left_1 = m - 1;
    int right_1 = m + n -1;
    int right_2 = n - 1;

    while (right_2 >= 0)
    {
        if (left_1 >= 0 and array_1[left_1] > array_2[right_2])
        {
            array_1[right_1] = array_1[left_1];
            left_1--;
        }

        else
        {
            array_1[right_1] = array_2[right_2];
            right_2--;
        }

        right_1--;
    }


}

// 6
inline void sort_binary_array(std::vector<int>& array)
{
    std::size_t left = 0;
    std::size_t right = array.size() - 1;

    while (left < right)
    {
        if (array[left] == 0) { left++; }
        else if (array[right] == 1) { right--; }

        else
        {
            std::swap(array[left], array[right]);
            left++;
            right--;
        }
    }
}

// 7
inline void sortColors(std::vector<int>& array)
{
    std::size_t left = 0;
    std::size_t mid = 0;
    std::size_t right = array.size() - 1;

    while (mid <= right)
    {
        switch (array[mid])
        {
            case 0:
                std::swap(array[mid], array[left]);
                left++;
                mid++;
                break;
                
            case 1:
                mid++;
                break;
                
            case 2:
                std::swap(array[mid], array[right]);
                right--;
                break;
        }
    }
}

// 8
inline void even_first(std::vector<int>& array)
{
    std::size_t even_index = 0;

    for (std::size_t i = 0; i < array.size() - 1; i++)
    {
        if (array[i] % 2 == 0)
        {
            std::swap(array[even_index], array[i]);
            even_index++;
        }
    }
}

// 9
inline void move_zero_to_end (std::vector<int>& array)
{
    std::size_t pointer = 0;

    for (std::size_t i = 0; i < array.size(); i++)
    {
        if (array[i])
        {
            std::swap(array[i], array[pointer]);
            pointer++;
        }
    }
}