/**
 * @file BinarySearchTree.h
 * @author Taylor Curran
 * @brief Simple binary search tree
 * @version 0.1
 * @date 2020-06-15
 * 
 * @copyright Copyright (c) 2020
 * 
 * @note: 
 */

// Credit

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <functional>

template<class T, class Less = std::less<T>>
class BinarySearchTree
{
private:
    // Definitions
    template<class S>
    struct Node
    {
        explicit Node(const T& data, Node<T> left = NULL, Node<T> right = NULL);
        virtual ~Node();

        T data;
        Node<S>* left;
        Node<S>* right;
    };

    // Members
    Node<T>* root;

public:
    explicit BinarySearchTree();
    ~BinarySearchTree();

    const T* find(const T& t) const;
    virtual bool insert(const T& t);
    virtual bool remove(const T& t);
    void clear();
};

// Private class definitions

template<class T, class Less>
template<class S>
BinarySearchTree<T,Less>::Node<S>::Node(const T& data, Node<T> left, Node<T> right) : 
    data(data), left(left), right(right)
{

}

template<class T, class Less>
template<class S>
BinarySearchTree<T,Less>::Node<S>::~Node()
{
    delete left;
    delete right;
}

// Public member functions

template<class T, class Less>
BinarySearchTree<T,Less>::BinarySearchTree() : root(NULL) 
{

}

template<class T, class Less>
BinarySearchTree<T,Less>::~BinarySearchTree()
{
    delete root;
}

template<class T, class Less>
const T* BinarySearchTree<T,Less>::find(const T& t) const
{
    return NULL;
}

template<class T, class Less>
bool BinarySearchTree<T,Less>::insert(const T& t)
{
    return false;
}

template<class T, class Less> 
bool BinarySearchTree<T,Less>::remove(const T& t)
{
    return false;
}

template<class T, class Less> 
void BinarySearchTree<T,Less>::clear()
{
    delete root;
    root = NULL;
}

#endif