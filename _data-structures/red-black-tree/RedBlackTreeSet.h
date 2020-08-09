/**
 * @file RedBlackTreeSet.h
 * @author Taylor Curran
 * @brief Implementation of ISet using red-black tree
 * @version 0.1
 * @date 2020-08-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef RED_BLACK_TREE_SET
#define RED_BLACK_TREE_SET

#include <functional>   // std::less, std::equal_to

#include "../../_abstract-data-types/sets&maps/ISet.h"  // ISet

/**
 * @brief Implementation of ISet interface using a red-black tree. The behaviour
 * of \tparam Equal_To and \tparam Less must be consistent: two objects must
 * be equal if neither is less than the other.
 * 
 * @tparam T data type store in the set
 * @tparam Equal_To equality comparison object (see std::equal_to)
 * @tparam Less comparison object (see std::less)
 */
template<class T, class Equal_To = std::equal_to<T>, class Less = std::less<T>>
class RedBlackTreeSet : public ISet<T, Equal_To>
{
private:

    // TODO

    Less less;

public:
    RedBlackTreeSet<T, Equal_To, Less>();
    ~RedBlackTreeSet<T, Equal_To, Less>();

    size_t size() const noexcept override final;
    bool contains(const T &element) const noexcept override final;
    void insert(const T &element) noexcept override final;
    void remove(const T &element) noexcept override final;
    void clear() noexcept override final;    
};

template<class T, class Equal_To, class Less>
RedBlackTreeSet<T, Equal_To, Less>::RedBlackTreeSet()
{
    // TODO
}

template<class T, class Equal_To, class Less>
RedBlackTreeSet<T, Equal_To, Less>::~RedBlackTreeSet()
{
    // TODO
}

template<class T, class Equal_To, class Less>
size_t RedBlackTreeSet<T, Equal_To, Less>::size() const noexcept
{
    // TODO
}

template<class T, class Equal_To, class Less>
bool RedBlackTreeSet<T, Equal_To, Less>::contains(const T &element) const noexcept
{
    // TODO
}

template<class T, class Equal_To, class Less>
void RedBlackTreeSet<T, Equal_To, Less>::insert(const T &element) noexcept
{
    // TODO
}

template<class T, class Equal_To, class Less>
void RedBlackTreeSet<T, Equal_To, Less>::remove(const T &element) noexcept
{
    // TODO
}

template<class T, class Equal_To, class Less>
void RedBlackTreeSet<T, Equal_To, Less>::clear() noexcept
{
    // TODO
} 

#endif