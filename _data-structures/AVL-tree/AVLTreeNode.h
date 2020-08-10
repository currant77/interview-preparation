/**
 * @file AVLTreeNode.h
 * @author Taylor Curran
 * @brief AVL tree node
 * @version 0.1
 * @date 2020-08-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef AVL_TREE_NODE
#define AVL_TREE_NODE

#include <algorithm> // std::max

template <class T>
struct AVLTreeNode {

    explicit AVLTreeNode(const T& data);
    ~AVLTreeNode();

    T data;
    size_t height;
    AVLTreeNode<T>* left;
    AVLTreeNode<T>* right;
};

template <class T>
AVLTreeNode<T>::AVLTreeNode(const T& data)
    : data(data)
{
}

template <class T>
AVLTreeNode<T>::~AVLTreeNode()
{
}

#endif