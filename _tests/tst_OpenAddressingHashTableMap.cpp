/**
 * @file tst_IMap.cpp
 * @author Taylor Curran
 * @brief Tests for OpenAddressingHashTableMap
 * @version 0.1
 * @date 2020-08-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <cassert> // assert
#include <iostream> // std::cout, std::endl

#include "../_data-structures/hash-table/HashFunctionExamples.h"
#include "../_data-structures/hash-table/OpenAddressingHashTableMap.h"

void tst_int(IMap<int, int>* map)
{
    // Empty table
    assert(!map->size());

    // Add first three values
    map->insert(0, 0);
    map->insert(1, 1);
    map->insert(2, 4);

    assert(map->size() == 3);

    assert(map->contains(0));
    assert(map->contains(1));
    assert(map->contains(2));
    assert(!map->contains(3));

    assert(map->get(0) == 0);
    assert(map->get(1) == 1);
    assert(map->get(2) == 4);

    try {
        assert(map->get(3));
        assert(false);
    } catch (const std::invalid_argument& e) {
        assert(true);
    }

    // Remove first two values
    map->remove(1);
    map->remove(0);

    // Try to re-remove values
    map->remove(0);
    map->remove(1);

    assert(map->size() == 1);
    assert(map->contains(2));
    assert(!map->contains(3));
    assert(map->get(2) == 4);

    // Clear map
    map->clear();
    assert(!map->size());
    assert(!map->contains(2));

    // Insert last value
    map->insert(3, 9);
    assert(map->size() == 1);
    assert(map->contains(3));
    assert(!map->contains(2));
    assert(map->get(3) == 9);

    try {
        assert(map->get(2));
        assert(false);
    } catch (const std::invalid_argument& e) {
        assert(true);
    }
}

void tst_person(IMap<Person, int>* map)
{
    Person a = { "Taylor Curran", "1957 W 1st Ave", 29 };
    Person a_eq = { "Taylor Curran", "12625 Tolmie Street", 29 };
    Person b = { "Spencer Curran", "1501 Jubilee Court", 15 };
    Person c = { "Barack Obama", "Hyde Park, Boston", 44 };
    Person c_eq = { "Barack Obama", "1600 Pennsylvania Ave", 44 };
    Person d = { "Joe Biden", "1600 Pensylvania Ave", 46 };

    // Empty table
    assert(!map->size());

    // Add first three values
    map->insert(a, 0);
    map->insert(b, 1);
    map->insert(c, 4);

    assert(map->size() == 3);

    assert(map->contains(a));
    assert(map->contains(b));
    assert(map->contains(c_eq));
    assert(!map->contains(d));

    assert(map->get(a_eq) == 0);
    assert(map->get(b) == 1);
    assert(map->get(c_eq) == 4);

    try {
        assert(map->get(d));
        assert(false);
    } catch (const std::invalid_argument& e) {
        assert(true);
    }

    // Remove first two values
    map->remove(a_eq);
    map->remove(b);

    // Try to re-remove values
    map->remove(a);
    map->remove(b);

    assert(map->size() == 1);
    assert(map->contains(c_eq));
    assert(!map->contains(d));
    assert(map->get(c) == 4);

    // Clear map
    map->clear();
    assert(!map->size());
    assert(!map->contains(c));

    // Insert last value
    map->insert(d, 9);
    assert(map->size() == 1);
    assert(map->contains(d));
    assert(!map->contains(c));
    assert(map->get(d) == 9);

    try {
        assert(map->get(c));
        assert(false);
    } catch (const std::invalid_argument& e) {
        assert(true);
    }
}

int main()
{
    std::cout << "\nBeginning tests..." << std::endl;

    IMap<int, int>* int_set = new OpenAddressingHashTableMap<int, int>();

    tst_int(int_set);
    delete int_set;

    IMap<Person, int>* person_set = new OpenAddressingHashTableMap<Person, int>();

    tst_person(person_set);
    delete person_set;

    std::cout << "All tests passed!" << std::endl;

    exit(0);
}
