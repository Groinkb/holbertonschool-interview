#include "binary_trees.h"

/**
 * get_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the tree root
 * Return: Size of the tree or 0 if tree is NULL
 */
size_t get_tree_size(const binary_tree_t *tree)
{
if (!tree)
return (0);

return (1 + get_tree_size(tree->left) + get_tree_size(tree->right));
}

/**
 * get_last_node - Get the last level-order node of a heap
 * @root: Pointer to the root of the heap
 * @size: Size of the heap
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root, size_t size)
{
heap_t *node = NULL;
size_t mask;

if (!root || size == 0)
return (NULL);

  /* Create a bit mask to navigate to the last node */
for (mask = 1; mask <= size; mask <<= 1)
;
mask >>= 2;

  /* Navigate to the last node using the bit mask */
node = root;
while (mask > 0)
{
if (size & mask)
node = node->right;
else
node = node->left;
mask >>= 1;
}

return (node);
}

/**
 * heapify_down - Restore the max heap property downward
 * @root: Pointer to the root of the heap
 */
void heapify_down(heap_t *root)
{
heap_t *node = root, *largest_child = NULL;
int tmp;

while (1)
{
if (!node->left)
break;

if (!node->right)
largest_child = node->left;
else
largest_child = (node->left->n > node->right->n) ? node->left : node->right;

if (node->n >= largest_child->n)
break;

    /* Swap values */
tmp = node->n;
node->n = largest_child->n;
largest_child->n = tmp;

node = largest_child;
}
}

/**
 * heap_extract - Extracts the root node from a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
int value;
size_t size;
heap_t *last_node = NULL;

if (!root || !*root)
return (0);

  /* Get the value to return */
value = (*root)->n;

  /* Get the size of the heap */
size = get_tree_size(*root);

  /* Handle the case of a single node */
if (size == 1)
{
free(*root);
*root = NULL;
return (value);
}

  /* Find the last level-order node */
last_node = get_last_node(*root, size);
if (!last_node)
return (0);

  /* Move the last node's value to the root */
(*root)->n = last_node->n;

  /* Remove the last node from its parent */
if (last_node->parent->left == last_node)
last_node->parent->left = NULL;
else
last_node->parent->right = NULL;
free(last_node);
  /* Restore the heap property */
heapify_down(*root);
return (value);
}
