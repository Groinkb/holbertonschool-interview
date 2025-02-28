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
 * binary_tree_is_perfect - Vérifie si un arbre binaire est parfait
 * @tree: Pointeur vers la racine de l'arbre
 * Return: 1 si parfait, 0 sinon
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t left_size, right_size;

    if (tree == NULL)
        return (0);

    left_size = binary_tree_size(tree->left);
    right_size = binary_tree_size(tree->right);

    return (left_size == right_size);
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

    if (!root)
        return (NULL);

    if (!*root)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    current = *root;
    while (current)
    {
        if (!current->left)
            break;
        if (!current->right)
            break;
        if (binary_tree_is_perfect(current->left))
            current = current->right;
        else
            current = current->left;
    }

    new_node = binary_tree_node(current, value);
    if (!new_node)
        return (NULL);

    if (!current->left)
        current->left = new_node;
    else
        current->right = new_node;

    while (new_node->parent && new_node->n > new_node->parent->n)
    {
        int temp = new_node->n;
        new_node->n = new_node->parent->n;
        new_node->parent->n = temp;
        new_node = new_node->parent;
    }

    return (new_node);
}