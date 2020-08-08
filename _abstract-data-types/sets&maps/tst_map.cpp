/**
 * @file tst_map.cpp
 * @author Taylor Curran
 * @brief Tests for the IMap interface
 * @version 0.1
 * @date 2020-08-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <cassert>  // assert
#include <iostream> // std::cout, std::endl

// Interface
#include "IMap.h"

// Implementation of IMap using hash table with open addressing 
// and linear probing (OpenAddressingHashTableMap)
#include "../../_data-structures/hash-table/OpenAddressingHashTableMap.h"

// Custom hash and equality objects for std::string and custom Person class
// (StringEquality, StringHash, Person, PersonEquality, PersonHash)
#include "../../_data-structures/hash-table/HashFunctionExamples.h" 

/**
 * @brief Tests map interface using integer keys
 * 
 * @param map 
 */
void tst_map_int(IMap<int, int>* map)
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

    try
    {
        assert(map->get(3));
        assert(false);
    }
    catch(const std::invalid_argument& e)
    {
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
    
    try
    {
        assert(map->get(2));
        assert(false);
    }
    catch(const std::invalid_argument& e)
    {
        assert(true);
    }
}

/**
 * @brief Tests map interface using std::string keys and custom string equality 
 * comparison object StringEquality
 * @details The default equality comparison for std::string considers
 * two strings equal if they refer to the same object; StringEquality
 * considers strings equal if all their characters match 
 * @param map 
 */
void tst_map_string(IMap<std::string, int, StringEquality>* map)
{
    // Empty table
    assert(!map->size());

    // Add first three values
    map->insert("0", 0);
    map->insert("1", 1);
    map->insert("2", 4);

    assert(map->size() == 3);
    
    assert(map->contains("0"));
    assert(map->contains("1"));
    assert(map->contains("2"));
    assert(!map->contains("3"));
    
    assert(map->get("0") == 0);
    assert(map->get("1") == 1);
    assert(map->get("2") == 4);

    try
    {
        assert(map->get("3"));
        assert(false);
    }
    catch(const std::invalid_argument& e)
    {
        assert(true);
    }
    
    // Remove first two values
    map->remove("1");
    map->remove("0");

    // Try to re-remove values
    map->remove("0");
    map->remove("1");

    assert(map->size() == 1);
    assert(map->contains("2"));
    assert(!map->contains("3"));
    assert(map->get("2") == 4);

    // Clear map
    map->clear();
    assert(!map->size());
    assert(!map->contains("2"));

    // Insert last value
    map->insert("3", 9);
    assert(map->size() == 1);
    assert(map->contains("3"));
    assert(!map->contains("2"));
    assert(map->get("3") == 9);
    
    try
    {
        assert(map->get("2"));
        assert(false);
    }
    catch(const std::invalid_argument& e)
    {
        assert(true);
    }
}

/**
 * @brief Tests map interface using custom class Person and equality comparison
 * object PersonEquality
 * @details PersonEquality considers two people equal if they have the same name
 * (first and last) and social insurance number.
 * 
 * @param map 
 */
void tst_map_person(IMap<Person, int, PersonEquality>* map)
{
    Person a = {"Taylor", "Curran", 29, 7871325};
    Person a_eq = {"Taylor", "Curran", 29, 7899776};
    Person b = {"Spencer", "Curran", 15, 9293418};
    Person c = {"Barack", "Obama", 44, 1234567};
    Person c_eq = {"Barack", "Obama", 44, 6543210};
    Person d = {"Joe", "Biden", 46, 4644644};

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

    try
    {
        assert(map->get(d));
        assert(false);
    }
    catch(const std::invalid_argument& e)
    {
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
    
    try
    {
        assert(map->get(c));
        assert(false);
    }
    catch(const std::invalid_argument& e)
    {
        assert(true);
    }
}

int main()
{
    std::cout << "\nBeginning tests..." << std::endl;

    IMap<int, int>* int_map;
    IMap<std::string, int, StringEquality>* string_map;
    IMap<Person, int, PersonEquality>* person_map;

    // Test ChainingHashTableSet
    std::cout << "Testing OpenAddressingHashTableMap..." << std::endl;

    // Small table size to force rehash
    int_map = new OpenAddressingHashTableMap<int, int>(2);
    string_map = new OpenAddressingHashTableMap<std::string, int, StringEquality, StringHash>(2);
    person_map = new OpenAddressingHashTableMap<Person, int, PersonEquality, PersonHash>(2);

    tst_map_int(int_map);
    tst_map_string(string_map);
    tst_map_person(person_map);

    // Cleanup
    delete int_map;
    delete string_map;
    delete person_map;

    std::cout << "All tests passed!" << std::endl;

    exit(0);
}
