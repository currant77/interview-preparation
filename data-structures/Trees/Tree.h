/**
 * @file Tree.h
 * @author Taylor Curran
 * @brief General tree; supports depth- and breadth-first iterators
 * @version 0.1
 * @date 2020-06-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef TREE_H
#define TREE_H

#include <vector>       // std:: vaector
#include <iterator>     // std::bidirectional_iterator_tag

/**
 * @brief General tree of values of type T 
 * @tparam T - template parameter
 */
template<class T>
class Tree
{
    public:
        // Definitions
        class dfs_iterator;
        //class bfs_iterator;
        // class Node;

        Tree();
        ~Tree();

        bool empty() const;
        size_t size() const;
  
        /**
         * @brief Returns a depth-first order iterator to
         * the root node
         * @return dfs_iterator - depth-first order iterator
         * to the root node
         */
        dfs_iterator dfs_begin();

        /**
         * @brief Returns a depth-first order iterator 
         * that points to the node *after* the last node.
         * in the tree.
         * 
         * @return dfs_iterator - Depth-first iterator to 
         * bode after the last node in the tree
         */
        dfs_iterator dfs_end();
        
        //bfs_iterator bfs_begin();
        //bfs_iterator bfs_end();

        /**
         * @brief Creates a new node with \p value and
         * inserts it as the last child of node at \p pos. 
         * If the tree is empty, inserts it as the root node.
         * 
         * @param pos - depth-first order iterator to a tree node
         * @param value - value associated with the new node
         * @return dfs_iterator - depth-first order iterator to the
         * new node.
         */
        dfs_iterator insert_child(dfs_iterator pos, const T& value);
        //bfs_iterator insert_child(bfs_iterator pos, const T& value);

        /**
         * @brief Creates a new node with \p value and
         * inserts it as a sibling of the node at \p pos (i.e.
         * it will have the same parent node). It will be 
         * inserted directly *before* \p pos in the parents
         * children. If the tree is empty, inserts it as the root node.
         * @throw std::invalid_argument if \p pos points
         * to the the root node
         * @param pos - depth-first order iterator to a tree node
         * @param value - value associated with the new node
         * @return dfs_iterator - depth-first order iterator to the
         * new node.
         */
        dfs_iterator insert_before(dfs_iterator pos, const T& value);
        //bfs_iterator insert_before(bfs_iterator pos, const T& value);

       /**
         * @brief Creates a new node with \p value and
         * inserts it as a sibling of the node at \p pos (i.e.
         * it will have the same parent node). It will be 
         * inserted directly *after* \p pos in the parents
         * children. If the tree is empty, inserts it as the root node.
         * @throw std::invalid_argument if \p pos points
         * to the the root node
         * @param pos - depth-first order iterator to a tree node
         * @param value - value associated with the new node
         * @return dfs_iterator - depth-first order iterator to the
         * new node.
         */
        dfs_iterator insert_after(dfs_iterator pos, const T& value);
        //bfs_iterator insert_after(bfs_iterator pos, const T& value);

        /**
         * @brief Removes the node (and its entire subtree) at
         * the position indicated by \p pos from the tree
         * @throw std::invalid_argument if \p pos equals dfs_end()
         * @param pos - depth-first order iterator to a tree node
         * @return dfs_iterator - depth-first order iterator
         * to the next node in depth-first order
         */
        dfs_iterator remove(dfs_iterator pos);
        //bfs_iterator remove(bfs_iterator pos);

        /**
         * @brief Clears all node from the tree. (All iterators
         * become invalid). 
         */
        void clear();

        class dfs_iterator
        {
            public:
                typedef std::bidirectional_iterator_tag iterator_category;
                
                ~dfs_iterator()
                {
                    // TODO
                }  

                dfs_iterator(const dfs_iterator& it)
                {
                    // TODO
                }
                
                // dfs_iterator(const bfs_iterator& it); 

                dfs_iterator& operator=(const dfs_iterator& it)
                {
                    // TODO
                    return *this;
                }
                
                // dfs_iterator& operator=(const bfs_iterator& it);

                T& operator*() const
                {
                    // TODO
                }

                T* operator->() const
                {
                    // TODO
                    return NULL;
                }

                dfs_iterator& operator++()
                {
                    // TODO
                    return *this;
                }

                dfs_iterator operator++(int)
                {
                    // TODO
                    return *this;
                }

                dfs_iterator& operator--()
                {
                    // TODO
                    return *this;
                }

                dfs_iterator operator--(int)
                {
                    // TODO
                    return *this;
                }

                bool operator==(const dfs_iterator& other) const
                {
                    // TODO
                    return false;
                }

                // bool operator==(const bfs_iterator& other) const;

                bool operator!=(const dfs_iterator& other) const
                {
                    // TODO
                    return false;
                }

                // bool operator!=(const bfs_iterator& other) const;

            private:
                friend class Tree<T>;

                dfs_iterator()
                {
                    // TODO
                }

                // Members
                // TODO
        };
        /*
        class bfs_iterator
        {
            public:
                typedef std::bidirectional_iterator_tag iterator_category;
                
                ~bfs_iterator();  

                bfs_iterator(const bfs_iterator& it)
                // dfs_iterator(const dfs_iterator& it); 

                bfs_iterator& operator=(const bfs_iterator& it);
                // dfs_iterator& operator=(const dfs_iterator& it);

                T& operator*() const;
                T* operator->() const;
                bfs_iterator& operator++();
                bfs_iterator operator++(int);
                bfs_iterator& operator--();
                bfs_iterator operator--(int);
                bool operator==(const bfs_iterator& other) const;
                // bool operator==(const dfs_iterator& other) const;
                bool operator!=(const bfs_iterator& other) const;
                // bool operator!=(const dfs_iterator& other) const;

            private:
                friend class Tree<T>;

                bfs_iterator();

                // TODO
        };
        */
    
    private:

        struct Node
        {
            public:
                explicit Node(const T& value);
                ~Node();

                T& value;
                Node* parent;
                std::vector<Node*> children();
        };

        Node* root;
        size_t num_nodes;
};

template<class T>
Tree<T>::Tree()
{
    // TODO
}

template<class T>
Tree<T>::~Tree()
{
    // TODO
}

template<class T>
bool Tree<T>::empty() const
{
    // TODO
    return false;
}

template<class T>
size_t Tree<T>::size() const
{
    // TODO
    return 0;   
}

template<class T>
typename Tree<T>::dfs_iterator Tree<T>::dfs_begin()
{
    // TODO
    return dfs_iterator();
}

template<class T>
typename Tree<T>::dfs_iterator Tree<T>::dfs_end()
{
    // TODO
    return dfs_iterator();
}
/*
template<class T>
typename Tree<T>::bfs_iterator Tree<T>::bfs_begin()
{
    // TODO
    return bfs_iterator();
}

template<class T>
typename Tree<T>::bfs_iterator Tree<T>::bfs_end()
{
    // TODO
    return bfs_iterator();
}
*/
template<class T>
typename Tree<T>::dfs_iterator Tree<T>::insert_child(dfs_iterator pos, const T& value)
{
    // TODO
    return dfs_iterator();
}
/*
template<class T>
typename Tree<T>::bfs_iterator Tree<T>::insert_child(bfs_iterator pos, const T& value)
{
    // TODO
    return bfs_iterator();
}
*/
template<class T>
typename Tree<T>::dfs_iterator Tree<T>::insert_before(dfs_iterator pos, const T& value)
{
    // TODO
    return dfs_iterator();
}
/*
template<class T>
typename Tree<T>::bfs_iterator Tree<T>::insert_before(bfs_iterator pos, const T& value)
{
    // TODO
    return bfs_iterator();
}
*/
template<class T>
typename Tree<T>::dfs_iterator Tree<T>::insert_after(dfs_iterator pos, const T& value)
{
    // TODO
    return dfs_iterator();
}
/*
template<class T>
typename Tree<T>::bfs_iterator Tree<T>::insert_after(bfs_iterator pos, const T& value)
{
    // TODO
    return bfs_iterator();
}
*/
template<class T>
typename Tree<T>::dfs_iterator Tree<T>::remove(dfs_iterator pos)
{
    // TODO
    return dfs_iterator();
}
/*
template<class T>
typename Tree<T>::bfs_iterator Tree<T>::remove(bfs_iterator pos)
{
    // TODO
    return bfs_iterator();
}
*/
template<class T>
void Tree<T>::clear()
{

}

#endif