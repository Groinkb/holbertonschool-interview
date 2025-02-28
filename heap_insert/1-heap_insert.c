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
    int temp;

    if (!root)
        return (NULL);

    /* Créer le premier nœud si l'arbre est vide */
    if (!*root)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    /* Trouver la position d'insertion */
    current = *root;
    while (current->left && current->right)
    {
        if (binary_tree_size(current->left) <= binary_tree_size(current->right))
            current = current->left;
        else
            current = current->right;
    }

    /* Créer et insérer le nouveau nœud */
    new_node = binary_tree_node(current, value);
    if (!new_node)
        return (NULL);

    if (!current->left)
        current->left = new_node;
    else
        current->right = new_node;

    /* Remonter le nœud si nécessaire */
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