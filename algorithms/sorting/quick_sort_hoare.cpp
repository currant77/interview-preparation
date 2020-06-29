/**
 * @file quick_sort_hoare.cpp
 * @author Taylor Curran
 * @brief Implementation of quick sort using the Hoare partitioning approach
 * @version 0.1
 * @date 2020-06-23
 * 
 * @copyright Copyright (c) 2020 
 */

#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

/**
 * @brief Partitions the list segment between start and
 * end. Returns partition index.
 * 
 * @note Partition index is such that all values to its left
 * are less than or equal to the partition index, while all 
 * values to the right are greater than or equal to. The 
 * partition value itself, however, can be at any index
 */
template<class T>
size_t partition(std::vector<T>& a, int left, int right)
{  
    T pivot = a[(left + right) / 2];
    
    while(left <= right)
    {
        while(a[left] < pivot)
            ++left;

        while(a[right] > pivot)
            --right;

        if(left <= right)
        {
            // Swap values
            T temp = a[left];
            a[left] = a[right];
            a[right] = temp;

            ++left;
            --right;
        }
    }

    return left;
}

/**
 * @brief Sorts the segment of the list between \p start
 * and \p end using quick sort (ascending)
 */
template<class T>
void quick_sort(std::vector<T>& a, int start, int end)
{
    int index = partition(a, start, end);

    if(start < index - 1)
        quick_sort(a, start, index - 1);

    if(index < end)
        quick_sort(a, index, end);
}

/**
 * @brief Sorts the given T vector (ascending).
 * Uses the Hoare partitioning approach.
 */
template<class T>
void quick_sort(std::vector<T>& a)
{
    if(!a.empty())
        quick_sort(a, 0, a.size() - 1);
}

int main()
{
    std::cout << "Beginning tests..." << std::endl; 

    std::vector<int> v;                     // [] -> []
    quick_sort(v);
    assert(v == std::vector<int>());

    v = {1};                                // [1] -> [1]
    quick_sort(v);
    assert(v == std::vector<int>({1}));

    v = {2,1};                              // [2,1] -> [1,2]
    quick_sort(v);
    assert(v == std::vector<int>({1,2}));

     v = {1,2,3};                           // [1,2,3] -> [1,2,3]
    quick_sort(v);
    assert(v == std::vector<int>({1,2,3}));

     v = {1,3,2};                           // [1,3,2] -> [1,2,3]
    quick_sort(v);
    assert(v == std::vector<int>({1,2,3}));

     v = {3,1,2};                            // [3,1,2] -> [1,2,3]
    quick_sort(v);
    assert(v == std::vector<int>({1,2,3}));

     v = {1,5,4,2,3};                      // [1,5,4,2,3] -> [1,2,3,4,5]
    quick_sort(v);
    assert(v == std::vector<int>({1,2,3,4,5}));
    
    std::cout << "All tests passed!" << std::endl;
    exit(0); 
} 

