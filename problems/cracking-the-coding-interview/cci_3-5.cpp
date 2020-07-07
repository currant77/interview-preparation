/**
 * @file cci_3-5.cpp
 * @author Taylor Curran
 * @brief Solution to problem 3.5 from Cracking the Coding Interview
 * @version 0.1
 * @date 2020-07-06
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 */

/* Problem 3.5: "Sort Stack: Write a progam to sort a stack such that the 
smallest items are on the top. You can use an additional temporary stack, 
but you may not copy the element into any oth data structure. The stack 
supports the following operations: push(), pop(), peek(), and isEmpty() */

/* Approach: Use the second stack to order value from smallest to largest.
When removing each value from the first stack, transfer values from second
back to first until the right spot to insert value. */

#include <stack>        // std::stack
#include <vector>       // std::vector
#include <cassert>      // assert
#include <iostream>     // std::cout, std::endl;

template<class T>
void sort_stack(std::stack<T>& stack)
{
    std::stack<T> helper;

    // Transfer value to helper so than max is on top
    while(!stack.empty())
    {
        T value = stack.top();
        stack.pop();

        /* Transfer items from helper back to stack
        until we find an item that is not larger than `value` */
        while(!helper.empty() && helper.top() > value)
        {
            stack.push(helper.top());
            helper.pop();   
        }

        helper.push(value);

        // Transfer values from stack to helper 
        while(
            helper.empty() || 
            (!stack.empty() && stack.top() >= helper.top()))
        {
            helper.push(stack.top());
            stack.pop();   
        }
    }

    // Transfer back to stack
    while(!helper.empty())
    {
        stack.push(helper.top());
        helper.pop();
    }
}

template<class T>
bool compare_stack(std::stack<T>& stack, const std::vector<T>& compare)
{
    if(stack.size() != compare.size())
        return false;

    std::stack<T> temp;

    for(auto it = compare.cbegin(); it != compare.cend(); ++it)
    {
        if(stack.top() != *it)
            return false;

        temp.push(stack.top());
        stack.pop();
    }

    // Transfer values back
    while(!temp.empty())
    {
        stack.push(temp.top());
        temp.pop();
    }

    return true;    
}

int main()
{
    std::cout << std::endl << "Beginning tests..." << std::endl; 

    std::stack<int> s1;
    sort_stack(s1);                                  // [] -> []
    assert(compare_stack(s1, {}));

    s1.push(1);                                      // top -> [1]
    s1.push(2);                                      // top -> [2,1]
    sort_stack(s1);                                  // [2,1] -> [1,2]
    assert(compare_stack<int>(s1, {1,2}));
    sort_stack(s1);                      
    assert(compare_stack<int>(s1, {1,2}));

    s1.push(5);                                      // top -> [5,1,2]
    s1.push(4);                                      // top -> [4,5,1,2]
    s1.push(7);                                      // top -> [7,4,5,1,2]
    sort_stack(s1);                                  // [7,4,5,1,2] -> [1,2,4,5,7]
    assert(compare_stack<int>(s1, {1,2,4,5,7}));

    s1.push(6);                                      // top -> [6,1,2,4,5,7]
    sort_stack(s1);                                  // [6,1,2,4,5,7] -> [1,2,4,5,6,7]
    assert(compare_stack<int>(s1, {1,2,4,5,6,7}));

    std::stack<char> s2;                            // top -> []
    s2.push('a');                                   // top -> [a]
    s2.push('z');                                   // top -> [z,a]
    s2.push('c');                                   // top -> [c,z,a]
    s2.push('b');                                   // top -> [b,c,z,a]
    s2.push('c');                                   // top -> [c,b,c,z,a]
    s2.push('f');                                   // top -> [f,c,b,c,z,a]    

    sort_stack(s2);                                 // [f,c,b,c,z,a] -> [a,b,c,c,f,z]
    assert(compare_stack<char>(s2, {'a','b','c','c','f','z'}));

    std::cout << "All tests passed!" << std::endl;
    exit(0); 
}