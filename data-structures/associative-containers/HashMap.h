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

template<class Key, class Value, class Hash = std::hash<Key>, 
class Equal = std::equal_to<Key>>
class HashMap : public IMap<Key, Value>
{
    // Constants
    static const size_t DEFAULT_SIZE = 10;
    static constexpr double LOAD_THRESHOLD = 0.75d;
    static const int EXPANSION_FACTOR = 2;
    
    public:
        typedef std::pair<Key, Value> Entry_Type;

        explicit HashMap<Key, Value, Hash, Equal>(size_t size = DEFAULT_SIZE);
        virtual ~HashMap<Key, Value, Hash, Equal>();

        size_t size() const override;
        bool lookup(const Key& k, const Value& v) const override;
        void insert(const Key& k, const Value& v) override;
        bool remove(const Key& k) override;
        void clear() override;  

    private:
        size_t num_entries;        // Number of entries
        size_t num_deleted;        // Number of deleted entries

        Entry_Type** table;
        size_t table_size;

        const Entry_Type dummy;     // Dummy entry for deletes  
        const Entry_Type* DELETED;  // Pointer to dummy entry

        Hash hash;
        Equal equal;

        void resize();
};

template<class Key, class Value, class Hash, class Equal>
HashMap<Key, Value, Hash, Equal>::HashMap(size_t size)
{
    return;
}

template<class Key, class Value, class Hash, class Equal>
HashMap<Key, Value, Hash, Equal>::~HashMap()
{
    return;
}

template<class Key, class Value, class Hash, class Equal>
size_t HashMap<Key, Value, Hash, Equal>::size() const
{
    return 0;
}

template<class Key, class Value, class Hash, class Equal>
bool HashMap<Key, Value, Hash, Equal>::lookup(const Key& k, const Value& v) const
{
    return false;   
}

template<class Key, class Value, class Hash, class Equal>
void HashMap<Key, Value, Hash, Equal>::insert(const Key& k, const Value& v)
{
    return;
}

template<class Key, class Value, class Hash, class Equal>
bool HashMap<Key, Value, Hash, Equal>::remove(const Key& k)
{
    return false;
}

template<class Key, class Value, class Hash, class Equal>
void HashMap<Key, Value, Hash, Equal>::clear()
{
    return;
}  

#endif