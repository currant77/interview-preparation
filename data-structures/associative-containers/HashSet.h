/**
 * @file HashSet.h
 * @author Taylor Curran
 * @brief Implementation of ISet using a hash table with chaining
 * @version 0.1
 * @date 2020-06-12
 * 
 * @copyright Copyright (c) 2020
 *
 */

#ifndef HASH_SET_H
#define HASH_SET_H

#include <list>
#include <functional>
#include "ISet.h"

template<class Key, class Hash = std::hash<Key>, 
class Equal = std::equal_to<Key>>
class HashSet : public ISet<Key>
{
    // Constants
    static const size_t DEFAULT_SIZE = 10;
    static constexpr double LOAD_THRESHOLD = 0.75d;
    static const int EXPANSION_FACTOR = 2;

    public:
        explicit HashSet<Key, Hash, Equal>(size_t size = DEFAULT_SIZE);
        ~HashSet<Key, Hash, Equal>();

        size_t size() const override;
        bool contains(const Key& k) const override;
        bool insert(const Key& k) override;
        bool remove(const Key& k) override;
        void clear() override;
    
    private:
    
        size_t num_entries;
        size_t table_size;
        std::list<Key>* table;

        Hash hash;
        Equal equal;

        void resize();
};

template<class Key, class Hash, class Equal>
HashSet<Key, Hash, Equal>::HashSet(size_t size)
{
    num_entries = 0;
    table_size = size;
    table = new std::list<Key>[table_size];
}

template<class Key, class Hash, class Equal>
HashSet<Key, Hash, Equal>::~HashSet()
{
    delete[] table;
}

template<class Key, class Hash, class Equal>
size_t HashSet<Key, Hash, Equal>::size() const
{
    return num_entries;   
}

template<class Key, class Hash, class Equal>
bool HashSet<Key, Hash, Equal>::contains(const Key& k) const
{
    size_t index = hash(k) % table_size;
    std::list<Key>& list = table[index];

    for (const Key& e : list)
    {
        if(equal(k,e)) return true;
    }

    return false;
}

template<class Key, class Hash, class Equal>
bool HashSet<Key, Hash, Equal>::insert(const Key& k)
{
    size_t index = hash(k) % table_size;
    std::list<Key>& list = table[index];

    for (const Key& e : list)
    {
        if (equal(k,e)) return false;
    }

    list.push_back(k);
    num_entries++;
    resize();
    return true;  
}

template<class Key, class Hash, class Equal>
bool HashSet<Key, Hash, Equal>::remove(const Key& k)
{
    size_t index = hash(k) % table_size;
    std::list<Key>& list = table[index];

    for (auto it = list.begin(); it != list.end(); it++)
    {
        if (equal(*it, k))
        {
            list.erase(it);
            num_entries--;
            return true;
        }
    }

    return false;
}

template<class Key, class Hash, class Equal>
void HashSet<Key, Hash, Equal>::clear()
{
    delete[] table;
    num_entries = 0;
    table_size = DEFAULT_SIZE;
    table = new std::list<Key>[table_size];   
}

template<class Key, class Hash, class Equal>
void HashSet<Key, Hash, Equal>::resize()
{
    // Rehash if load exceeds threshold
    if(num_entries / table_size > LOAD_THRESHOLD)
    {
        // Create new table
        size_t new_table_size = table_size * EXPANSION_FACTOR;
        std::list<Key>* new_table = new std::list<Key>[new_table_size];
        
        // Hash all entries to the new table
        for(size_t i = 0; i < table_size; i++)
        {
            std::list<Key>& list = table[i];
            for (const Key& k : list)
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