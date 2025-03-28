# AVL Trees

This project implements a function to check if a binary tree is a valid AVL Tree.

## Requirements

### General
- Allowed editors: `vi`, `vim`, `emacs`
- All files will be compiled on Ubuntu 14.04 LTS
- Programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall`, `-Werror`, `-Wextra`, and `-pedantic`
- All files should end with a new line
- Code should use the Betty style
- No global variables are allowed
- No more than 5 functions per file
- The standard library is allowed
- Prototypes of all functions are included in the header file `binary_trees.h`
- Header files are include guarded

## Data Structures

The following data structures are used for binary trees:

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
typedef struct binary_tree_s avl_t;
```

## Task: Is AVL

### Description
Write a function that checks if a binary tree is a valid AVL Tree.

### Prototype
```c
int binary_tree_is_avl(const binary_tree_t *tree);
```

### Parameters
- `tree`: A pointer to the root node of the tree to check

### Return Value
- `1` if the tree is a valid AVL Tree
- `0` otherwise
- If `tree` is `NULL`, return `0`

### Properties of an AVL Tree
- An AVL Tree is a BST (Binary Search Tree)
- The difference between heights of left and right subtrees cannot be more than one
- The left and right subtree each must also be a binary search tree

## Algorithm Approach

The implementation uses the following approach to check if a binary tree is a valid AVL Tree:

1. First, check if the tree is a valid Binary Search Tree (BST)
   - For each node, ensure its value is greater than all values in its left subtree and less than all values in its right subtree

2. Then, verify the AVL property (balance)
   - Calculate the height of left and right subtrees
   - Ensure the difference between heights is at most 1
   - Recursively check if all subtrees are also balanced

3. Return `1` only if both conditions are met, `0` otherwise

The solution uses helper functions to:
- Calculate the height of a tree
- Check if a tree is a valid BST
- Check if a tree is height-balanced

This implementation ensures correct validation of AVL Trees according to their formal definition.

## Author
BM
