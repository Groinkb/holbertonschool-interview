# Sorted Array to AVL Tree

## Description
This project contains a function that builds an AVL (Adelson-Velsky and Landis) tree from a sorted array. An AVL tree is a self-balancing binary search tree where the height difference between the left and right subtrees of any node is at most 1.

## Task
Write a function that builds an AVL tree from a sorted array

* Prototype: `avl_t *sorted_array_to_avl(int *array, size_t size);`
* Where `array` is a pointer to the first element of the array to be converted
* And `size` is the number of elements in the array
* The function must return a pointer to the root node of the created AVL tree, or NULL on failure
* There will be no duplicate values in the array
* Rotations are not allowed
* Only 3 functions are allowed in the file

## Approach
The implementation uses a recursive strategy to build a balanced AVL tree:
1. Choose the middle element of the array as the root
2. Recursively build the left subtree with elements before the middle
3. Recursively build the right subtree with elements after the middle
4. This approach ensures the tree is balanced without explicit rotations

## Files
* `0-sorted_array_to_avl.c`: Implementation of the function to convert sorted array to AVL
* `binary_trees.h`: Header file with necessary function prototypes and data structures

## Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-sorted_array_to_avl.c -o 0-sorted_array_to_avl
```

## Usage
```bash
./0-sorted_array_to_avl
```

## Example
```
Input array: [1, 2, 20, 21, 22, 32, 34, 47, 62, 68, 79, 84, 87, 91, 95, 98]

Output AVL tree:
                 .-----------------(047)-----------------.
       .-------(021)-------.                   .-------(084)-------.
  .--(002)--.         .--(032)--.         .--(068)--.         .--(091)--.
(001)     (020)     (022)     (034)     (062)     (079)     (087)     (095)--.
                                                                           (098)
```

## Author
[BM]