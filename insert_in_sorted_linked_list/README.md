# Insertion dans une Liste Chaînée Triée

## Description du problème

Dans le cadre de cet exercice de préparation aux entretiens techniques, vous devez implémenter une fonction qui insère un nombre dans une liste chaînée simple triée.

## Contraintes

- Pas de recherche Google autorisée
- La solution doit d'abord être conçue sur un tableau blanc
- La liste est triée en ordre croissant

## Prototype de la fonction

```c
listint_t *insert_node(listint_t **head, int number);
```

## Structure de données

```c
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;
```

## Paramètres

- `head` : Un pointeur vers le pointeur de tête de la liste chaînée
- `number` : L'entier à insérer dans la liste

## Valeur de retour

- L'adresse du nouveau nœud en cas de succès
- `NULL` en cas d'échec

## Fonctions auxiliaires fournies

1. `print_listint` : Affiche tous les éléments de la liste
2. `add_nodeint_end` : Ajoute un nouveau nœud à la fin de la liste
3. `free_listint` : Libère la mémoire de la liste

## Exemple d'utilisation

```c
int main(void)
{
    listint_t *head = NULL;

    // Création de la liste : 0 -> 1 -> 2 -> 3 -> 4 -> 98 -> 402 -> 1024
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    // ... autres ajouts ...

    // Insertion du nombre 27
    insert_node(&head, 27);

    // Résultat attendu :
    // 0 -> 1 -> 2 -> 3 -> 4 -> 27 -> 98 -> 402 -> 1024
}
```

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-insert_number.c -o insert
```

## Approche suggérée

1. Gérer les cas spéciaux :
   - Liste vide
   - Insertion en début de liste
2. Parcourir la liste jusqu'à trouver la bonne position
3. Créer le nouveau nœud
4. Mettre à jour les pointeurs pour insérer le nœud
5. Gérer la gestion de la mémoire

## Complexité

- Temporelle : O(n) où n est le nombre de nœuds dans la liste
- Spatiale : O(1) car nous créons seulement un nouveau nœud
