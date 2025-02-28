#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_size - Mesure la taille d'un arbre binaire
 * @tree: Pointeur vers la racine de l'arbre
 * Return: Taille de l'arbre
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * find_parent - Trouve le parent pour le nouveau nœud
 * @root: Racine de l'arbre
 * @index: Index où insérer le nouveau nœud
 * Return: Pointeur vers le parent
 */
heap_t *find_parent(heap_t *root, size_t index)
{
    size_t mask;

    for (mask = 1 << (31); mask > 1; mask >>= 1)
    {
        if (index & mask)
            break;
    }

    mask >>= 1;
    while (mask > 0 && root)
    {
        if (index & mask)
            root = root->right;
        else
            root = root->left;
        mask >>= 1;
    }
    return (root);
}

/**
 * heap_insert - Insère une valeur dans un Max Binary Heap
 * @root: Double pointeur vers la racine du tas
 * @value: Valeur à insérer
 * Return: Pointeur vers le nœud inséré, ou NULL en cas d'échec
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;
    size_t size;
    int temp;

    if (!root)
        return (NULL);

    if (!*root)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    size = binary_tree_size(*root);
    parent = find_parent(*root, size);

    new_node = binary_tree_node(parent, value);
    if (!new_node)
        return (NULL);

    if (!parent->left)
        parent->left = new_node;
    else
        parent->right = new_node;

    while (new_node->parent && new_node->n > new_node->parent->n)
    {
        temp = new_node->n;
        new_node->n = new_node->parent->n;
        new_node->parent->n = temp;
        new_node = new_node->parent;
    }

    return (new_node);
}