#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Insère un nombre dans une liste chaînée triée
 * @head: Pointeur vers le pointeur de tête de la liste
 * @number: Nombre à insérer
 * Return: Adresse du nouveau nœud ou NULL si échec
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *current;

    /* Création du nouveau nœud */
    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;
    new->next = NULL;

    /* Si la liste est vide ou si le nombre est plus petit que la tête */
    if (*head == NULL || (*head)->n >= number)
    {
        new->next = *head;
        *head = new;
        return (new);
    }

    /* Parcours de la liste pour trouver la position d'insertion */
    current = *head;
    while (current->next != NULL && current->next->n < number)
        current = current->next;

    /* Insertion du nouveau nœud */
    new->next = current->next;
    current->next = new;

    return (new);
}
