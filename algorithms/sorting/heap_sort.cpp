/**
 * @file heap_sort.cpp
 * @author Taylor Curran
 * @brief Implementation of heap sort
 * @version 0.1
 * @date 2020-08-06
 * 
 * @copyright Copyright (c) 2020 
 */

#include <vector>       // std::vector
#include <cassert>      // assert
#include <iostream>     // std::cout, std::endl
#include <functional>   // std::less

/**
 * @brief Swaps the element at index \p i down the (max) binary heap until the 
 * heap property is restored
 *
 * @tparam T heap type
 * @tparam Less comparison operator (see std::less)  
 * @param heap 
 * @param i index to start swap down; cannot be greater than length of \p heap
 * @param length length of the heap; cannot be less than length of \p heap
 */
template<class T, class Less = std::less<T>>
void swap_down(std::vector<T>& heap, size_t i, size_t length)
{
    size_t left = (2 * i) + 1;
    size_t right = (2 * i) + 2;
    size_t max_index = i;

    // Find index of largest value
    if(left < length && heap[left] > heap[max_index])
    {
        max_index = left;
    }

    if(right < length && heap[right] > heap[max_index])
    {
        max_index = right;
    }

    // Swap and recurse if necessary
    if(max_index != i)
    {
        T temp = heap[i];
        heap[i] = heap[max_index];
        heap[max_index] = temp;

        swap_down(heap, max_index, length);
    }
}

/**
 * @brief Sorts \p list in ascending order using heap sort
 * 
 * @tparam T list type
 * @tparam std::less<T> 
 * @param list 
 */
template<class T, class Less = std::less<T>>
void heap_sort(std::vector<T>& list)
{
    // Create heap ("heapify")
    for(int i = list.size() - 1; i >= 0; i--)
    {
        swap_down(list, i, list.size());
    }

    // Swap first (max) element with last element in heap and swap down
    for(int i = list.size() - 1; i > 0; i--)
    {
        // Swap front (max) element with last element in heap
        T temp = list[0];
        list[0] = list[i];
        list[i] = temp;

        // Restore heap property
        swap_down(list, 0, i);
    }
}

int main()
{
    std::cout << "\nBeginning tests..." << std::endl; 

    std::vector<int> v;                     // [] -> []
    heap_sort<int>(v);
    assert(v == std::vector<int>());

    v = {1};                                // [1] -> [1]
    heap_sort<int>(v);
    assert(v == std::vector<int>({1}));

    v = {2,1};                              // [2,1] -> [1,2]
    heap_sort<int>(v);
    assert(v == std::vector<int>({1,2}));

     v = {1,2,3};                           // [1,2,3] -> [1,2,3]
    heap_sort<int>(v);
    assert(v == std::vector<int>({1,2,3}));

     v = {1,3,2};                           // [1,3,2] -> [1,2,3]
    heap_sort<int>(v);
    assert(v == std::vector<int>({1,2,3}));

     v = {3,1,2};                            // [3,1,2] -> [1,2,3]
    heap_sort<int>(v);
    assert(v == std::vector<int>({1,2,3}));

     v = {1,5,4,2,3};                      // [1,5,4,2,3] -> [1,2,3,4,5]
    heap_sort<int>(v);
    assert(v == std::vector<int>({1,2,3,4,5}));
    
    std::cout << "All tests passed!" << std::endl;
    exit(0); 
} 

