/**
 * @file AVLTreeSet.h
 * @author Taylor Curran
 * @brief Implementation of the ISet interface using an AVL tree
 * @version 0.1
 * @date 2020-08-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef AVL_TREE_SET_H
#define AVL_TREE_SET_H

#include "../../../_abstract-data-types/sets&maps/ISet.h" // ISet
#include "AVLTree.h" // AVLTree

/**
 * @brief Implementation of the ISet interface using an AVL tree. Tree uses 
 * \tparam Less comparison object to create AVL tree: behaviour of Equal_To and 
 * Less must be consistent!
 * 
 * @tparam T Data type of set elements
 * @tparam Equal_To Equality comparison object (see std::equal_to)
 * @tparam Less Comparison object (see std::less). Requires: behaviour must be
 * consistent with Equal_To.
 */
template <class T, class Equal_To = std::equal_to<T>, class Less = std::less<T>>
class AVLTreeSet : public ISet<T, Equal_To> {
public:
    AVLTreeSet<T, Equal_To, Less>();
    ~AVLTreeSet();

    size_t size() const noexcept;
    bool contains(const T& element) const noexcept;
    bool insert(const T& element) noexcept;
    bool remove(const T& element) noexcept;
    void clear() noexcept;

private:
    AVLTree<T, Less> avl;
};

template <class T, class Equal_To, class Less>
AVLTreeSet<T, Equal_To, Less>::AVLTreeSet()
{
}

template <class T, class Equal_To, class Less>
AVLTreeSet<T, Equal_To, Less>::~AVLTreeSet()
{
}

template <class T, class Equal_To, class Less>
size_t AVLTreeSet<T, Equal_To, Less>::size() const noexcept
{
    return avl.size();
}

template <class T, class Equal_To, class Less>
bool AVLTreeSet<T, Equal_To, Less>::contains(const T& element) const noexcept
{
    return avl.find(element);
}

template <class T, class Equal_To, class Less>
bool AVLTreeSet<T, Equal_To, Less>::insert(const T& element) noexcept
{
    return avl.insert(element);
}

template <class T, class Equal_To, class Less>
bool AVLTreeSet<T, Equal_To, Less>::remove(const T& element) noexcept
{
    return avl.remove(element);
}

template <class T, class Equal_To, class Less>
void AVLTreeSet<T, Equal_To, Less>::clear() noexcept
{
    avl.clear();
}

#endif