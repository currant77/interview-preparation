/**
 * @file merge_sort.cpp
 * @author Taylor Curran
 * @brief Implementation of merge sort for arrays
 * @version 0.1
 * @date 2020-06-22
 * 
 * @note Uses std::less to allow any ordering
 * 
 * @copyright Copyright (c) 2020 
 */

#include <vector>
#include <cassert>
#include <iostream>

/**
 * @brief Merges the sublists between left and mid and
 * mid + 1 and right (inclusive). Helper to merge_sort
 * 
 * @note Merges lists in place by accumulating values
 * at the left of the range
 */
template<class T>
void merge(std::vector<T>& a, size_t left, size_t mid, size_t right)
{
    // Proceed through both lists at the same time
    while(left <= mid && mid < right)
    {
        T temp;

        if(a[left] <= a[right])
            left++;

        else
        {
            temp = a[mid + 1];
            
            // Shift left list over
            for(size_t i = mid + 1; i > left; --i)
                a[i] = a[i - 1];
            
            a[left] = temp;
            ++left;
            ++mid;
        }
    }

    // Remainder is automatically in order
}

/**
 * @brief Sorts the sublist between \p left and \p right 
 * indices. Helper function to merge_sort
 */
template<class T>
void merge_sort(std::vector<T>& a, size_t left, size_t right)
{
    // Base Case
    if(right - left < 1)
        return;

    // Split list in half
    size_t mid = left + (right - left) / 2;

    // Sort each half
    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);

    // Merged sorted halves
    merge(a, left, mid, right);
}

/**
 * @brief Sorts the given T array in place using the ordering provided
 * by the comparison object L 
 */
template<class T>
void merge_sort(std::vector<T>& a)
{
    if(a.empty()) 
        return;
    
    merge_sort(a, 0, a.size() - 1);  
}

int main()
{
    std::cout << "Beginning tests..." << std::endl; 

    std::vector<int> v;                     // [] -> []
    merge_sort(v);
    assert(v == std::vector<int>());

    v = {1};                                // [1] -> [1]
    merge_sort(v);
    assert(v == std::vector<int>({1}));

    v = {2,1};                              // [2,1] -> [1,2]
    merge_sort(v);
    assert(v == std::vector<int>({1,2}));

     v = {1,2,3};                           // [1,2,3] -> [1,2,3]
    merge_sort(v);
    assert(v == std::vector<int>({1,2,3}));

     v = {1,3,2};                           // [1,3,2] -> [1,2,3]
    merge_sort(v);
    assert(v == std::vector<int>({1,2,3}));

     v = {3,1,2};                            // [3,1,2] -> [1,2,3]
    merge_sort(v);
    assert(v == std::vector<int>({1,2,3}));

     v = {1,5,4,2,3};                      // [1,5,4,2,3] -> [1,2,3,4,5]
    merge_sort(v);
    assert(v == std::vector<int>({1,2,3,4,5}));
    
    std::cout << "All tests passed!" << std::endl;
    exit(0); 
} 

