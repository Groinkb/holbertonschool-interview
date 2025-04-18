# Heap Extract

This project implements a function to extract the root node from a Max Binary Heap.

## Description

The main function `heap_extract` extracts the root node (which contains the maximum value) from a Max Binary Heap, replaces it with the last level-order node, and reorganizes the heap to maintain the Max Heap property.

## Requirements

* All files will be compiled on Ubuntu 14.04 LTS
* Programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
* The code follows the Betty style
* No global variables are used
* No more than 5 functions per file
* The standard library is used

## Files

* `0-heap_extract.c`: Contains the implementation of the heap_extract function
* `binary_trees.h`: Header file with function prototypes and data structure definitions

## Data Structures

```c
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;
```

## Function Prototype

```c
int heap_extract(heap_t **root);
```

## Algorithm

The implementation follows these steps:
1. Extract the root value (maximum value in the heap)
2. Find the last level-order node of the heap
3. Replace the root node value with the value of the last node
4. Remove the last node from the heap
5. Restore the heap property by sifting down the new root value
6. Return the extracted value

## Complexity

* Time Complexity: O(log n) where n is the number of nodes in the heap
* Space Complexity: O(1) as no extra data structures are used

## Author

BM