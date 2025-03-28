#include "list.h"

/**
 * create_node - Creates a new node with the given string
 * @str: String to be duplicated and stored in the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *create_node(char *str)
{
List *new_node;

    /* Allocate memory for new node */
new_node = malloc(sizeof(List));
if (!new_node)
return (NULL);

    /* Duplicate the string */
new_node->str = strdup(str);
if (!new_node->str)
{
free(new_node);
return (NULL);
}

return (new_node);
}

/**
 * initialize_single_node - Sets up a node as the only element in the list
 * @list: Pointer to the pointer of the head of the list
 * @new_node: The node to initialize
 *
 * Return: Address of the new node
 */
List *initialize_single_node(List **list, List *new_node)
{
new_node->next = new_node;
new_node->prev = new_node;
*list = new_node;
return (new_node);
}

/**
 * add_node_end - Adds a new node to the end of a double circular linked list
 * @list: Pointer to the pointer of the head of the list
 * @str: String to be duplicated and stored in the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
List *new_node, *last;

    /* Validate inputs */
if (!list || !str)
return (NULL);

    /* Create new node */
new_node = create_node(str);
if (!new_node)
return (NULL);

    /* If the list is empty */
if (!*list)
return (initialize_single_node(list, new_node));

    /* Find the last node (the one that points back to the first) */
    last = (*list)->prev;

    /* Set connections */
last->next = new_node;
new_node->prev = last;
new_node->next = *list;
(*list)->prev = new_node;

return (new_node);
}

/**
 * add_node_begin - Adds a new node to the beginning of a double circular list
 * @list: Pointer to the pointer of the head of the list
 * @str: String to be duplicated and stored in the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
List *new_node, *last;

    /* Validate inputs */
if (!list || !str)
return (NULL);

    /* Create new node */
new_node = create_node(str);
if (!new_node)
return (NULL);

    /* If the list is empty */
if (!*list)
return (initialize_single_node(list, new_node));

    /* Find the last node and set connections */
last = (*list)->prev;
new_node->next = *list;
new_node->prev = last;
last->next = new_node;
(*list)->prev = new_node;

    /* Update the head pointer to the new node */
*list = new_node;

return (new_node);
}