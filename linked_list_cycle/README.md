# Cycle dans une Liste Chaînée

## Description
Ce projet implémente une fonction en C qui vérifie si une liste chaînée simple contient un cycle. Un cycle dans une liste chaînée se produit lorsqu'un nœud pointe vers un nœud précédent dans la liste, créant ainsi une boucle infinie lors du parcours de la liste.

## Exigences de la tâche
- Écrire une fonction en C qui vérifie si une liste chaînée simple contient un cycle
- Prototype: `int check_cycle(listint_t *list);`
- Retour:
  - 0 s'il n'y a pas de cycle
  - 1 s'il y a un cycle
- Seules ces fonctions sont autorisées: `write`, `printf`, `putchar`, `puts`, `malloc`, `free`
- La solution doit être efficace en termes de temps d'exécution et d'utilisation de la mémoire

## Fichiers
- `0-check_cycle.c`: Implémentation de la fonction `check_cycle`
- `lists.h`: Fichier d'en-tête contenant les prototypes de fonctions et la définition de la structure de liste chaînée

## Compilation
Le code peut être compilé en utilisant:
```
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-check_cycle.c 0-linked_lists.c -o cycle
```

## Exemple d'utilisation
```c
#include "lists.h"

int main(void)
{
    listint_t *head = NULL;
    
    // Créer une liste chaînée
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    add_nodeint(&head, 3);
    
    // Vérifier s'il y a un cycle
    if (check_cycle(head) == 0)
        printf("Pas de cycle détecté\n");
    else
        printf("Cycle détecté\n");
        
    // Créer un cycle
    head->next->next->next = head;
    
    // Vérifier à nouveau
    if (check_cycle(head) == 0)
        printf("Pas de cycle détecté\n");
    else
        printf("Cycle détecté\n");
    
    return (0);
}
```

## Algorithme
La solution implémente l'algorithme du lièvre et de la tortue de Floyd (également connu sous le nom de technique des "pointeurs rapide et lent"). Cette approche utilise deux pointeurs qui parcourent la liste à des vitesses différentes, et s'il y a un cycle, le pointeur plus rapide finira par rattraper le plus lent.

## Auteur
Groink étudiant de Holberton School