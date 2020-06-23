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
 * @brief Sorts the given T vector (ascending)
 */
template<class T>
void quick_sort(std::vector<T>& a)
{
    // TODO
    return;
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

