#include "binary_trees.h"
#include <limits.h>

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
int left_height;
int right_height;

if (tree == NULL)
return (0);

left_height = height(tree->left);
right_height = height(tree->right);

if (left_height > right_height)
return (left_height + 1);
return (right_height + 1);
}

/**
 * is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value nodes can have
 * @max: Maximum value nodes can have
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
if (tree == NULL)
return (1);

    /* Check if current node's value is within the valid range */
if (tree->n <= min || tree->n >= max)
return (0);

    /* Recursively check left and right subtrees */
return (is_bst(tree->left, min, tree->n) &&
is_bst(tree->right, tree->n, max));
}

/**
 * is_balanced - Checks if a binary tree is height-balanced
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if balanced, 0 otherwise
 */
int is_balanced(const binary_tree_t *tree)
{
int left_height;
int right_height;
int balance_factor;

if (tree == NULL)
return (1);

left_height = height(tree->left);
right_height = height(tree->right);

    /* Get the balance factor */
if (left_height > right_height)
balance_factor = left_height - right_height;
else
balance_factor = right_height - left_height;

    /* If balance factor is more than 1, tree is not balanced */
if (balance_factor > 1)
return (0);

    /* Recursively check if left and right subtrees are balanced */
return (is_balanced(tree->left) && is_balanced(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

    /* Check if it's a BST */
if (!is_bst(tree, INT_MIN, INT_MAX))
return (0);

    /* Check if it's balanced */
if (!is_balanced(tree))
return (0);

return (1);
}