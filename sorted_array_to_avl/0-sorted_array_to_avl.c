#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * create_node - Creates a new AVL tree node
 *
 * @n: Value to be stored in the node
 * Return: Pointer to the newly created node, or NULL on failure
 */
avl_t *create_node(int n)
{
    avl_t *new_node;

    new_node = malloc(sizeof(avl_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}

/**
 * build_avl - Recursively builds an AVL tree from a sorted array
 *
 * @array: Pointer to the first element of the array
 * @start: Starting index of the current sub-array
 * @end: Ending index of the current sub-array
 * @parent: Pointer to the parent node
 * Return: Pointer to the root of the created AVL tree, or NULL on failure
 */
avl_t *build_avl(int *array, size_t start, size_t end, avl_t *parent)
{
    avl_t *root;
    size_t mid;

    /* Base case */
    if (start > end || array == NULL)
        return (NULL);

    /* Get the middle element and make it root */
    mid = (start + end) / 2;

    /* Create the node */
    root = create_node(array[mid]);
    if (root == NULL)
        return (NULL);

    /* Set parent */
    root->parent = parent;

    /* Recursively build left subtree
     * Be careful with unsigned values when subtracting */
    if (mid > start)
        root->left = build_avl(array, start, mid - 1, root);
    else
        root->left = NULL;

    /* Recursively build right subtree */
    root->right = build_avl(array, mid + 1, end, root);

    return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 *
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return (NULL);

    return (build_avl(array, 0, size - 1, NULL));
}