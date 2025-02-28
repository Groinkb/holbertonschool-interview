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
 * @index: Index du nœud actuel
 * Return: Pointeur vers le parent
 */
heap_t *get_parent(heap_t *root, size_t index)
{
    size_t parent_idx;
    size_t mask;

    /* Trouver le parent en utilisant l'index */
    for (mask = 1; mask <= index; mask <<= 1)
        ;
    mask >>= 2;

    for (parent_idx = index; mask > 0; mask >>= 1)
        parent_idx = ((index & mask) ? parent_idx | mask : parent_idx & ~mask);

    /* Parcourir l'arbre jusqu'au parent */
    for (mask = 1; mask <= parent_idx; mask <<= 1)
        ;
    mask >>= 2;

    while (mask > 0 && root != NULL)
    {
        root = (parent_idx & mask) ? root->right : root->left;
        mask >>= 1;
    }

    return (root);
}

/**
 * swap_with_parent - Échange un nœud avec son parent si nécessaire
 * @node: Pointeur vers le nœud à échanger
 * Return: Pointeur vers la position finale du nœud
 */
heap_t *swap_with_parent(heap_t *node)
{
    heap_t *parent;
    heap_t *temp_left, *temp_right, *temp_parent;

    while (node->parent && node->n > node->parent->n)
    {
        parent = node->parent;
        temp_parent = parent->parent;
        temp_left = node->left;
        temp_right = node->right;

        /* Ajuster les liens avec le parent du parent */
        if (temp_parent)
        {
            if (temp_parent->left == parent)
                temp_parent->left = node;
            else
                temp_parent->right = node;
        }

        /* Échanger les liens entre parent et node */
        if (parent->left == node)
        {
            node->right = parent->right;
            node->left = parent;
            if (parent->right)
                parent->right->parent = node;
        }
        else
        {
            node->left = parent->left;
            node->right = parent;
            if (parent->left)
                parent->left->parent = node;
        }

        /* Mettre à jour les liens du parent */
        parent->parent = node;
        parent->left = temp_left;
        parent->right = temp_right;
        if (temp_left)
            temp_left->parent = parent;
        if (temp_right)
            temp_right->parent = parent;

        /* Mettre à jour le parent du node */
        node->parent = temp_parent;
    }
    return (node);
}

/**
 * heap_insert - Insère une valeur dans un Max Binary Heap
 * @root: Double pointeur vers la racine du tas
 * @value: Valeur à insérer
 * Return: Pointeur vers le nœud inséré, ou NULL en cas d'échec
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node;
    heap_t *parent;
    size_t size;

    /* Si l'arbre est vide, créer la racine */
    if (*root == NULL)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    /* Calculer la taille de l'arbre */
    size = binary_tree_size(*root);

    /* Trouver le parent du nouveau nœud */
    parent = get_parent(*root, size);

    /* Créer le nouveau nœud */
    new_node = binary_tree_node(parent, value);
    if (new_node == NULL)
        return (NULL);

    /* Attacher le nouveau nœud au parent */
    if (parent->left == NULL)
        parent->left = new_node;
    else
        parent->right = new_node;

    /* Remonter le nœud si nécessaire pour maintenir la propriété du tas */
    new_node = swap_with_parent(new_node);
    if (new_node->parent == NULL)
        *root = new_node;

    return (new_node);
}
