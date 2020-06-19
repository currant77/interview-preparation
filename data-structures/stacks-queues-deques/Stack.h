/**
 * @file Stack.h
 * @author Taylor Curran
 * @brief Stack with basic functionality.
 * @version 0.1
 * @date 2020-06-19
 * 
 * @note  Implemented as a wrapper to ArrayList
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef STACK_H
#define STACK_H

#include "../lists/ArrayList.h"

/**
 * @brief Stack of values of type T
 * @tparam T - template parameter
 */
template<class T>
class Stack
{
    public:
        Stack();
        ~Stack();

        bool empty() const;
        size_t size() const;

        /**
         * @brief Returns a reference to the value at the 
         * top of the stack
         * @return T& - reference to value at the top of 
         * the stack
         */
        T& top();

        /**
         * @brief Returns a const reference to the value 
         * at the  top of the stack
         * @return const T& - const reference to value at the 
         * top of the stack
         */
        const T& top() const;

        /**
         * @brief Insert \p value at the top of the stack
         * @param value - value to insert
         */
        void push(const T& value);

        /**
         * @brief Removes the top value from the stack
         * @throw std::invalid_argument if stack is empty
         */
        void pop();

        /**
         * @brief Clear all values from the stack
         */
        void clear();

    private:
        ArrayList<T> list;
};

template<class T>
Stack<T>::Stack()
{
    
}

template<class T>
Stack<T>::~Stack()
{

}

template<class T>
bool Stack<T>::empty() const
{
    return list.empty();
}

template<class T>
size_t Stack<T>::size() const
{
    return list.size();
}

template<class T>
T& Stack<T>::top()
{
    return list[0];
}

template<class T>
const T& Stack<T>::top() const
{
    return list[0];
}

template<class T>
void Stack<T>::push(const T& value)
{
    list.push_back(value);
}

template<class T>
void Stack<T>::pop()
{
    list.pop_front();
}

template<class T>
void Stack<T>::clear()
{
    list.clear();
}


#endif