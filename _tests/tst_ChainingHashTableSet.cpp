/**
 * @file tst_ISet.cpp
 * @author Taylor Curran
 * @brief Tests for ChainingHashTableSet
 * @version 0.1
 * @date 2020-08-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <cassert> // assert
#include <iostream> // std::cout, std::endl

#include "../_data-structures/hash-table/ChainingHashTableSet.h"
#include "../_data-structures/hash-table/HashFunctionExamples.h"

void tst_int(ISet<int>* set)
{
    // Empty table
    assert(!set->size());

    // Add first three values
    set->insert(0);
    set->insert(1);
    set->insert(2);

    // Try to re-insert values
    set->insert(0);
    set->insert(2);

    assert(set->size() == 3);
    assert(set->contains(0));
    assert(set->contains(2));
    assert(!set->contains(3));

    // Remove first two values
    set->remove(1);
    set->remove(0);

    // Try to re-remove values
    set->remove(0);
    set->remove(1);

    assert(set->size() == 1);
    assert(set->contains(2));
    assert(!set->contains(1));

    // Clear set
    set->clear();
    assert(!set->size());
    assert(!set->contains(2));

    // Insert last value
    set->insert(3);
    assert(set->contains(3));
    assert(set->size() == 1);
}

void tst_string(ISet<std::string>* set)
{
    std::string a = "A";
    std::string a_eq = "A";
    std::string b = "B";
    std::string c = "C";
    std::string c_eq = "C";
    std::string d = "D";
    std::string d_eq = "D";

    // Empty table
    assert(!set->size());

    // Add first three values
    set->insert(a);
    set->insert(b);
    set->insert(c);

    // Try to re-insert values
    set->insert(a);
    set->insert(a_eq);
    set->insert(c);
    set->insert(c_eq);

    assert(set->size() == 3);
    assert(set->contains(a_eq));
    assert(set->contains(b));
    assert(!set->contains(d));

    // Remove first two values
    set->remove(b);
    set->remove(a_eq);

    // Try to re-remove values
    set->remove(a);
    set->remove(b);

    assert(set->size() == 1);
    assert(set->contains(c_eq));
    assert(!set->contains(b));

    // Clear set
    set->clear();
    assert(!set->size());
    assert(!set->contains(a));

    // Insert last value
    set->insert(d_eq);
    assert(set->contains(d));
    assert(set->size() == 1);
}

int main()
{
    std::cout << "\nBeginning tests..." << std::endl;

    ISet<int>* int_set = new ChainingHashTableSet<int>();
    tst_int(int_set);
    delete int_set;

    ISet<std::string>* string_set = new ChainingHashTableSet<std::string, StringEqual, StringHash>();
    tst_string(string_set);
    delete string_set;

    std::cout << "All tests passed!" << std::endl;

    exit(0);
}