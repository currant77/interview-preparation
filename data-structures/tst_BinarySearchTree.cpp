/**
 * @file tst_BinarySearchTree.cpp
 * @author Taylor Curran
 * @brief Tests for BinarySearchTree
 * @version 0.1
 * @date 2020-06-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <cassert>
#include <iostream>
#include "BinarySearchTree.h"

int main()
{
    std::cout << "Beginning tests..." << std::endl;

    BinarySearchTree<int> bst;

    // Test empty tree
    assert(bst.find(0) ==  NULL);
    assert(!bst.remove(10));

    // Add one value
    assert(bst.insert(5));
    assert(*bst.find(5) == 5);
    assert(!bst.find(10));

    // Add multiple values
    assert(bst.insert(15));
    assert(bst.insert(3));
    assert(bst.insert(4));
    assert(bst.insert(2));
    assert(bst.insert(10));

    assert(*bst.find(5) == 5);
    assert(*bst.find(15) == 15);
    assert(*bst.find(3) == 3);
    assert(*bst.find(2) == 2);
    assert(*bst.find(10) == 10);
    assert(!bst.find(12));

    // Remove values
    assert(bst.remove(3));      // Node with two children
    assert(bst.remove(5));      // Root node
    assert(bst.remove(15));     // Node with left child
    assert(!bst.remove(15));

    assert(!bst.find(5));
    assert(!bst.find(15));
    assert(!bst.find(3));
    assert(*bst.find(2) == 2);
    assert(*bst.find(10) == 10);
    assert(!bst.find(12));

    // Clear
    bst.clear();
    assert(!bst.find(10));
    assert(!bst.remove(3));

    // Add value
    assert(bst.insert(1));
    assert(bst.insert(2));
    assert(bst.insert(3));

    assert(!bst.find(4));
    assert(*bst.find(3) == 3);
    assert(*bst.find(1) == 1);
    assert(*bst.find(2) == 2);

    std::cout << "All tests passed!" << std::endl;
    exit(0);
}