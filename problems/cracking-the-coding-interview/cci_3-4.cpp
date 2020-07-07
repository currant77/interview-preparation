/**
 * @file cci_3-4.cpp
 * @author Taylor Curran
 * @brief Solution to problem 3.4 from Cracking the Coding Interview
 * @version 0.1
 * @date 2020-07-06
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 */

/* Problem 3.4: "Queue via Stacks: Implement a `MyQueue` class which 
implements a queue using two stacks." */

/* Approach: Maintain two stacks. One stack holds the `oldest` value at the bottom; 
when we want to access it, we moves all the values above it to `newest`, and move
then back when needed. */

#include <cassert>      // assert
#include <iostream>     // std::cout, std::endl;
#include <stack>        // std:: stack

template<class T>
class StackQueue
{
    private:
        std::stack<T> oldest;
        std::stack<T> newest;

        /**
         * @brief Shifts all but last element
         * from `oldest` to `newest`
         * 
         */
        void shiftOver()
        {
            while(oldest.size() > 1)
            {
                newest.push(oldest.top());
                oldest.pop();
            }            
        }

        void shiftBack()
        {
            while(!newest.empty())
            {
                oldest.push(newest.top());
                newest.pop();
            }
        }

    public:
        bool empty() const
        {
            return oldest.empty() && newest.empty();
        }

        size_t size() const
        {
            return oldest.size() + newest.size();
        }

        T& front()
        {
            shiftOver();
            return oldest.top();
        }
        
        const T& top() const
        {
            return top();
        }

        T& back()
        {
            shiftBack();
            return oldest.top();
        }

        const T& back() const
        {
            return back();
        }

        void push(const T& value)
        {
            shiftBack();
            oldest.push(value);
        }

        void pop()
        {
            shiftOver();
            oldest.pop();

            if(!newest.empty())
            {
                oldest.push(newest.top());
                newest.pop();
            }
        }
};

int main()
{
    std::cout << std::endl <<"Beginning tests..." << std::endl; 

    // Using tests from tst_Queue.cpp

    StackQueue<int> q;

    assert(q.empty());
    assert(!q.size());

    // Insert items
    q.push(1);                  // 1
    assert(q.front() == 1);
    assert(q.back() == 1);
    
    q.push(5);                  // 1 < 5
    assert(q.back() == 5);

    q.push(12);                 // 1 < 5 < 12
    assert(q.back() == 12);
    assert(q.front() == 1);
    assert(q.size() == 3);

    // Remove items
    q.pop();                    // 5 < 12
    assert(q.front() == 5);
    assert(q.back() == 12);

    q.pop();                    // 12
    assert(q.front() == 12);
    assert(q.back() == 12);
    assert(q.size());

    q.pop();                    // empty
    assert(q.empty());

    std::cout << "All tests passed!" << std::endl;
    exit(0); 
}