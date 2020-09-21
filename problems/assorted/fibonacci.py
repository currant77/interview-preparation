"""
@file: fionacci.py
@author: Taylor Curran
@brief: Solution to problem on UrtheCast job application
@version 0.1
@date 2020-08-17

@copyright Copyright (c) 2020
"""

"""
Problem: "Write a function that calculates the nth Fibonacci number in O(n)
time or better without using any 'for' or 'while' loops."

/* Approach:

Fibonacci numbers:
F_0 = 0
F_1 = 1
F_n = F_n-1 + F_n-2, where n > 1

The nth Fibonacci number can be calculated using dynamic programming, where
each intermediate value is stored in an array. Use a recursive function.
"""

""" 
While the nth Fibonacci number can be calculated in only a couple lines by
looking up a formula, I assumed that was not what you were looking for! The 
solution below is recursive, uses dynamic programming, and has runtime O(n)
"""


def fibonacci(n):
    results = [None] * (n+1)
    return fib_helper(n, results)


def fib_helper(n, results):
    if results[n] != None:
        return results[n]
    elif n == 0:
        results[0] = 0
        return results[0]
    elif n == 1:
        results[1] = 1
        return results[1]
    else:
        results[n] = fib_helper(n-2, results) + fib_helper(n-1, results)
        return results[n]


print("\nBeginning tests...")

assert fibonacci(0) == 0
assert fibonacci(1) == 1
assert fibonacci(2) == 1
assert fibonacci(3) == 2
assert fibonacci(4) == 3
assert fibonacci(5) == 5
assert fibonacci(6) == 8
assert fibonacci(7) == 13
assert fibonacci(19) == 4181
assert fibonacci(37) == 24157817

print("All tests passed!")
