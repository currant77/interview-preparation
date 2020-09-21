/**
 * @file 16-10.cpp
 * @author Taylor Curran
 * @brief Solution to problem 16.10 from Cracking the Coding Interview
 * @version 0.1
 * @date <date>
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 */

/* Problem 16.10: Living People: Given a list of people with their birth and
death years, implement a method to compute the year with the most number of 
people alive. You may assume that all people were born between 1900 and 2000 
(inclusive). If a person was alive during any portion of that year, they should 
\be included in that year's count."*/

/* Approach: 

Create array of size 101, with each entry representing a year. Sort people by
birth year. Iterate across people list, storing cumulative births in array. 
Then sort people by death year, and subtract cumulative deaths. Then find max.

*/

#include <cassert> // assert
#include <iostream> // std::cout, std::endl
#include <vector> // std::vector

struct Person {
    int birth;
    int death;
};

typedef std::vector<Person> People;

int MaxLivingYear_naive(People people, int minYear, int maxYear)
{
    int maxAliveYear = minYear;
    int maxAliveCount = 0;

    int aliveCount;
    for (int i = minYear; i <= maxYear; i++) {
        aliveCount = 0;
        for (Person p : people) {
            if (p.birth <= i && p.death >= i)
                aliveCount++;
        }

        if (aliveCount > maxAliveCount) {
            maxAliveYear = i;
            maxAliveCount = aliveCount;
        }
    }

    return maxAliveYear;
}

int MaxLivingYear_optimized(People people, int minYear, int maxYear)
{
    if (maxYear < minYear)
        throw std::invalid_argument("minYear cannot be less than maxYear");

    int range = maxYear - minYear + 1;
    int delta[range] = { 0 };

    // Add deltas
    for (Person p : people) {

        // Add birth
        if (p.birth < minYear)
            delta[0]++;
        else if (p.birth <= maxYear)
            delta[p.birth - minYear]++;

        // Add death
        if (p.death < minYear)
            delta[0]--;
        else if (p.death < maxYear)
            delta[p.death - minYear + 1]--;
    }

    // Find max year
    int maxAliveYear = minYear;
    int maxAliveCount = 0;

    int alive = 0;

    for (int i = 0; i < maxYear - minYear + 1; i++) {
        alive += delta[i];

        if (alive > maxAliveCount) {
            maxAliveCount = alive;
            maxAliveYear = minYear + i;
        }
    }

    return maxAliveYear;
}
int main()
{
    std::cout << std::endl
              << "Beginning tests..." << std::endl;

    std::cout << "Testing naive implementation..." << std::endl;

    int minYear = 1900;
    int maxYear = 2000;

    Person gertrude = { 1920, 1965 };
    Person karen = { 1965, 2010 };
    Person timmy = { 1965, 1965 };
    Person john = { 1970, 2020 };

    // Empty people
    assert(MaxLivingYear_naive(People({}), minYear, maxYear) == 1900);

    // One person
    assert(MaxLivingYear_naive(People({ gertrude }), minYear, maxYear) == 1920);

    // Two people, no overlap
    assert(MaxLivingYear_naive(People({ gertrude, john }), minYear, maxYear) == 1920);

    // Two people, one year overlap
    assert(MaxLivingYear_naive(People({ gertrude, karen }), minYear, maxYear) == 1965);

    // Two people, multiple years overlap
    assert(MaxLivingYear_naive(People({ karen, john }), minYear, maxYear) == 1970);

    // Three people, one year overlap
    assert(MaxLivingYear_naive(People({ gertrude, karen, timmy }), minYear, maxYear) == 1965);

    // Four people, multiple overlaps
    assert(MaxLivingYear_naive(People({ gertrude, karen, timmy, john }), minYear, maxYear) == 1965);

    std::cout << "Testing optimized implementation..." << std::endl;

    // Empty people
    assert(MaxLivingYear_optimized(People({}), minYear, maxYear) == 1900);

    // One person
    assert(MaxLivingYear_optimized(People({ gertrude }), minYear, maxYear) == 1920);

    // Two people, no overlap
    assert(MaxLivingYear_optimized(People({ gertrude, john }), minYear, maxYear) == 1920);

    // Two people, one year overlap
    assert(MaxLivingYear_optimized(People({ gertrude, karen }), minYear, maxYear) == 1965);

    // Two people, multiple years overlap
    assert(MaxLivingYear_optimized(People({ karen, john }), minYear, maxYear) == 1970);

    // Three people, one year overlap
    assert(MaxLivingYear_optimized(People({ gertrude, karen, timmy }), minYear, maxYear) == 1965);

    // Four people, multiple overlaps
    assert(MaxLivingYear_optimized(People({ gertrude, karen, timmy, john }), minYear, maxYear) == 1965);

    std::cout << "All tests passed!" << std::endl;
    exit(0);
}