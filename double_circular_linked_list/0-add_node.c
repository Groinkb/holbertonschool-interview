#include "list.h"

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

    /* If the list is empty */
if (!*list)
{
new_node->next = new_node;
new_node->prev = new_node;
*list = new_node;
return (new_node);
    }

    /* Find the last node (the one that points back to the first) */
last = (*list)->prev;

    /* Set the next of the last node to the new node */
last->next = new_node;

    /* Set the previous of the new node to the last node */
new_node->prev = last;

    /* Set the next of the new node to the first node */
new_node->next = *list;

    /* Set the previous of the first node to the new node */
(*list)->prev = new_node;

return (new_node);
}

/**
 * add_node_begin - Adds a new node to the beginning of a double circular
 *                  linked list
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

    /* If the list is empty */
if (!*list)
{
new_node->next = new_node;
 new_node->prev = new_node;
*list = new_node;
return (new_node);
}

    /* Find the last node (the one that points back to the first) */
last = (*list)->prev;

    /* Set the next of the new node to the first node */
new_node->next = *list;

    /* Set the previous of the new node to the last node */
new_node->prev = last;

    /* Set the next of the last node to the new node */
last->next = new_node;

    /* Set the previous of the first node to the new node */
(*list)->prev = new_node;

    /* Update the head pointer to the new node */
*list = new_node;

return (new_node);
}
