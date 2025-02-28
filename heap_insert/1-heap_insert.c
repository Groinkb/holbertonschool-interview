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
 * get_last_node - Trouve la position du dernier nœud
 * @root: Pointeur vers la racine
 * @size: Taille de l'arbre
 * Return: Pointeur vers le parent du dernier nœud
 */
heap_t *get_last_node(heap_t *root, size_t size)
{
size_t path = size;
int bits = 0;
heap_t *node = root;

while (path > 1)
{
bits++;
path >>= 1;
}

path = size;
while (--bits >= 0)
{
if ((path >> bits) & 1)
node = node->right;
else
node = node->left;
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
parent = get_last_node(*root, (size + 1) / 2);

new_node = binary_tree_node(parent, value);
if (!new_node)
return (NULL);

if (!parent->left)
parent->left = new_node;
else
parent->right = new_node;

while (new_node->parent && new_node->n > new_node->parent->n)
{
int temp = new_node->n;

new_node->n = new_node->parent->n;
new_node->parent->n = temp;
new_node = new_node->parent;
}

return (new_node);
}