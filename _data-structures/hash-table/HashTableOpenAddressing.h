/**
 * @file HashTableOpenAddressing.h
 * @author Taylor Curran
 * @brief Implementation of IMap interface using hash table data structure with
 * open addressing and linear probing
 * @version 0.1
 * @date 2020-08-08
 * 
 * @copyright Copyright (c) 2020
 * 
 * @ref Koffman and Wolfgang 2006, 530-558
 */

#ifndef HASH_TABLE_OPEN_ADDRESSING
#define HASH_TABLE_OPEN_ADDRESSING

#include <utility>      // std::pair
#include <functional>   // std::hash, std::map

#include "../../_abstract-data-types/sets&maps/IMap.h" // IMap

/**
 * @brief Implementation of IMap interface using hash table data structure with
 * open addressing and linear probing
 * 
 * @tparam K key data type
 * @tparam V value data type
 * @tparam Equal_To equality comparison object type (see std::equal_to)
 * @tparam Hash hash function object type (see std::hash)
 */
template <
    class K,
    class V,
    class Equal_To = std::equal_to<K>,
    class Hash = std::hash<K>>
class HashMap : public IMap<K, V>
{
private:
    typedef std::pair<const K, V> Entry_Type;

    static const size_t EXPANSION_FACTOR = 2;
    static constexpr double LOAD_THRESHOLD = 0.75d;
    static const size_t DEFAULT_SIZE = 100;
    static const size_t STRIDE = 1;

    static Entry_Type dummy;          // Dummy entry for deletes
    static Entry_Type *const DELETED; // Pointer to dummy entry

    // Members
    size_t num_entries;
    size_t num_deleted;

    size_t table_size;
    size_t initial_size;
    Entry_Type **table;

    Hash hash;
    Equal_To equal_to;

    /**
     * @brief Rehashes the table if load threshold is exceeded
     * 
     */
    void rehash() noexcept;

    /**
     * @brief Searches \p table for \p key
     * If \p key is found, returns its index; if it is not found, return the
     * first free index.
     * 
     * @param key
     * @param table 
     * @param table_size 
     * @return size_t table index corresponding to \p key or first free slot
     */
    size_t find(const K &key, Entry_Type** table, 
        size_t table_size) const noexcept;

public:
    explicit HashMap<K, V, Equal_To, Hash>(size_t size = DEFAULT_SIZE);
    ~HashMap<K, V, Equal_To, Hash>();

    size_t size() const noexcept override final;
    V& get(const K& key) override final;
    const V& get(const K& key) const override final;
    void insert(const K& key, const V& value) noexcept override final;
    void remove(const K& key) noexcept override final;
    void clear() noexcept override final;
};

// Initialize static class members
template <class K, class V, class Equal_To, class Hash>
typename HashMap<K, V, Equal_To, Hash>::Entry_Type
    HashMap<K, V, Equal_To, Hash>::dummy = std::pair<const K, V>(K(), V());

template <class K, class V, class Equal_To, class Hash>
typename HashMap<K, V, Equal_To, Hash>::Entry_Type *const
    HashMap<K, V, Equal_To, Hash>::DELETED = 
        &HashMap<K, V, Equal_To, Hash>::dummy;

template <class K, class V, class Equal_To, class Hash>
HashMap<K, V, Equal_To, Hash>::HashMap(size_t size)
{
    num_entries = 0;
    num_deleted = 0;
    initial_size = table_size = size;
    table = new Entry_Type *[initial_size]();
}

template <class K, class V, class Equal_To, class Hash>
HashMap<K, V, Equal_To, Hash>::~HashMap()
{
    for (size_t i = 0; i < table_size; i++)
    {
        delete table[i];
    }

    delete[] table;
}

template <class K, class V, class Equal_To, class Hash>
size_t HashMap<K, V, Equal_To, Hash>::size() const noexcept
{
    return num_entries;
}

template <class K, class V, class Equal_To, class Hash>
V& HashMap<K, V, Equal_To, Hash>::get(const K& key)
{
    size_t i = find(key, table, table_size);

    if(table[i] == NULL)
        throw std::invalid_argument("Map does not contain key");

    return table[i]->second;
}

template <class K, class V, class Equal_To, class Hash>
const V& HashMap<K, V, Equal_To, Hash>::get(const K& key) const
{
    return get(key);
}

template <class K, class V, class Equal_To, class Hash>
void HashMap<K, V, Equal_To, Hash>::insert(const K& key, const V& value) noexcept
{
    size_t i = find(key, table, table_size);

    // Key is not in table - insert pair
    if (table[i] == NULL)
    {
        table[i] = new Entry_Type(key, value);
        num_entries++;

        rehash();
    }

    // Key is already in table - update value
    else
    {
        table[i]->second = value;
    }
}

template <class K, class V, class Equal_To, class Hash>
void HashMap<K, V, Equal_To, Hash>::remove(const K& key) noexcept
{
    size_t i = find(key, table, table_size);

    if(table[i] != NULL)
    {
        delete table[i];
        table[i] = DELETED;
        num_entries--;
        num_deleted++;
    }
}

template <class K, class V, class Equal_To, class Hash>
void HashMap<K, V, Equal_To, Hash>::clear() noexcept
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

template <class K, class V, class Equal_To, class Hash>
size_t HashMap<K, V, Equal_To, Hash>::find(
    const K &key, Entry_Type** table, size_t table_size) const noexcept
{
    size_t i = hash(key) % table_size;

    while (table[i] != NULL && 
        (table[i] == DELETED || !equal_to(table[i]->first, key)))
    {
        i = (i + STRIDE) % table_size;
    }

    return i;
}

template <class K, class V, class Equal_To, class Hash>
void HashMap<K, V, Equal_To, Hash>::rehash() noexcept
{

    if (double(num_entries + num_deleted) / double(table_size) >= LOAD_THRESHOLD)
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
                new_index = find(table[i]->first, new_table, new_table_size);
                new_table[new_index] = table[i];
            }
        }

        // Update members
        delete[] table;
        table = new_table;
        table_size = new_table_size;
        num_deleted = 0;
    }
}



#endif