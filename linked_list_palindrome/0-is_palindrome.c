#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse - reverses a singly linked list
 * @head: pointer to pointer of the first node of listint_t list
 * Return: pointer to the first node of the reversed list
 */
listint_t *reverse(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current;
	listint_t *next;

	current = *head;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
	return (*head);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow;
	listint_t *fast;
	listint_t *prev_slow;
	listint_t *second_half;
	listint_t *first_half;
	listint_t *second_half_head;
	int is_palindrome = 1;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	slow = *head;
	fast = *head;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		prev_slow = slow;
		slow = slow->next;
	}

	prev_slow->next = NULL;
	second_half = reverse(&slow);

	first_half = *head;
	second_half_head = second_half;
	while (first_half != NULL && second_half != NULL)
	{
		if (first_half->n != second_half->n)
		{
			is_palindrome = 0;
			break;
		}
		first_half = first_half->next;
		second_half = second_half->next;
	}

	prev_slow->next = reverse(&second_half_head);

	return (is_palindrome);
}
