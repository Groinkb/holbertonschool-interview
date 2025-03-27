#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: pointer to the first node where value is located, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *express, *current;

    /* Check if list is NULL */
    if (list == NULL)
        return (NULL);

    express = list;
    current = list;

    /* Traverse express lanes */
    while (express->express != NULL && express->n < value)
    {
        current = express;
        express = express->express;
        printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
    }

    /* If express lane ends or we found our search range */
    if (express->express == NULL && express->n < value)
    {
        /* Save the start of our range for searching */
        current = express;
        /* Find the last node of the list */
        while (express->next != NULL)
            express = express->next;
    }

    printf("Value found between indexes [%lu] and [%lu]\n",
           current->index, express->index);

    /* Linear search between the nodes */
    while (current != NULL && current->index <= express->index)
    {
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
        if (current->n == value)
            return (current);
        current = current->next;
    }

    /* Value not found */
    return (NULL);
}