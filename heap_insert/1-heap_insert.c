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
 * heap_insert - Insère une valeur dans un Max Binary Heap
 * @root: Double pointeur vers la racine du tas
 * @value: Valeur à insérer
 * Return: Pointeur vers le nœud inséré, ou NULL en cas d'échec
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *current;
    size_t size;

    if (!root)
        return (NULL);

    if (!*root)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    size = binary_tree_size(*root);
    current = *root;

    /* Trouver la position d'insertion en utilisant la représentation binaire de size + 1 */
    size++;
    for (size >>= 1; size > 0; size >>= 1)
    {
        if (size & 1)
            current = current->right;
        else
            current = current->left;
    }

    /* Remonter d'un niveau pour trouver le parent */
    current = current->parent;
    new_node = binary_tree_node(current, value);
    if (!new_node)
        return (NULL);

    if (!current->left)
        current->left = new_node;
    else
        current->right = new_node;

    /* Remonter le nœud si nécessaire */
    while (new_node->parent && new_node->n > new_node->parent->n)
    {
        int temp = new_node->n;
        new_node->n = new_node->parent->n;
        new_node->parent->n = temp;
        new_node = new_node->parent;
    }

    return (new_node);
}