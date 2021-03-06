/**
 * @file ChainingHashTableSet.h
 * @author Taylor Curran
 * @brief Implementation of ISet interface using hash table data structure 
 * with chaining
 * @version 0.1
 * @date 2020-08-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CHAINING_HASH_TABLE_SET
#define CHAINING_HASH_TABLE_SET

#include <functional> // std::hash, std::equal_to
#include <vector> // std::vector

#include "../../_abstract-data-types/sets&maps/ISet.h" // ISet

/**
 * @brief Implementation of ISet interface using hash table data structure 
 * with chaining. Requires: \tparam Equal_To and 
 * \tparam Hash objects must be consistent
 * 
 * @tparam T Data type
 * @tparam Equal_To Equality comparison object type (see std::equal_to)
 * @tparam Hash Hash function object type (see std::hash)
 */
template <class T, class Equal_To = std::equal_to<T>, class Hash = std::hash<T>>
class ChainingHashTableSet : public ISet<T> {
private:
    static const size_t DEFAULT_SIZE = 10;
    static constexpr double LOAD_THRESHOLD = 0.75d;
    static const int EXPANSION_FACTOR = 2;

    size_t num_entries;
    size_t table_size;
    std::vector<T>* table;

    Hash hash;
    Equal_To equal_to;

    void resize();

public:
    explicit ChainingHashTableSet<T, Equal_To, Hash>(size_t size = DEFAULT_SIZE);
    ~ChainingHashTableSet<T, Equal_To, Hash>();

    size_t size() const noexcept override final;
    bool contains(const T& element) const noexcept override final;
    bool insert(const T& element) noexcept override final;
    bool remove(const T& element) noexcept override final;
    void clear() noexcept override final;
};

template <class T, class Equal_To, class Hash>
ChainingHashTableSet<T, Equal_To, Hash>::ChainingHashTableSet(size_t size)
{
    num_entries = 0;
    table_size = size;
    table = new std::vector<T>[table_size];
}

template <class T, class Equal_To, class Hash>
ChainingHashTableSet<T, Equal_To, Hash>::~ChainingHashTableSet()
{
    clear();
}

template <class T, class Equal_To, class Hash>
size_t ChainingHashTableSet<T, Equal_To, Hash>::size() const noexcept
{
    return num_entries;
}

template <class T, class Equal_To, class Hash>
bool ChainingHashTableSet<T, Equal_To, Hash>::contains(const T& element) const noexcept
{
    size_t index = hash(element) % table_size;
    std::vector<T>& vector = table[index];

    for (const T& e : vector) {
        if (equal_to(element, e))
            return true;
    }

    return false;
}

template <class T, class Equal_To, class Hash>
bool ChainingHashTableSet<T, Equal_To, Hash>::insert(const T& element) noexcept
{
    size_t index = hash(element) % table_size;
    std::vector<T>& vector = table[index];

    for (const T& e : vector) {
        if (equal_to(element, e))
            return false;
    }

    vector.push_back(element);
    num_entries++;
    resize();
    return true;
}

template <class T, class Equal_To, class Hash>
bool ChainingHashTableSet<T, Equal_To, Hash>::remove(const T& element) noexcept
{
    size_t index = hash(element) % table_size;
    std::vector<T>& vector = table[index];

    for (auto it = vector.begin(); it != vector.end(); it++) {
        if (equal_to(*it, element)) {
            vector.erase(it);
            num_entries--;
            return true;
        }
    }

    return false;
}

template <class T, class Equal_To, class Hash>
void ChainingHashTableSet<T, Equal_To, Hash>::clear() noexcept
{
    delete[] table;
    num_entries = 0;
    table_size = DEFAULT_SIZE;
    table = new std::vector<T>[table_size];
}

template <class T, class Equal_To, class Hash>
void ChainingHashTableSet<T, Equal_To, Hash>::resize()
{
    // Rehash if load exceeds threshold
    if (double(num_entries) / double(table_size) > LOAD_THRESHOLD) {
        // Create new table
        size_t new_table_size = table_size * EXPANSION_FACTOR;
        std::vector<T>* new_table = new std::vector<T>[new_table_size];

        // Hash all entries to the new table
        for (size_t i = 0; i < table_size; i++) {
            std::vector<T>& vector = table[i];
            for (const T& k : vector) {
                new_table[hash(k) % new_table_size].push_back(k);
            }
        }

        // Update members
        delete[] table;
        table = new_table;
        table_size = new_table_size;
    }
}

#endif