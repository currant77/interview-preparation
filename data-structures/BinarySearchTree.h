/**
 * @file BinarySearchTree.h
 * @author Taylor Curran
 * @brief Simple binary search tree
 * @version 0.1
 * @date 2020-06-15
 * 
 * @copyright Copyright (c) 2020 
 */

// Credit

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <functional>

/**
 * @brief Implementation of a binary search tree.
 *
 * @tparam T - template parameter
 * @tparam Less - Function object for performing comparisons between
 * keys; see std::less. 
 */
template<class T, class Less = std::less<T>>
class BinarySearchTree
{
private:
    // Definitions

    /**
     * @brief Binary search tree node. Each node owns its
     * child nodes (i.e. is responsible for their deletion)
     */
    struct Node
    {
        explicit Node(const T& data, Node* left = NULL, Node* right = NULL);
        virtual ~Node();

        T data;
        Node* left;
        Node* right;
    };

    // Members
    Node* root;
    Less less;

    // Recusive private functions
    const T* find(const Node* root, const T& t) const;
    bool insert(Node*& root, const T& t);
    bool remove(Node*& root, const T& t);

    /**
     * @brief Recursive function that replaces the data at \p old_root 
     * with its inorder predecessor (the largest subtree value smaller than it),
     * updates pointers, and set \p old_root to the node to be removed.
     * 
     * @note The algorithm above took me some time to wrap my head around.
     * See (Koffman & Wolfgang 2006, 474-478) for a detailed run-through. 
     * Important: note that old_root is a reference to the pointer to the node
     * that will be deleted in remove(), *not* the reference to the pointer
     * to that node held by its parent.
     */ 
    void replace_parent(Node*& old_root, Node*& local_root);

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
BinarySearchTree<T,Less>::Node::Node(const T& data, Node* left, Node* right) : 
    data(data), left(left), right(right)
{

}

template<class T, class Less>
BinarySearchTree<T,Less>::Node::~Node()
{
    delete left;
    delete right;
}

// Private member functions

template<class T, class Less>
const T* BinarySearchTree<T,Less>::find(const Node* root, const T& t) const
{
    // Base case (empty tree)
    if(root == NULL) 
        return NULL;

    // (1) Search left branch
    else if(less(t, root->data)) 
        return find(root->left, t);

    // (2) Search right branch
    else if(less(root->data, t)) 
        return find(root->right, t);

    // (3) Return node data
    else 
        return &(root->data);
}

template<class T, class Less>
bool BinarySearchTree<T,Less>::insert(Node*& root, const T& t)
{
    // Base case (empty tree)
    if(root == NULL)
    {
        root = new Node(t);
        return true;
    }

    // (1) Insert in left branch
    else if(less(t, root->data)) return insert(root->left, t);

    // (2) Insert in right branch
    else if(less(root->data, t)) return insert(root->right, t);

    // (3) Value is already in tree
    else return false;
}

template<class T, class Less>
bool BinarySearchTree<T,Less>::remove(Node*& root, const T&t)
{
    // Base case
    if(root == NULL) return false;

    // (1) Remove from left branch
    else if(less(t, root->data)) return remove(root->left, t);

    // (2) Remove from right branch
    else if(less(root->data, t)) return remove(root->right, t);

    // (3) Remove root
    else
    {
        // Pointer to the node to be deleted
        Node* old_root = root;

        // (3)(A) Root has no left child
        if(root->left == NULL) 
            root = root->right;

        // (3)(B) Root has no right child
        else if(root->right == NULL)
            root = root->left;

        // (3)(C) Root has two children
        else 
            replace_parent(old_root, root->left);

        old_root->left = old_root->right = NULL;
        delete old_root;
        return true;
    }
}

template<class T, class Less>
void BinarySearchTree<T,Less>::replace_parent(Node*& old_root, Node*& local_root)
{
    // (1) Search right branch
    if(local_root->right != NULL) 
        replace_parent(old_root, local_root->right);

    // (2) local_root is old_root's inorder predecessor
    else
    {
        old_root->data = local_root->data;
        old_root = local_root;
        local_root = local_root->left;
    }    
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
    return find(root, t);
}

template<class T, class Less>
bool BinarySearchTree<T,Less>::insert(const T& t)
{
    return insert(root, t);
}

template<class T, class Less> 
bool BinarySearchTree<T,Less>::remove(const T& t)
{
    return remove(root, t);
}

template<class T, class Less> 
void BinarySearchTree<T,Less>::clear()
{
    delete root;
    root = NULL;
}

#endif