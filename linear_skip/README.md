# Linear Search in a Skip List

## Overview
This project implements a `linear_skip` function that searches for a value in a sorted skip list of integers. A skip list is a data structure that allows for faster search within an ordered sequence of elements by using "express lanes" - shortcuts that skip multiple elements to reach distant parts of the list in fewer steps.

## Description of a Skip List
A skip list is a probabilistic data structure that allows `O(log n)` average complexity for search operations, similar to a binary search tree. The structure maintains multiple layers of linked lists, with the bottom layer containing all elements, and each higher layer acting as an "express lane" for the layer below, allowing for skipping multiple elements at once during search.

## Implementation Details
The `linear_skip` function implements the following algorithm:
1. First, it uses the express lane to find a range of nodes where the value might exist.
2. Then, it performs a standard linear search within this range.
3. At each step, it prints the values being checked as required.

The function follows the required prototype:
```c
skiplist_t *linear_skip(skiplist_t *list, int value);
```

### Time Complexity
The time complexity of this implementation is O(sqrt(n)) in the average case, where n is the number of nodes in the list. This is because:
- Express lane traversal takes O(sqrt(n)) steps in the worst case
- The subsequent linear search also takes O(sqrt(n)) steps in the worst case

### Space Complexity
The space complexity is O(1) as we only use a constant amount of extra space regardless of the input size.

## Requirements
- Allowed editors: vi, vim, emacs
- Compiled on Ubuntu 14.04 LTS with gcc 4.8.4
- Code follows the Betty style guide
- No more than 5 functions per file
- No global variables

## Files
- `0-linear_skip.c`: Contains the implementation of the linear_skip function
- `search.h`: Header file with function prototypes and data structures

## Usage
```c
skiplist_t *result = linear_skip(list, value);
```
- If `value` is found, returns a pointer to the first node where `value` is located
- If `value` is not in the list or if `list` is NULL, returns NULL