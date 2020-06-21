/**
 * @file tst_Tree.cpp
 * @author Taylor Curran
 * @brief Tests for Tree
 * @version 0.1
 * @date 2020-06-20
 * 
 * @note Tests are based on the tree structure found 
 * here: 
 *                  A
 *         B        C        D
 *       E   F      G      H   I
 *                J   K
 * 
 * Breadth-first order: A B C D E F G H I J K
 * Depth-first order: A B E F C G J K D H I
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <string>
#include <cassert>
#include <iostream>
#include <exception>
#include "Tree.h"

int main()
{
    std::cout << "Beginning tests..." << std::endl; 

    Tree<std::string> t;

    // Empty tree
    assert(t.empty());
    assert(!t.size());
    assert(t.dfs_begin() == t.dfs_end());

    // Insert root using insert_child
    auto dfs_it = t.dfs_begin();
    dfs_it = t.insert_child(dfs_it, "A");       // it -> "A"
    assert((*dfs_it).compare("A"));

    // Insert children
    dfs_it = t.insert_child(dfs_it, "B");       // it -> "B"
    dfs_it = t.insert_child(dfs_it, "E");       // it -> "E"
    dfs_it = t.insert_after(dfs_it, "F");       // it -> "F"

    --dfs_it;                                   // it -> "E"
    --dfs_it;                                   // it -> "B"

    dfs_it = t.insert_after(dfs_it, "D");       // it -> "D"
    dfs_it = t.insert_child(dfs_it, "I");       // it -> "I"
    dfs_it = t.insert_before(dfs_it, "H");      // it -> "H"

    --dfs_it;                                   // it -> "D"
    --dfs_it;                                   // it -> "B"

    dfs_it = t.insert_after(dfs_it, "C");       // it -> "C"
    dfs_it = t.insert_child(dfs_it, "G");       // it -> "G"
    dfs_it = t.insert_child(dfs_it, "J");       // it -> "J"
    dfs_it = t.insert_after(dfs_it, "K");       // it -> "G"

    // Depth-first order
    dfs_it = t.dfs_begin();                     // it -> "A"
    assert((*dfs_it++).compare("A"));           // it -> "B"
    assert((*dfs_it++).compare("B"));           // it -> "E"
    assert((*dfs_it++).compare("E"));           // it -> "F"
    assert((*dfs_it++).compare("F"));           // it -> "C"
    assert((*dfs_it++).compare("C"));           // it -> "G"
    assert((*dfs_it--).compare("G"));           // it -> "C"
    assert((*dfs_it--).compare("C"));           // it -> "F"
    assert((*dfs_it++).compare("C"));           // it -> "G"
    assert((*dfs_it++).compare("G"));           // it -> "J"
    assert((*dfs_it++).compare("J"));           // it -> "K"
    assert((*dfs_it++).compare("K"));           // it -> "D"
    assert((*dfs_it++).compare("D"));           // it -> "H"
    assert((*dfs_it++).compare("H"));           // it -> "I"
    assert((*dfs_it++).compare("I"));           // it -> dfs_end()
    assert((dfs_it--) == t.dfs_end());          // it -> "I"
    assert((*dfs_it).compare("I"));

    // Breadth-first order
    // TODO

    // Remove using iterator
    // TODO

    // Clear
    t.clear();
    t.clear();
    assert(t.empty());
    assert(!t.size());
    assert(t.dfs_begin() == t.dfs_end());

    // Test errors
    // TODO

    std::cout << "All tests passed!" << std::endl;
    exit(0);
}