/**
 * @file cci_10-8.cpp
 * @author Taylor Curran
 * @brief Solution to problem 10.8 from Cracking the Coding Interview
 * @version 0.1
 * @date 2020-06-30
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/* Problem 10.8: Find Duplicates: You have an array with all numbers 
from 1 to N, where N is at most 32,000. The array may have duplicate
entries and you do not know what N is. With only 4 kilobytes of 
memory available, how would you print all duplicate elements in the array? */

/* Approach:

We have 4 kilobytes = 4 * 1000 * 8 = 32,000 bits available. 
We can solve the problem using a 'bit vector' (an array of bits) that is 
of length 32,000. 

(1) Iterate over the array once to find N
(2) Create a bit vector of size N and set all the values to zero
(3) Iterate over array. At each value, query the corresponding 
bit. If it is zero, set it to one; it if is one, it is a duplicate. 

Note 1: TODO - implement a bit vector class

Note 2: Solution in Cracking the Coding Interview does not search over
the array to find N first - it simly creates a bit vector of size 32,000.
This approach is faster (although asymptotically the same) but more
memory intensive in the case where N << 32,000. */

#include <vector>
#include <iostream> // std::cout, std::endl

void print_duplicates(unsigned* array, size_t size)
{
    // Find N - O(n)
    unsigned N = 1;
    for(auto it = array; it != array + size; ++it)
        if(*it > N)
            N = *it;

    // Create bit vector - max 4kB memory
    std::vector<bool> bits(N, true);

    std::cout << "[";

    // Print duplicates - O(n)
    bool printed = false;
    for(auto it = array; it != array + size; ++it)
    {    
        if(bits[*it - 1])
            bits[*it - 1] = false;
        else
        {
            std::cout << (printed ? "," : "") << *it;
            printed = true;
        }
            
    }

    std::cout << "]" << std::endl;
}

int main()
{
    std::cout << "Beginning tests..." << std::endl; 

    // N = 12, Duplicates = [1,5,7], size = 15
    unsigned one[] = {1,3,7,6,5,4,7,5,12,11,10,9,2,8,1};
    print_duplicates(one, 15);

    // N = 5, Duplicates = [], size = 5
    unsigned two[] = {5,3,4,2,1};
    print_duplicates(two, 5);

    // N = 1, Duplicates = [1,1,1], size = 4
    unsigned three[] = {1,1,1,1};
    print_duplicates(three, 4);

    // N = 2, Duplicates = [2,1], size = 4
    unsigned four[] = {2,1,1,2};
    print_duplicates(four, 4);

    std::cout << "All tests passed!" << std::endl;
    exit(0); 
}