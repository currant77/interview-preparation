/**
 * @file explicit-heap.cpp
 * @author Taylor Curran
 * @brief Implementation of priority queue using an explicit 
 * heap data structure - a binary heap.
 * @version 0.1
 * @date 2020-07-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "priority-queue.h"

template<class T, class GreaterEqual = std::greater_equal<T>>
class ExplicitHeap : public PriorityQueue<T, GreaterEqual>
{
    private:
        struct BinaryTreeNode
        {
            explicit BinaryTreeNode(
                const T& value, 
                BinaryTreeNode* left_child = NULL,
                BinaryTreeNode* right_child = NULL)
            {
                this->value = value;
                this->left = left_child;
                this->right = right_child;
            }

            T value;
            BinaryTreeNode* left;
            BinaryTreeNode* right;
        };

    BinaryTreeNode* root;
    size_t num_values;

    public:
        ExplicitHeap();
        ~ExplicitHeap();

        bool empty() const override;
        size_t size() const override;
        const T& top() const override;
        void push(const T& value) override;
        void pop() override;
        void clear() override;
};

template<class T, class GreaterEqual>
ExplicitHeap<T, GreaterEqual>::ExplicitHeap()
{
    root = NULL;
    num_values = 0;
}

template<class T, class GreaterEqual>
ExplicitHeap<T, GreaterEqual>::~ExplicitHeap()
{
    clear();
}

template<class T, class GreaterEqual>
bool ExplicitHeap<T, GreaterEqual>::empty() const
{
    return !num_values;
}

template<class T, class GreaterEqual>
size_t ExplicitHeap<T, GreaterEqual>::size() const
{
    return num_values;
}

template<class T, class GreaterEqual>
const T& ExplicitHeap<T, GreaterEqual>::top() const
{
    if(empty()) 
        throw std::logic_error("Cannot call top() on empty priority queue");
        
    return root->value;
}

template<class T, class GreaterEqual>
void ExplicitHeap<T, GreaterEqual>::push(const T& value)
{
    if(empty())
    {
        root = new BinaryTreeNode(value);
    }
    
    else
    {
        // TODO
        
    }

    num_values++;
}

template<class T, class GreaterEqual>
void ExplicitHeap<T, GreaterEqual>::pop()
{
    if(empty()) 
        throw std::logic_error("Cannot call pop() on empty priority queue");

    // TODO
}

template<class T, class GreaterEqual>
void ExplicitHeap<T, GreaterEqual>::clear()
{
    // TODO
}

