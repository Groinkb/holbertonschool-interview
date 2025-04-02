# Advanced Binary Search

This project implements an advanced version of the binary search algorithm that finds the first occurrence of a value in a sorted array of integers.

## Description

The standard binary search algorithm doesn't necessarily return the index of the first occurrence of a value when duplicates are present. This advanced implementation solves that issue by finding the leftmost occurrence of the target value.

## Requirements

- All files will be compiled on Ubuntu 14.04 LTS
- Code compiled with gcc 4.8.4 using flags -Wall -Werror -Wextra and -pedantic
- Code follows the Betty style guide
- No global variables allowed
- Maximum of 5 functions per file
- Only the printf function from the standard library is allowed
- Header file: search_algos.h (include guarded)

## Function Prototype

```c
int advanced_binary(int *array, size_t size, int value);
```

Where:
- `array` is a pointer to the first element of the array to search in
- `size` is the number of elements in the array
- `value` is the value to search for

Return value:
- The index where the value is located (first occurrence)
- -1 if the value is not present in the array or if the array is NULL

## Approach

The implementation uses recursion to find the target value while maintaining these properties:
1. Every time the array is split, the new subarray being searched is printed
2. When a match is found, the algorithm continues searching on the left side to ensure finding the first occurrence
3. Only one loop is used (to print the array), and recursion handles the search logic

## Example

```
$ ./0-advanced_binary
Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 6, 6, 7, 8, 9
Searching in array: 8, 9
Found 8 at index: 8

Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 0, 1, 2, 5, 5
Searching in array: 5, 5
Found 5 at index: 3

Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 6, 6, 7, 8, 9
Searching in array: 8, 9
Searching in array: 9
Found 999 at index: -1
```

## Files

- `0-advanced_binary.c`: Implementation of the advanced binary search algorithm
- `search_algos.h`: Header file containing function prototypes

## Author
BM

