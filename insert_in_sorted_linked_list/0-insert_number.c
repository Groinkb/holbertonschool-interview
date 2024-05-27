#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to pointer to the head of the list
 * @number: value to be inserted
 * BM
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node;
    listint_t *current_node;

    new_node = *head;
    current_node = *head;

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
		return (NULL);

    new_node->n = number;

    if (*head == NULL)
    {
        *head = new_node;
        return (new_node);
    }

    if (current_node->n > number)
    {
        *head = new_node;
        new_node->next = current_node;
        return (new_node);
    }

    while (current_node->next->n < number)
    {
        current_node = current_node->next;

        if (current_node->next == NULL)
        {
        current_node->next = new_node;
        new_node->next = NULL;
        return (new_node);
        }
    }
    new_node->next = current_node->next;
    current_node->next = new_node;
    return (new_node);
}
