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
        class Node;

        Tree();
        ~Tree();

        bool empty() const;
        size_t num_nodes() const;

        Node* root();

        dfs_iterator dfs_begin();
        dfs_iterator dfs_end();
        //bfs_iterator bfs_begin();
        //bfs_iterator bfs_end();

        dfs_iterator insert_child(dfs_iterator pos, const T& value);
        //bfs_iterator insert_child(bfs_iterator pos, const T& value);

        dfs_iterator insert_before(dfs_iterator pos, const T& value);
        //bfs_iterator insert_before(bfs_iterator pos, const T& value);

        dfs_iterator insert_after(dfs_iterator pos, const T& value);
        //bfs_iterator insert_after(bfs_iterator pos, const T& value);

        dfs_iterator remove(dfs_iterator pos);
        //bfs_iterator remove(bfs_iterator pos);

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
                    return T();
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
        class Node
        {
            public:
                explicit Node(const T& value);
                ~Node();

                T& value();
                Node* parent();
                std::vector<Node*> children();

            private:
                T& value;
                Node* parent;
                std::vector<Node*> children();
        };
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
size_t Tree<T>::num_nodes() const
{
    // TODO
    return 0;   
}

template<class T>
typename Tree<T>::Node* Tree<T>::root()
{
    // TODO
    return NULL;
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