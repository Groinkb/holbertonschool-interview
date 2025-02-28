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
 * get_parent - Trouve le parent pour le nouveau nœud
 * @root: Pointeur vers la racine
 * @idx: Index du nœud à insérer
 * Return: Pointeur vers le parent
 */
heap_t *get_parent(heap_t *root, size_t idx)
{
    size_t mask;
    heap_t *parent = root;

    for (mask = 1 << (sizeof(size_t) * 4); mask > 2; mask >>= 1)
    {
        if (!parent)
            break;
        if (idx & mask)
            parent = parent->right;
        else
            parent = parent->left;
    }
    return (parent);
}

/**
 * heap_insert - Insère une valeur dans un Max Binary Heap
 * @root: Double pointeur vers la racine du tas
 * @value: Valeur à insérer
 * Return: Pointeur vers le nœud inséré, ou NULL en cas d'échec
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *current;
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
    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    if (size == 0)
    {
        free(new_node);
        return (NULL);
    }

    current = *root;
    while (size > 1)
    {
        if (size & 1)
            current = current->right;
        else
            current = current->left;
        size >>= 1;
    }

    if (!current->left)
        current->left = new_node;
    else
        current->right = new_node;
    new_node->parent = current;

    current = new_node;
    while (current->parent && current->n > current->parent->n)
    {
        temp = current->n;
        current->n = current->parent->n;
        current->parent->n = temp;
        current = current->parent;
    }

    return (new_node);
}