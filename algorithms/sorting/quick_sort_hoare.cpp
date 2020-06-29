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
 */
template<class T>
size_t partition(std::vector<T>& a, size_t start, size_t end)
{
    size_t mid = (end + start) / 2;
    T pivot = a[mid];
    
    size_t front = start;
    size_t back = end;
    
    while(true)
    {
        // Find next to swap
        while(a[front] < pivot)
            ++front;

        while(a[back] > pivot)
            --back;

        // Partitioning done
        if(front >= back)
            return back;
        
        // Swap values
        T temp = a[back];
        a[back] = a[front];
        a[front] = temp;
    }
}
/**
 * @brief Sorts the segment of the list between \p start
 * and \p end using quick sort (ascending)
 */
template<class T>
void quick_sort(std::vector<T>& a, size_t start, size_t end)
{
    size_t n = end - start + 1;

    // Base case
    if(n < 2) return;

    // Partition
    size_t pi = partition(a, start, end);

    // Sort each half
    quick_sort(a, start, pi - 1);
    quick_sort(a, pi + 1, end);
}

/**
 * @brief Sorts the given T vector (ascending).
 * Uses the Hoare partitioning approach.
 */
template<class T>
void quick_sort(std::vector<T>& a)
{
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

