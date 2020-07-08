# Strings

## Abstract Data Type

A **string** is an abstract data type that represents a countable collection of ordered values from a finite set called an _alphabet_. Unlike a list (#REF) (which also represents a collection of ordered values), strings are generally assumed to have information coded not only in the individual characters, but in the ordering of the characters and their relations to each other. 

The string abstract data type is most commonly used to represent text as an ordered collection of characters, but it can also be used to represent a DNA sequence (a collection of base pairs) or morse code (a collection of dots and dashes). 

Many of the operations supported by strings may be specified to their application (for example, unzipping a DNA sequence or translating morse code into text), but strings commonly support the following application:
* `length`: return the number of values in the string
* `lookup`: return the value at a specific position in the string
* `concatenate`: combine two or more strings together
* `substring`: extract a substring

Because the relationships _between_ the values in a string encode information, there are two more common and interrelated types of operations that are performed on strings: extracting information from the string and transforming it into other abstract data types and structures, and searching strings for patterns. For example, we may want to transform a DNA sequence into a collection of genes or search a character string to see if it contains any email addresses. 

The first process - traversing a string in order to process it or extract information - is called **parsing**. The second, searching a string for a pattern, can be thought of as just a specific type of parsing. We may want to search for a specific substring (a direct match), such as specific gene or a known email address; but, just as commonly, we want to search for a substring that matches a more general pattern, just as an email address or a phone number. These can be represented as **regular expressions** (see below), and many string types provide methods to determine if a string matches the pattern represented by a regular expression or contains any substrings that do.

Lastly, string may be either mutable or immutable. In the former case, the string abstract data type will commonly include methods (like a list #REF) for inserting or removing values (or substrings) from the string. Both approaches are common; for example, `C` and `C++` have mutable strings, while `Python`, `Java`, and `C#` have immutable strings.

## Data Structures

Most strings are simply implemented using arrays (or pointers) to arrays (character strings are simply null-terminated character arrays in `C`). Because strings are such a frequently-used data type, vary widely in length, and are often moved, copied, and modified, different implementation will may use different approaches to optimize performance. For example, many `C++` implementations of `std::string` use a "copy-on-write" approach, which uses reference counting to avoid unnecessary copying, and a "short string optimization", which only uses a fixed-size to store smaller strings and dynamically allocated array to store larger ones.

## Algorithms

### Regular Expressions

// TODO

## Examples and Problems

// TODO
implement string class with ref counting
(https://stackoverflow.com/questions/1466073/how-is-stdstring-implemented)
(https://stackoverflow.com/questions/2916358/immutable-strings-vs-stdstring)

* _Cracking the Coding Interview_:
    * Chapter 1 - Arrays and Strings:
        * 1.1 Is Unique (#REF)
        * 1.2 Check Permutation (#REF)
        * 1.3 URLify (#REF)
        * 1.4 Palindrome Permutation (#REF)
        * 1.5 One Away (#REF)
        * 1.6 String Compression (#REF)
        * 1.9 String Rotation (#REF)

## References

"Abstract String / String ADT." Algorithms and Data Structures. Department of Electrincal and Computer Engineering, University of Waterloo. Accessed Junly 7, 2020. https://ece.uwaterloo.ca/~dwharder/aads/Abstract_data_types/Linear_ordering/String/.

McDowell, Gayle Lakkmann. _Cracking the Coding Interview_. 6th ed. Palo Alto, CA: CareerCup, 2016.