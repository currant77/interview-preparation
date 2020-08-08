/**
 * @file HashSet.h
 * @author Taylor Curran
 * @brief Implementation of the ISet interface using a hash table with chaining
 * @version 0.1
 * @date 2020-06-12
 * 
 * @copyright Copyright (c) 2020
 *
 */

#ifndef HASH_TABLE_SET_H
#define HASH_TABLE_SET_H

#include <vector>       // std::vector
#include <functional>   // std::hash

#include "ISet.h"       // ISet

template<class T, class Equal_To = std::equal_to<T>, class Hash = std::hash<T>>
class HashTableSet : public ISet<T, Equal_To>
{
    private:

    // Constants
    static const size_t DEFAULT_SIZE = 10;
    static constexpr double LOAD_THRESHOLD = 0.75d;
    static const int EXPANSION_FACTOR = 2;

    // Members
    size_t num_entries;
    size_t table_size;
    std::vector<T>* table;

    Hash hash;
    Equal_To equal_to;

    void resize();

    public:

    explicit HashTableSet<T, Equal_To, Hash>(size_t size = DEFAULT_SIZE);
    ~HashTableSet<T, Equal_To, Hash>();

    size_t size() const noexcept;
    bool contains(const T& element) const noexcept;
    void insert(const T& element) noexcept;
    void remove(const T& element) noexcept;
    void clear() noexcept;    
};

template<class T, class Equal_To, class Hash>
HashTableSet<T, Equal_To, Hash>::HashTableSet(size_t size)
{
    num_entries = 0;
    table_size = size;
    table = new std::vector<T>[table_size];
}

template<class T, class Equal_To, class Hash>
HashTableSet<T, Equal_To, Hash>::~HashTableSet()
{
    clear();
}

template<class T, class Equal_To, class Hash>
size_t HashTableSet<T, Equal_To, Hash>::size() const noexcept
{
    return num_entries;   
}

template<class T, class Equal_To, class Hash>
bool HashTableSet<T, Equal_To, Hash>::contains(const T& element) const noexcept
{
    size_t index = hash(element) % table_size;
    std::vector<T>& vector = table[index];

    for (const T& e : vector)
    {
        if(equal_to(element,e)) 
            return true;
    }

    return false;
}

template<class T, class Equal_To, class Hash>
void HashTableSet<T, Equal_To, Hash>::insert(const T& element) noexcept
{
    size_t index = hash(element) % table_size;
    std::vector<T>& vector = table[index];

    for (const T& e : vector)
    {
        if (equal_to(element,e)) 
            return;
    }

    vector.push_back(element);
    num_entries++;
    resize();
}

template<class T, class Equal_To, class Hash>
void HashTableSet<T, Equal_To, Hash>::remove(const T& element) noexcept
{
    size_t index = hash(element) % table_size;
    std::vector<T>& vector = table[index];

    for (auto it = vector.begin(); it != vector.end(); it++)
    {
        if (equal_to(*it, element))
        {
            vector.erase(it);
            num_entries--;
            return;
        }
    }
}

template<class T, class Equal_To, class Hash>
void HashTableSet<T, Equal_To, Hash>::clear() noexcept
{
    delete[] table;
    num_entries = 0;
    table_size = DEFAULT_SIZE;
    table = new std::vector<T>[table_size];   
} 

template<class T, class Equal_To, class Hash>
void HashTableSet<T, Equal_To, Hash>::resize()
{
    // Rehash if load exceeds threshold
    if(double(num_entries) / double(table_size) > LOAD_THRESHOLD)
    {
        // Create new table
        size_t new_table_size = table_size * EXPANSION_FACTOR;
        std::vector<T>* new_table = new std::vector<T>[new_table_size];
        
        // Hash all entries to the new table
        for(size_t i = 0; i < table_size; i++)
        {
            std::vector<T>& vector = table[i];
            for (const T& k : vector)
            {
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