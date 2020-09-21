"""
@file: list-merge.py
@author: Taylor Curran
@brief: Solution to UrtheCast job application question
@version 0.1
@date 2020-08-17

@copyright Copyright (c) 2020
"""

"""
Problem: "Write an immutable function that merges the following inputs
into a single list:

Inputs
- Original list of strings
- List of strings to be added
- List of strings to be removed

Return
- List shall only contain unique values
- List shall be ordered as follows
--- Most character count to least character count
--- In the event of a tie, reverse alphabetical

Other Notes
- You can use any programming language you like
- The function you submit shall be runnable

For example:

Original List = ['one', 'two', 'three',]
Add List = ['one', 'two', 'five', 'six]
Delete List = ['two', 'five']
Result List = ['three', 'six', 'one']
"""

"""
Approach:

(0) Copy the lists
(1) Sort the lists in reverse alphabetical order
(2) Step through all three lists at the same time, adding elements to a new
list one-by-one (if they are in either the original or add list but not in the
delete list)
(3) Sort the list by character count
"""

# Solution


def merge_list(orig, add, delete):

    # Copy lists (combine orig and add)
    insert = orig + add
    remove = list(delete)

    # Sort lists reverse alphabetically
    insert.sort(reverse=True)
    remove.sort(reverse=True)

    # Add items to merged list in order
    merged = []
    ii = 0           # Insert index
    ri = 0           # Remove index

    while ii < len(insert):

        while ri < len(remove) and remove[ri] > insert[ii]:
            ri += 1

        # Insert value into list if:
        #   - It is not a duplicate (already in merged)
        #   - It is not in remove list

        if (ri >= len(remove) or insert[ii] != remove[ri]) and \
                (len(merged) == 0 or merged[len(merged) - 1] != insert[ii]):
            merged.append(insert[ii])

        ii += 1

    # Sort by number of characters (descending)
    # (Python sort is stable)
    merged.sort(reverse=True, key=len)

    return merged

# Tests


print("\nBeginning tests...")

orig = []
add = []
delete = []
assert merge_list(orig, add, delete) == []

orig.append('one')
assert merge_list(orig, add, delete) == ['one']

add.append('one')
assert merge_list(orig, add, delete) == ['one']

delete.append('two')
assert merge_list(orig, add, delete) == ['one']

add.append('two')
assert merge_list(orig, add, delete) == ['one']

delete.append('one')
assert merge_list(orig, add, delete) == []

orig.append('two')
orig.append('three')
assert merge_list(orig, add, delete) == ["three"]

orig = ['one', 'two', 'three', ]
add = ['one', 'two', 'five', 'six']
delete = ['two', 'five']
assert merge_list(orig, add, delete) == ['three', 'six', 'one']

delete.remove('five')
assert merge_list(orig, add, delete) == ['three', 'five', 'six', 'one']

orig.append('ten')
assert merge_list(orig, add, delete) == ['three', 'five', 'ten', 'six', 'one']

print("All tests passed!")
