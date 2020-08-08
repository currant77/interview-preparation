/**
 * @file HashMap.h
 * @author Taylor Curran
 * @brief Implementation of ISet using a hash table with open addressing
 * and linear probing; based in part on (Koffman and Wolfgang 2006, 530-558)
 * @version 0.1
 * @date 2020-06-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <utility>
#include <functional>
#include "IMap.h"

template <class T, class Value, class Hash = std::hash<T>,
          class Equal = std::equal_to<T>>
class HashMap : public IMap<T, Value>
{
private:
    // Type definitions
    typedef std::pair<const T, Value> Entry_Type;

    // Constants
    static const int EXPANSION_FACTOR = 2;
    static constexpr double LOAD_THRESHOLD = 0.75d;
    static const size_t DEFAULT_SIZE = 100;
    static const int STRIDE = 1;

    static Entry_Type dummy;          // Dummy entry for deletes
    static Entry_Type *const DELETED; // Pointer to dummy entry

    // Members
    size_t num_entries;
    size_t num_deleted;

    size_t table_size;
    size_t initial_size;
    Entry_Type **table;

    Hash hash;
    Equal equal;

    /**
         * @brief Rehashes the table if load threshold is exceeded
         */
    void rehash();

    /**
         * @brief If the key is in the table, returns its index; else
         * returns the first free slot
         */
    size_t locate(const T &k, Entry_Type **table, size_t table_size) const;

public:
    explicit HashMap<T, Value, Hash, Equal>(size_t size = DEFAULT_SIZE);
    ~HashMap<T, Value, Hash, Equal>();

    size_t size() const override;
    bool lookup(const T &k, Value &v) const override;
    void insert(const T &k, const Value &v) override;
    bool remove(const T &k) override;
    void clear() override;
};

// Initialize static class members
// (see Koffman and Wolfgang 2006, 545)
template <class T, class Value, class Hash, class Equal>
typename HashMap<T, Value, Hash, Equal>::Entry_Type
    HashMap<T, Value, Hash, Equal>::dummy =
        std::pair<const T, Value>(T(), Value());

template <class T, class Value, class Hash, class Equal>
typename HashMap<T, Value, Hash, Equal>::Entry_Type *const
    HashMap<T, Value, Hash, Equal>::DELETED =
        &HashMap<T, Value, Hash, Equal>::dummy;

template <class T, class Value, class Hash, class Equal>
HashMap<T, Value, Hash, Equal>::HashMap(size_t size)
{
    num_entries = 0;
    num_deleted = 0;
    initial_size = table_size = size;
    table = new Entry_Type *[initial_size]();
}

template <class T, class Value, class Hash, class Equal>
HashMap<T, Value, Hash, Equal>::~HashMap()
{
    for (size_t i = 0; i < table_size; i++)
    {
        delete table[i];
    }

    delete[] table;
}

template <class T, class Value, class Hash, class Equal>
size_t HashMap<T, Value, Hash, Equal>::size() const
{
    return num_entries;
}

template <class T, class Value, class Hash, class Equal>
bool HashMap<T, Value, Hash, Equal>::lookup(const T &k, Value &v) const
{
    size_t i = locate(k, table, table_size);

    if (table[i] == NULL)
    {
        return false;
    }

    else
    {
        v = table[i]->second;
        return true;
    }
}

template <class T, class Value, class Hash, class Equal>
void HashMap<T, Value, Hash, Equal>::insert(const T &k, const Value &v)
{
    size_t i = locate(k, table, table_size);

    // Key is not in table - insert pair
    if (table[i] == NULL)
    {
        table[i] = new Entry_Type(k, v);
        num_entries++;

        // Rehash table if necessary
        if (double(num_entries + num_deleted) / table_size >= LOAD_THRESHOLD)
        {
            rehash();
        }
    }

    // Key is already in table - update value
    else
    {
        table[i]->second = v;
    }
}

template <class T, class Value, class Hash, class Equal>
bool HashMap<T, Value, Hash, Equal>::remove(const T &k)
{
    size_t i = locate(k, table, table_size);

    // Key is not in table
    if (table[i] == NULL)
    {
        return false;
    }

    // Key is in table
    else
    {
        delete table[i];
        table[i] = DELETED;
        num_entries--;
        num_deleted++;
        return true;
    }
}

template <class T, class Value, class Hash, class Equal>
void HashMap<T, Value, Hash, Equal>::clear()
{
    // Delete existing entries
    for (size_t i = 0; i < table_size; i++)
    {
        delete table[i];
    }

    delete[] table;

    // Create new table
    num_entries = 0;
    num_deleted = 0;
    table_size = initial_size;
    table = new Entry_Type *[initial_size]();
}

template <class T, class Value, class Hash, class Equal>
void HashMap<T, Value, Hash, Equal>::rehash()
{
    // Create new table
    size_t new_table_size = table_size * EXPANSION_FACTOR;
    Entry_Type **new_table = new Entry_Type *[new_table_size]();

    // Hash all entries to new table
    size_t new_index;
    for (size_t i = 0; i < table_size; i++)
    {
        if (table[i] != NULL && table[i] != DELETED)
        {
            new_index = locate(table[i]->first, new_table, new_table_size);
            new_table[new_index] = table[i];
        }
    }

    // Update members
    delete[] table;
    table = new_table;
    table_size = new_table_size;
    num_deleted = 0;
}

template <class T, class Value, class Hash, class Equal>
size_t HashMap<T, Value, Hash, Equal>::locate(const T &k,
                                                Entry_Type **table, size_t table_size) const
{
    size_t i = hash(k) % table_size;

    while (table[i] != NULL &&
           (table[i] == DELETED || !equal(table[i]->first, k)))
    {
        i = (i + STRIDE) % table_size;
    }

    return i;
}



#endif