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

// Implementation of ISet using hash table with chaining
#include "../../_data-structures/hash-table/HashTableChaining.h"

// Custom hash and equality objects for std::string and custom Person class
#include "../../_data-structures/hash-table/HashFunctionExamples.h"

template <class T, class Equal_To = std::equal_to<T>>
void tst_set(ISet<T, Equal_To> *set, T tst_values[4])
{
    // Empty table
    assert(!set->size());

    // Add first three values
    set->insert(tst_values[0]);
    set->insert(tst_values[1]);
    set->insert(tst_values[2]);

    // Try to re-insert values
    set->insert(tst_values[0]);
    set->insert(tst_values[2]);

    assert(set->size() == 3);
    assert(set->contains(tst_values[0]));
    assert(set->contains(tst_values[2]));
    assert(!set->contains(tst_values[3]));

    // Remove first two values
    set->remove(tst_values[1]);
    set->remove(tst_values[0]);

    // Try to re-remove values
    set->remove(tst_values[0]);
    set->remove(tst_values[1]);

    assert(set->size() == 1);
    assert(set->contains(tst_values[2]));
    assert(!set->contains(tst_values[1]));

    // Clear set
    set->clear();
    assert(!set->size());
    assert(!set->contains(tst_values[2]));

    // Insert last value
    set->insert(tst_values[3]);
    assert(set->contains(tst_values[3]));
    assert(set->size() == 1);
}

int main()
{
    std::cout << "\nBeginning tests..." << std::endl;

    // Create test objects
    int unique_ints[4] = {1, 2, 3, 4};
    std::string unique_strings[4] = {"A", "B", "C", "D"};

    Person unique_persons[4];
    unique_persons[0] = {"Taylor", "Curran", 29, 7871325};
    unique_persons[1] = {"Taylor", "Curran", 7, 7899776};
    unique_persons[2] = {"Spencer", "Curran", 15, 9293418};
    unique_persons[3] = {"Barack", "Obama", 44, 1234567};

    ISet<int> *int_set;
    ISet<std::string, StringEquality> *string_set;
    ISet<Person, PersonEquality> *person_set;

    // Test HashTableChaining
    std::cout << "Testing HashTableChaining..." << std::endl;

    int_set = new HashTableChaining<int>(2);
    string_set = new HashTableChaining<std::string, StringEquality, StringHash>(2);
    person_set = new HashTableChaining<Person, PersonEquality, PersonHash>(2);

    tst_set<int>(int_set, unique_ints);
    tst_set<std::string, StringEquality>(string_set, unique_strings);
    tst_set<Person, PersonEquality>(person_set, unique_persons);

    // Cleanup
    delete int_set;
    delete string_set;
    delete person_set;

    std::cout << "All tests passed!" << std::endl;

    exit(0);
}
