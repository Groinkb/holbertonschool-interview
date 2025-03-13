#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle
 * @list: pointer to the head of the list
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
    listint_t *slow, *fast;

    /* Empty list or single node list - no cycle possible */
    if (list == NULL || list->next == NULL)
        return (0);

    /* Initialize slow and fast pointers */
    slow = list;
    fast = list->next;

    /* Traverse the list */
    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        /* If slow and fast pointers meet, we found a cycle */
        if (slow == fast)
            return (1);

        /* Move slow pointer one step */
        slow = slow->next;
        /* Move fast pointer two steps */
        fast = fast->next->next;
    }

    /* If we reached here, no cycle was found */
    return (0);
}