# File: 00_04_repeated-string.py
# Name: Taylor Curran
# Date: September 21, 2020
# Description:
# HackerRank > Interview Preparation Kit > Warm-up Challenges > Repeated String

"""
Problem: Lilah has a string, 's', of lowercase English letters that she repeated
infinitely many times. Given an integer, 'n', find and print the number of 
letter 'a' in the first 'n' letters of Lilah's infinite string.

For example, if the string s = 'abcac' and n = 10, the substring we consider is 
'abcacabcac, the first 10 characters of her infinite string. There are 4 
occurrences of a in the substring.

Complete the repeatedString function in the editor below. It should return an 
integer representing the number of occurrences of 'a' in the prefix of length 
'n' in the infinitely repeating string.

Parameters:
    - s: a string to repeat
    - n: the number of characters to consider

Contraints:
    - 1 <= |s| <= 100
    - 1 <= n <= 10^12
    - For 25% of the test cases, n <= 10^6

Output: integer denoting the number of letter a's in the first 'n'  letters of 
the infinite string created by repeating 's' infinitely many times.
"""


def repeatedString(s, n):
    quotient = n // len(s)
    remainder = n % len(s)

    a_count = 0
    for index, char in enumerate(s):
        if char == 'a':
            if index < remainder:
                a_count += quotient + 1
            else:
                a_count += quotient
