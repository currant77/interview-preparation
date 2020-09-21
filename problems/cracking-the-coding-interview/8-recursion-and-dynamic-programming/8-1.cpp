/**
 * @file 8-1.cpp
 * @author Taylor Curran
 * @brief Solution to problem 8.1 from Cracking the Coding Interview
 * @version 0.1
 * @date August 29, 2020
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 */

/* Problem 8.1: "Triple Step. A child is running up a staircase with n steps and
can hop either 1 step, 2 steps, or 3 steps at a time. Implement a method to
count how many possible ways the child can run up the stairs." */

/* Approach: 

The problem is recursive. The hop to the last step will be a hop
of either 1, 2, or 3 steps. Therefore, the number of ways to hop to the nth step
is equal to the sum of the number of ways to hop to the (n-1)th, (n-2)th, and
(n-3)th steps. However, to avoid duplication, we should use dynamic programming 
store the earlier results.*/

#include <cassert> // assert
#include <iostream> // std::cout, std::endl;

unsigned helper(unsigned n, unsigned* memo)
{
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else if (n == 3)
        return 4;

    if (memo[n - 1] == 0)
        memo[n - 1] = helper(n - 3, memo) + helper(n - 2, memo) + helper(n - 1, memo);

    return memo[n - 1];
}

unsigned triple_step(unsigned n)
{
    if (n == 0)
        return 0;

    unsigned* memo = new unsigned[n] { 0 };
    unsigned steps = helper(n, memo);
    delete memo;
    return steps;
}

int main()
{
    std::cout << "\nBeginning tests..." << std::endl;

    assert(triple_step(0) == 0);
    assert(triple_step(1) == 1);
    assert(triple_step(2) == 2);
    assert(triple_step(3) == 4);
    assert(triple_step(4) == 7);

    std::cout << "All tests passed!" << std::endl;
    exit(0);
}