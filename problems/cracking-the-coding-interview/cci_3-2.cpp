/**
 * @file cci_3-2.cpp
 * @author Taylor Curran
 * @brief Solution to problem 3.2 from Cracking the Coding Interview
 * @version 0.1
 * @date 2020-07-06
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 */

/* Problem 3.2: "Stack Min: How would you design a stack which, in addition to push()
and pop(), has a function min() which returns the minimum element? Push(), pop(), and
min() should all operate in O(1) time."*/

/* Approach: Each stack node will store the following values: the data for that node,
and the minimum value of the 'substack' that it is at the top of. */

#include <cassert>      // assert
#include <iostream>     // std::cout, std::endl;
#include <stdexcept>    // std::invalid_argument

// Classes and structs
template<class T>
class MinStack
{
    private:
        struct MinStackNode
        {
            T data;
            T substackMin;
            MinStackNode* below;
        };

        MinStackNode* top_node;        

    public:
        MinStack() : top_node(NULL) {}
        
        ~MinStack()
        {
            clear();
        }

        const T& top() const
        {
            if(!top_node)
                throw std::invalid_argument("Cannot call top() on empty stack");

            return top_node->data;
        }
        
        const T& min() const
        {
            if(!top_node)
                throw std::invalid_argument("Cannot call min() on empty stack");

            return top_node->substackMin;  
        }

        void push(const T& value)
        {
            top_node = new MinStackNode{value, value, top_node};
            
            if(top_node->below && top_node->below->data < top_node->substackMin)
                top_node->substackMin = top_node->below->substackMin;
        }

        void pop()
        {
            if(!top_node)
                throw std::invalid_argument("Cannot call pop() on empty stack");  
            
            MinStackNode* ptr = top_node;

            if(top_node)
                top_node = top_node->below;
            else
                top_node = NULL;

            delete ptr;
        }
        
        void clear()
        {
            MinStackNode* ptr;
            while(top_node)
            {
                ptr = top_node;
                top_node = top_node->below;
                delete ptr;
            }
        }
};

int main()
{
    std::cout << std::endl << "Beginning tests..." << std::endl; 

    MinStack<int> ms;

    // Insert values
    ms.push(5);                         // [5]
    assert(ms.top() == 5);
    assert(ms.min() == 5);  

    ms.push(2);                         // 5->[2]
    assert(ms.top() == 2);
    assert(ms.min() == 2); 

    ms.push(2);                         // 5->[2]->2
    assert(ms.top() == 2);
    assert(ms.min() == 2); 

    ms.push(1);                         // 5->2->2->[1]
    assert(ms.top() == 1);
    assert(ms.min() == 1); 

    ms.push(4);                         // 5->2->2->[1]->4
    assert(ms.top() == 4);
    assert(ms.min() == 1); 

    // Remove values
    ms.pop();                           // 5->2->2->[1]
    ms.pop();                           // 5->[2]->2
    ms.pop();                           // 5->[2]
    ms.push(0);                         // 5->2->[0]
    ms.push(1);                         // 5->2->[0]->1
    assert(ms.top() == 1);
    assert(ms.min() == 0);

    // Clear and errors
    ms.clear();

    try
    {
        ms.min();
        assert(false);
    }
    catch(const std::invalid_argument& e) {}

    try
    {
        ms.top();
        assert(false);
    }
    catch(const std::invalid_argument& e) {}

    try
    {
        ms.pop();
        assert(false);
    }
    catch(const std::invalid_argument& e) {}

    std::cout << "All tests passed!" << std::endl;
    exit(0); 
}