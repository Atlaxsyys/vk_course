#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

class Shellsort {
private:
    void shell_sort (std::vector<int>& array, const std::vector<int>& gaps)
    {
        for (int gap : gaps)
        {
            for (int cur_pos = gap; cur_pos < array.size(); cur_pos++)
            {
                int temp = array[cur_pos];
                int m_gap = cur_pos;

                while (m_gap >= gap && array[m_gap - gap] > temp)
                {
                    array[m_gap] = array[m_gap - gap];
                    m_gap -= gap;
                }

                array[m_gap] = temp;
            }
        }
    }

public:
    // ~O(n^3/2)
    void shell_sort_Hibbard (std::vector<int>& array)
    {
        std::vector<int> gaps;
        int k = 1;

        while (true)
        {
            int gap = static_cast<int>(std::pow(2, k)) - 1;

            if (gap > array.size()) { break; }

            gaps.push_back(gap);
            
            k++;
        }

        if (gaps.empty()) { gaps.push_back(1); }

        std::reverse(gaps.begin(), gaps.end());
        
        printArray(gaps, "Hibbard_gaps: ");
        shell_sort(array, gaps);
    }

    void shell_sort_Pratt (std::vector<int>& array)
    {
        std::vector<int> gaps;
        int max_power = static_cast<int>(std::log(array.size()) / std::log(2)) + 1;

        for (int i = 0; i < max_power; i++)
        {
            for (int j = 0; j < max_power; j++)
            {
                int gap = static_cast<int>(std::pow(2, i)) * static_cast<int>(std::pow(3, j));

                if (gap <= array.size() && gap > 0)
                {
                    gaps.push_back(static_cast<int>(gap));
                }
            }
        }


        std::sort(gaps.begin(), gaps.end(), std::greater<int>());
        gaps.erase(std::unique(gaps.begin(), gaps.end()), gaps.end());
        printArray(gaps, "Pratt_gaps: ");
        shell_sort(array, gaps);
    }

    void shell_sort_Ciura (std::vector<int>& array)
    {
        std::vector<int> Ciura_gaps = {1, 4, 10, 23, 57, 132, 301, 701, 1750};
        std::vector<int> gaps;

        for (int gap : Ciura_gaps)
        {
            if (gap < array.size())
            {
                gaps.push_back(gap);
            }
        }

        
        std::sort(gaps.begin(), gaps.end(), std::greater<int>());
        
        printArray(gaps, "Ciura_gaps: ");
        shell_sort(array, gaps);
    }

    void printArray(const std::vector<int>& arr, const std::string& label)
    {
        std::cout << label;

        for (int num : arr)
        {
            std::cout << num << " ";
        }

        std::cout << std::endl;
    }

    void testSort()
    {
        std::vector<int> original = {8, 3, 7, 12, 18, 24, 10, 11, 9, 86, 72, 63};
        
        std::vector<int> array1 = original;
        shell_sort_Hibbard(array1);
        printArray(array1, "Hibbard: ");
        
        std::vector<int> array2 = original;
        shell_sort_Pratt(array2);
        printArray(array2, "Pratt: ");
        
        std::vector<int> array3 = original;
        shell_sort_Ciura(array3);
        printArray(array3, "Ciura: ");
    }


};