/**
 * @file tst_RedBlackMap.cpp
 * @author yTaylor Curran
 * @brief Tests for RedBlackMap (based on tests for HashMap)
 * @version 0.1
 * @date 2020-06-15
 * 
 * @note See "tst_HashMap.cpp" for an example of how to 
 * override std::equal_to to get custom equality comparisons;
 * std::less can be overriden in the same manner to get
 * customer ordering in the map.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <string>
#include <cassert>
#include <iostream>
#include <functional>
#include "RedBlackMap.h"

int main()
{
    std::cout << "Beginning tests..." << std::endl;

    // Create hash map. Table is small enough to force resize.
    RedBlackMap<int, std::string> map;

    // Empty table
    assert(!map.size());

    // Add names by id number
    map.insert(29, "Taylor");
    map.insert(15, "Spencer");
    map.insert(44, "Barack");

    /** Note: recall that std::string.compare() returns zero
     * if the two strings are equal */
    std::string s = "";
    assert(map.size() == 3);
    assert(map.lookup(29, s));
    assert(!s.compare("Taylor"));
    assert(map.lookup(15, s));
    assert(!s.compare("Spencer"));
    assert(map.lookup(44, s));
    assert(!s.compare("Barack"));

    // Remove customers
    assert(map.remove(29));
    assert(map.remove(44));
    assert(!map.remove(44));
    assert(map.size() == 1);

    // Clear
    map.clear();
    assert(!map.size());
    
    // Add the Great One
    map.insert(99, "Wayne");
    assert(map.lookup(99, s));
    assert(!s.compare("Wayne"));
    
    std::cout << "All tests passed!" << std::endl;
    exit(0);
}