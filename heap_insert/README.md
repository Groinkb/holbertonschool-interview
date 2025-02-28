# Binary Tree Node & Max Heap Insertion

## Description
Ce projet implémente deux fonctionnalités essentielles des arbres binaires et des tas binaires maximaux :
- Création d'un nœud d'arbre binaire
- Insertion dans un tas binaire maximal (Max Binary Heap)

## Exigences

### Environnement
- Ubuntu 14.04 LTS
- gcc 4.8.4
- Flags de compilation : `-Wall -Werror -Wextra -pedantic`

### Contraintes
- Éditeurs autorisés : vi, vim, emacs
- Tous les fichiers doivent se terminer par une nouvelle ligne
- Style de code Betty obligatoire (vérifié avec betty-style.pl et betty-doc.pl)
- Pas de variables globales
- Maximum 5 fonctions par fichier
- Utilisation de la bibliothèque standard autorisée

## Structure de données

```c
/**
 * struct binary_tree_s - Nœud d'arbre binaire
 * @n: Entier stocké dans le nœud
 * @parent: Pointeur vers le nœud parent
 * @left: Pointeur vers le fils gauche
 * @right: Pointeur vers le fils droit
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;
```

## Tâches

### 0. Création d'un nouveau nœud
**Fichier :** `0-binary_tree_node.c`

```c
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
```

**Description :**
- Crée un nouveau nœud d'arbre binaire
- Le nœud créé n'a pas d'enfants initialement
- Retourne un pointeur vers le nouveau nœud ou NULL en cas d'échec

### 1. Insertion dans un tas
**Fichier :** `1-heap_insert.c`

```c
heap_t *heap_insert(heap_t **root, int value);
```

**Description :**
- Insère une valeur dans un tas binaire maximal
- Maintient la propriété du tas maximal
- Si root est NULL, crée le nœud racine
- Retourne un pointeur vers le nœud inséré ou NULL en cas d'échec

## Exemple d'utilisation

```bash
$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node
$ ./0-node
        .-------(098)-------.
   .--(012)--.         .--(402)--.
 (006)     (016)     (256)     (512)
```

## Fichiers

- `binary_trees.h` : fichier d'en-tête avec prototypes et structures
- `0-binary_tree_node.c` : implémentation de la création de nœud
- `1-heap_insert.c` : implémentation de l'insertion dans le tas

## Notes

- Les fichiers main.c sont fournis comme exemples et ne doivent pas être poussés
- La fonction d'impression binary_tree_print est fournie pour la visualisation
- Tous les fichiers d'en-tête doivent être protégés contre la double inclusion
