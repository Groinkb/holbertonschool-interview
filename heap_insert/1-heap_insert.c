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
 * swap_nodes - Échange les valeurs de deux nœuds
 * @a: Premier nœud
 * @b: Second nœud
 */
void swap_nodes(heap_t *a, heap_t *b)
{
    int temp = a->n;
    a->n = b->n;
    b->n = temp;
}

/**
 * heapify_up - Fait remonter un nœud pour maintenir la propriété du tas
 * @node: Nœud à faire remonter
 * Return: Pointeur vers la position finale du nœud
 */
heap_t *heapify_up(heap_t *node)
{
    heap_t *current = node;

    while (current->parent && current->n > current->parent->n)
    {
        swap_nodes(current, current->parent);
        current = current->parent;
    }
    return (current);
}

/**
 * get_last_parent - Trouve le parent du dernier nœud à insérer
 * @size: Taille actuelle du tas
 * @root: Racine du tas
 * Return: Pointeur vers le parent du prochain nœud
 */
heap_t *get_last_parent(size_t size, heap_t *root)
{
    size_t mask;
    heap_t *parent = root;

    for (mask = 1 << ((sizeof(size_t) * 8) - 1); mask > 1; mask >>= 1)
    {
        if (size & mask)
            parent = parent->right;
        else if (mask > 2)
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
    heap_t *new_node, *parent;
    size_t size;

    if (!root)
        return (NULL);

    if (!*root)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    size = binary_tree_size(*root);
    parent = get_last_parent(size + 1, *root);

    new_node = binary_tree_node(parent, value);
    if (!new_node)
        return (NULL);

    if (!parent->left)
        parent->left = new_node;
    else
        parent->right = new_node;

    return (heapify_up(new_node));
}