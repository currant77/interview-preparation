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

template<class T, class Hash = std::hash<T>, 
class Equal = std::equal_to<T>>
class HashSet : public ISet<T>
{
    // Constants
    static const size_t DEFAULT_SIZE = 10;
    static constexpr double LOAD_THRESHOLD = 0.75d;
    static const int EXPANSION_FACTOR = 2;

    public:
        explicit HashSet<T, Hash, Equal>(size_t size = DEFAULT_SIZE);
        ~HashSet<T, Hash, Equal>();

        size_t size() const override;
        bool contains(const T& k) const override;
        bool insert(const T& k) override;
        bool remove(const T& k) override;
        void clear() override;
    
    private:
    
        size_t num_entries;
        size_t table_size;
        std::list<T>* table;

        Hash hash;
        Equal equal;

        void resize();
};

template<class T, class Hash, class Equal>
HashSet<T, Hash, Equal>::HashSet(size_t size)
{
    num_entries = 0;
    table_size = size;
    table = new std::list<T>[table_size];
}

template<class T, class Hash, class Equal>
HashSet<T, Hash, Equal>::~HashSet()
{
    delete[] table;
}

template<class T, class Hash, class Equal>
size_t HashSet<T, Hash, Equal>::size() const
{
    return num_entries;   
}

template<class T, class Hash, class Equal>
bool HashSet<T, Hash, Equal>::contains(const T& k) const
{
    size_t index = hash(k) % table_size;
    std::list<T>& list = table[index];

    for (const T& e : list)
    {
        if(equal(k,e)) return true;
    }

    return false;
}

template<class T, class Hash, class Equal>
bool HashSet<T, Hash, Equal>::insert(const T& k)
{
    size_t index = hash(k) % table_size;
    std::list<T>& list = table[index];

    for (const T& e : list)
    {
        if (equal(k,e)) return false;
    }

    list.push_back(k);
    num_entries++;
    resize();
    return true;  
}

template<class T, class Hash, class Equal>
bool HashSet<T, Hash, Equal>::remove(const T& k)
{
    size_t index = hash(k) % table_size;
    std::list<T>& list = table[index];

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

template<class T, class Hash, class Equal>
void HashSet<T, Hash, Equal>::clear()
{
    delete[] table;
    num_entries = 0;
    table_size = DEFAULT_SIZE;
    table = new std::list<T>[table_size];   
}

template<class T, class Hash, class Equal>
void HashSet<T, Hash, Equal>::resize()
{
    // Rehash if load exceeds threshold
    if(double(num_entries) / table_size > LOAD_THRESHOLD)
    {
        // Create new table
        size_t new_table_size = table_size * EXPANSION_FACTOR;
        std::list<T>* new_table = new std::list<T>[new_table_size];
        
        // Hash all entries to the new table
        for(size_t i = 0; i < table_size; i++)
        {
            std::list<T>& list = table[i];
            for (const T& k : list)
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