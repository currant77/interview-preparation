/**
 * @file AVLTree.h
 * @author Taylor Curran
 * @brief AVL tree
 * @version 0.1
 * @date 2020-08-09
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef AVL_TREE
#define AVL_TREE

#include <algorithm> // std::max
#include <cassert> // assert
#include <functional> // std::less

#include "../binary-search-tree/IBinarySearchTree.h" // IBinarySearchTree
#include "AVLTreeNode.h" // AVLTreeNode

template <class T, class Less = std::less<T>>
class AVLTree : public IBinarySearchTree<T, Less> {
public:
    AVLTree();
    ~AVLTree();

    size_t size() const noexcept override final;
    const T* find(const T& item) const noexcept override final;
    bool insert(const T& item) noexcept override final;
    bool remove(const T& item) noexcept override final;
    void clear() noexcept override final;

private:
    AVLTreeNode<T>* root;
    size_t num_entries;
    Less less;

    const T* find(const AVLTreeNode<T>* local_root, const T& item) const noexcept;
    bool insert(AVLTreeNode<T>*& local_root, const T& item) noexcept;
    bool remove(AVLTreeNode<T>*& local_root, const T& item) noexcept;
    void clear(AVLTreeNode<T>* local_root) noexcept;

    void rotate_left(AVLTreeNode<T>*& local_root);
    void rotate_right(AVLTreeNode<T>*& local_root);

    /**
     * @brief If \p is null, return 0; else returns height. Requires: heights of
     * child nodes are set correctly.
     * 
     * @param node 
     * @return size_t 
     */
    size_t height(AVLTreeNode<T>* node) const noexcept;

    /**
     * @brief Sets the height of \p node. Requires: heights of child nodes are
     * set correctly.
     * 
     * @param node 
     */
    void set_height(AVLTreeNode<T>* node) const noexcept;

    /**
     * @brief If \p node is null, return 0; else returns balance. Requires:
     * heights of child nodes are set correctly.
     * 
     * @param node 
     * @return size_t 
     */
    size_t balance(AVLTreeNode<T>* node) const noexcept;
};

// Public members ===========

template <class T, class Less>
AVLTree<T, Less>::AVLTree()
{
    root = NULL;
    num_entries = 0;
}

template <class T, class Less>
AVLTree<T, Less>::~AVLTree()
{
    clear();
}

template <class T, class Less>
size_t AVLTree<T, Less>::size() const noexcept
{
    return num_entries;
}

template <class T, class Less>
const T* AVLTree<T, Less>::find(const T& item) const noexcept
{
    return find(root, item);
}

template <class T, class Less>
bool AVLTree<T, Less>::insert(const T& item) noexcept
{
    return insert(root, item);
}

template <class T, class Less>
bool AVLTree<T, Less>::remove(const T& item) noexcept
{
    return remove(root, item);
}

template <class T, class Less>
void AVLTree<T, Less>::clear() noexcept
{
    clear(root);
}

// Private members ===========

template <class T, class Less>
const T* AVLTree<T, Less>::find(const AVLTreeNode<T>* local_root,
    const T& item) const noexcept
{
    if (!root)
        return NULL;

    else if (less(item, root->data))
        return find(root->left, item);

    else if (less(root->data, item))
        return find(root->right, item);

    else
        return &(root->data);
}

template <class T, class Less>
bool AVLTree<T, Less>::insert(AVLTreeNode<T>*& root, const T& item) noexcept
{
    // Base case: empty subtree
    if (!root) {
        root = new AVLTreeNode<T>(item);
        root->height = 0;
        num_entries++;
        return true;
    }

    // Insert in left subtree
    else if (less(item, root->data)) {
        if (!insert(root->left, item))
            return false;

        // Set height
        set_height(root);

        // Rebalance
        if (balance(root) < 1) {

            // Case Left-Right
            if (balance(root->left) > 0)
                rotate_left(root->left);

            // Case Left-Left
            rotate_right(root);
        }

        num_entries++;
        return true;
    }

    // Insert in right subtree
    else if (less(root->data, item)) {
        if (!insert(root->right, item))
            return false;

        // Set height
        set_height(root);

        // Rebalance
        if (balance(root) > 1) {

            // Case Right-Left
            if (balance(root->right) < 0)
                rotate_right(root->right);

            // Case Right-Right
            rotate_left(root);
        }

        num_entries++;
        return true;
    }

    // Item is at root
    else
        return false;
}

template <class T, class Less>
bool AVLTree<T, Less>::remove(AVLTreeNode<T>*& local_root,
    const T& item) noexcept
{
    // TODO
    return false;
}

template <class T, class Less>
void AVLTree<T, Less>::clear(AVLTreeNode<T>* local_root) noexcept
{
    if (!root)
        return;

    // Clear subtrees
    clear(root->left);
    clear(root->right);

    delete root;
    num_entries--;
}

template <class T, class Less>
void AVLTree<T, Less>::rotate_left(AVLTreeNode<T>*& root)
{
    // Check conditions
    assert(root);
    assert(root->right);

    // Rotate left about local_root
    AVLTreeNode<T>* right = root->right;
    root->right = right->left;
    right->left = root;
    root = right;

    // Set heights
    set_height(root->left);
    set_height(root);
}

template <class T, class Less>
void AVLTree<T, Less>::rotate_right(AVLTreeNode<T>*& root)
{
    // Check conditions
    assert(root);
    assert(root->left);

    // Rotate right about root
    AVLTreeNode<T>* left = root->left;
    root->left = left->right;
    left->right = root;
    root = left;

    // Set heights
    set_height(root->right);
    set_height(root);
}

template <class T, class Less>
size_t AVLTree<T, Less>::height(AVLTreeNode<T>* node) const noexcept
{
    return node ? node->height : -1;
}

template <class T, class Less>
void AVLTree<T, Less>::set_height(AVLTreeNode<T>* node) const noexcept
{
    if (node) {
        node->height = 1 + std::max({ height(node->left), height(node->right) });
    }
}

template <class T, class Less>
size_t AVLTree<T, Less>::balance(AVLTreeNode<T>* node) const noexcept
{
    return node ? height(node->left) - height(node->right) : 0;
}

#endif