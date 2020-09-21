/**
 * @file 16-2.cpp
 * @author Taylor Curran
 * @brief Solution to problem 16.2 from Cracking the Coding Interview
 * @version 0.1
 * @date August 29, 2020
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 */

/* Problem <16.2: "Word Frequencies: Design a method to find the frequency of 
occurences of any given word in a book. What if we were running this algorithm 
multiple times?" */

/* Approach: 

Search book for occurences of first letter. When each one is encountered, check
if the string that follows equals the word. */

#include <cassert> // assert
#include <cstring> // strcpy
#include <iostream> // std::cout, std::endl;

/**
 * @brief Returns the number of occurences of \p word in \p book
 * 
 * @param word 
 * @param book 
 * @return int 
 */
int countOccurences(char* word, char* book)
{
    // Empty word or book
    if (!word || !book)
        return 0;

    // Get size of word
    size_t w_sz = 0;
    while (word[w_sz] != '\0')
        w_sz++;

    int count = 0;

    // Search book for first letter
    size_t i = 0;
    while (book[i] != '\0') {
        if (book[i] == word[0])
            if (!strncmp(book + i, word, w_sz))
                count++;
        i++;
    }

    return count;
}

int main()
{
    std::cout << "\nBeginning tests..." << std::endl;

    char word[5];
    char book[100];

    // Empty book
    strcpy(word, "a");
    strcpy(book, "");
    assert(countOccurences(word, book) == 0);

    // Empty word
    strcpy(word, "");
    strcpy(book, "a");
    assert(countOccurences(word, book) == 0);

    // One letter word
    strcpy(word, "a");
    strcpy(book, "abc");
    assert(countOccurences(word, book) == 1);

    // Repeated word
    strcpy(word, "a");
    strcpy(book, "abab");
    assert(countOccurences(word, book) == 2);

    // Overlapping words
    strcpy(word, "aa");
    strcpy(book, "aaaaa");
    assert(countOccurences(word, book) == 4);

    // Word longer than book
    strcpy(word, "");
    strcpy(book, "");
    assert(countOccurences(word, book) == 0);

    // Part of word at end of book
    strcpy(word, "cd");
    strcpy(book, "abc");
    assert(countOccurences(word, book) == 0);

    // Actual sentence
    strcpy(word, "the");
    strcpy(book, "the problem with the radical left is the absence of God...");
    assert(countOccurences(word, book) == 3);

    // Word not found
    strcpy(word, "a");
    strcpy(book, "bcd");
    assert(countOccurences(word, book) == 0);

    std::cout << "All tests passed!" << std::endl;
    exit(0);
}