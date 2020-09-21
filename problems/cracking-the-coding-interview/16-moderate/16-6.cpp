/**
 * @file 16-6.cpp
 * @author Taylor Curran
 * @brief Solution to problem 16.6 from Cracking the Coding Interview
 * @version 0.1
 * @date <date>
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 */

/* Problem 16.6: "Smallest Difference: Given two array of integrs, compute the
pair of values (one value in each array) with the smallest (non-negative)
differebce. Return the difference. */

/* Approach: The naive implementation in O(n^2) - comparing every pair.*/

#include <algorithm> // std::sort
#include <cassert> // assert
#include <cmath> // std::abs
#include <iostream> // std::cout, std::endl;
#include <vector> // std:: vector

int smallestDifference_naive(std::vector<int> first, std::vector<int> second)
{
    if (first.empty() || second.empty())
        return -1;

    // Naive implementationS
    int difference = INT_MAX;
    for (auto fit = first.begin(); fit != first.end(); ++fit) {
        for (auto sit = second.begin(); sit != second.end(); ++sit) {
            if (abs(*fit - *sit) < difference)
                difference = abs(*fit - *sit);
        }
    }

    return difference;
}

int smallestDifference_optimized(std::vector<int> first, std::vector<int> second)
{

    if (first.empty() || second.empty())
        return -1;

    // Sort arrays
    std::sort(first.begin(), first.end());
    std::sort(second.begin(), second.end());

    // Find min difference
    int min = INT_MAX;
    auto fit = first.begin();
    auto sit = second.begin();

    while (fit != first.end() && sit != second.end()) {
        if (abs(*fit - *sit) < min)
            min = abs(*fit - *sit);

        // Advance smaller value iterator (shrinks difference)
        if (*fit < *sit)
            ++fit;
        else
            ++sit;
    }

    return min;
}

int main()
{
    std::cout << std::endl
              << "Beginning tests..." << std::endl;

    std::cout << "Testing naive imnplementation..." << std::endl;

    // Empty list
    assert(smallestDifference_naive(std::vector<int>({}), std::vector<int> { 3 }) == -1);

    // One value in each
    assert(smallestDifference_naive(std::vector<int>({ 1 }), std::vector<int> { 3 }) == 2);
    assert(smallestDifference_naive(std::vector<int>({ 1 }), std::vector<int> { 3 }) == 2);

    // One value in one list
    assert(smallestDifference_naive(std::vector<int>({ 1 }), std::vector<int> { 1, 2, 3 }) == 0);
    assert(smallestDifference_naive(std::vector<int>({ 1, 2, 3 }), std::vector<int> { 1 }) == 0);

    // More complicated
    assert(smallestDifference_naive(std::vector<int>({ 1, 2, 3 }), std::vector<int> { -5, 12 }) == 6);
    assert(smallestDifference_naive(std::vector<int>({ 1, 3, 15, 11, 2 }), std::vector<int> { 23, 127, 235, 19, 8 }) == 3);

    std::cout << "Testing optimized imnplementation..." << std::endl;

    // Empty list
    assert(smallestDifference_optimized(std::vector<int>({}), std::vector<int> { 3 }) == -1);

    // One value in each
    assert(smallestDifference_optimized(std::vector<int>({ 1 }), std::vector<int> { 3 }) == 2);
    assert(smallestDifference_optimized(std::vector<int>({ 1 }), std::vector<int> { 3 }) == 2);

    // One value in one list
    assert(smallestDifference_optimized(std::vector<int>({ 1 }), std::vector<int> { 1, 2, 3 }) == 0);
    assert(smallestDifference_optimized(std::vector<int>({ 1, 2, 3 }), std::vector<int> { 1 }) == 0);

    // More complicated
    assert(smallestDifference_optimized(std::vector<int>({ 1, 2, 3 }), std::vector<int> { -5, 12 }) == 6);
    assert(smallestDifference_optimized(std::vector<int>({ 1, 3, 15, 11, 2 }), std::vector<int> { 23, 127, 235, 19, 8 }) == 3);

    std::cout << "All tests passed!" << std::endl;
    exit(0);
}