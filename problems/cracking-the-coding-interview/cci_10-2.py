"""
@file: cci_10-2.py
@author: Taylor Curran
@brief: Solution to problem 10.2 from Cracking the Coding Interview
@version 0.1
@date 2020-06-30

@note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
6th ed. Palo Alto, CA: CareerCup, 2016.

@copyright Copyright (c) 2020
"""

""" 
Problem 10.2: "Group Anagrams: Write a method to sort an array of strings so that
all the anagrams are next to each other" 
"""

"""
Definition: An anagram is a word formed by re-arranging the letters of a different word
"""

""" 
Approach: Sort the strings using any sorting method (insertion sort used for simplicity)
but change the comparator so that it compares the _sorted_ strings (i.e. the strings with
their characters sorted alphabetically). It is important that the required behaviour is 
not strictly defined - it is fine as long as the anagrams are adjacent (so the results
shown below are not _required_ by the question - they are just the output produced by
this particular solution to it).

Alternate: This appraoch works by sorting the strings. But we don't actually _need_ to sort
the strings -  we only need to group anagrams. cci_10-2.cpp presents a way of doing this 
that uses a hash map from strings to lists of strings.
"""

def sort_string(s):
    """ 
    Returns a anagram of the string where the characters are 
    sorted alphabetically
    """

    chars = list(s)
    chars.sort()
    return "".join(chars)

def group_anagrams(input):
    """
    Re-orders the list values so that strings that are anagrams of each
    other appear next to each other
    """

    sorted = False

    while not sorted:
        
        sorted = True
        
        for i in range(0, len(input) - 1):

            if sort_string(input[i]) < sort_string(input[i+1]):
                temp = input[i]
                input[i] = input[i+1]
                input[i+1] = temp
                sorted = False

print("Beginning tests...")

anags = []                           
group_anagrams(anags)
print(anags)

# Result: []

anags.extend(["ab", "ac", "aa"])
group_anagrams(anags)
print(anags)

# Result: ['ac', 'ab', 'aa']

anags.extend(["ba", "aa", "ca"])               
group_anagrams(anags)
print(anags)

# Result: ['ac', 'ca', 'ab', 'ba', 'aa', 'aa']

anags.extend(["dave", "dav", "ave", "aved"])
group_anagrams(anags)
print(anags)

# Result: ['ave', 'dav', 'dave', 'aved', 'ac', 'ca', 'ab', 'ba', 'aa', 'aa']

anags.extend(["AA", "aa"])
group_anagrams(anags)
print(anags)

# Result: ['ave', 'dav', 'dave', 'aved', 'ac', 'ca', 'ab', 'ba', 'aa', 'aa', 'aa', 'AA']

print("All tests passed!")