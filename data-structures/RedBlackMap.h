/**
 * @file RedBlackMap.h
 * @author Taylor Curran
 * @brief Implementation of ISet using a red-black tree
 * @version 0.1
 * @date 2020-06-15
 * 
 * @note One of the main advantages of implementing a map using
 * a red-black tree (rather than a hash table; see "HashMap.h")
 * it that it provides a defined ordering for the keys in the
 * set and allows them to be traversed in that order. This was 
 * not implemented here for simplicity, but it would be relatively
 * straight-forward to do so (depth-first search).
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef RED_BLACK_MAP_H
#define RED_BLACK_MAP_H


#include <utility>      // std::pair
#include <functional>   // std::less
#include "IMap.h"

template<class T, class Value, class Less = std::less<T>>
class RedBlackMap : public IMap<T, Value>
{
    private:
        // Classa and struct definitions
        struct Node
        {
            T key;
            Value value;
            Node* left = NULL;
            Node* right = NULL;
            Node* parent = NULL;
        };

        // Members
        size_t num_entries = 0;
        Node* root = NULL;
    
    public:
        explicit RedBlackMap<T, Value, Less>();
        ~RedBlackMap<T, Value, Less>();

        size_t size() const override;
        bool lookup(const Key& k, Value& v) const override;
        void insert(const Key& k, const Value& v) override;
        bool remove(const Key& k) override;
        void clear() override;
};

template<class T, class Value, class Less>
RedBlackMap<T, Value, Less>::RedBlackMap()
{

}

template<class T, class Value, class Less>
RedBlackMap<T, Value, Less>::~RedBlackMap()
{
    
}

template<class T, class Value, class Less >
size_t RedBlackMap<T, Value, Less>::size() const
{
    return 0;
}

template<class T, class Value, class Less>
bool RedBlackMap<T, Value, Less>::lookup(const T& k, Value& v) const
{
    return false;
}

template<class T, class Value, class Less>
void RedBlackMap<T, Value, Less>::insert(const T& k, const Value& v)
{
    return;
}

template<class T, class Value, class Less>
bool RedBlackMap<T, Value, Less>::remove(const T& k)
{
    return false;
}

template<class T, class Value, class Less>
void RedBlackMap<T, Value, Less>::clear()
{
    return;  
}

#endif