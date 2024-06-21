#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - check if the linked list has a cycle on it
 * @list: pointer to head of linked list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *slow = list;
	listint_t *fast = list;

	/* Browse the list with two pointers, one slow and one fast */
	while (slow && fast && fast->next)
	{
		slow = slow->next;	/* One step forward */
		fast = fast->next->next;	/* Two steps forward */

		/* If the two pointers meet, there is a cycle */
		if (slow == fast)
			return (1);
	}

	/* If there is no cycle, returns 0 */
	return (0);
}
