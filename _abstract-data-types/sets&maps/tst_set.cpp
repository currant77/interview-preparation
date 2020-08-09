/**
 * @file tst_set.cpp
 * @author Taylor Curran
 * @brief Tests for the ISet interface.
 * @version 0.1
 * @date 2020-08-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <cassert>  // assert
#include <iostream> // std::cout, std::endl

// Interface
#include "ISet.h"

// Custom hash and equality objects for std::string and custom Person class
// (StringEquality, StringHash, Person, PersonEquality, PersonHash)
#include "../../_data-structures/hash-table/HashFunctionExamples.h"

// Implementation of ISet using hash table with chaining (ChainingHashTableSet)
#include "../../_data-structures/hash-table/ChainingHashTableSet.h"

// Implementation of ISet using a red-black tree (RedBlackTreeSet)
#include "../../_data-structures/red-black-tree/RedBlackTreeSet.h"

/**
 * @brief Tests set interface using integers
 * 
 * @param set 
 */
void tst_set_int(ISet<int> *set)
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

/**
 * @brief Tests set interface using custom string equality comparison
 * object StringEquality
 * @details The default equality comparison for std::string considers
 * two strings equal if they refer to the same object; StringEquality
 * considers strings equal if all their characters match
 * 
 * @param set 
 */
void tst_set_string(ISet<std::string, StringEquality> *set)
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

/**
 * @brief Tests set interface using custom class Person 
 * @details Person considers two people equal if they have the same name
 * (first and last) and social insurance number.
 * 
 * @param set 
 */
void tst_set_person(ISet<Person> *set)
{
    Person a = {"Taylor", "Curran", 29, 7871325};
    Person a_eq = {"Taylor", "Curran", 29, 7899776};
    Person b = {"Spencer", "Curran", 15, 9293418};
    Person c = {"Barack", "Obama", 44, 1234567};
    Person c_eq = {"Barack", "Obama", 44, 6543210};
    Person d = {"Joe", "Biden", 46, 4644644};

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
    set->insert(d);
    assert(set->contains(d));
    assert(set->size() == 1);
}

int main()
{
    std::cout << "\nBeginning tests..." << std::endl;

    ISet<int> *int_set;
    ISet<std::string, StringEquality> *string_set;
    ISet<Person> *person_set;

    // Test ChainingHashTableSet
    std::cout << "Testing ChainingHashTableSet..." << std::endl;

    int_set = new ChainingHashTableSet<int>();
    string_set = new ChainingHashTableSet<std::string, StringEquality, StringHash>();
    person_set = new ChainingHashTableSet<Person>();

    tst_set_int(int_set);
    tst_set_string(string_set);
    tst_set_person(person_set);

    delete int_set;
    delete string_set;
    delete person_set;

    // Test RedBlackTreeSet
    std::cout << "Testing RedBlackTreeSet..." << std::endl;

    int_set = new RedBlackTreeSet<int>();
    string_set = new RedBlackTreeSet<std::string, StringEquality>();
    person_set = new RedBlackTreeSet<Person>();

    tst_set_int(int_set);
    tst_set_string(string_set);
    tst_set_person(person_set);

    delete int_set;
    delete string_set;
    delete person_set;

    std::cout << "All tests passed!" << std::endl;

    exit(0);
}
