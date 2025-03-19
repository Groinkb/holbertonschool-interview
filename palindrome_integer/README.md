# Palindrome Integer

## Description
Ce projet implémente une fonction en C qui vérifie si un entier non signé donné est un palindrome. Un palindrome est un nombre qui se lit de la même façon de gauche à droite et de droite à gauche.

## Exigences
- Éditeurs autorisés: `vi`, `vim`, `emacs`
- Système de compilation: Ubuntu 14.04 LTS
- Compilation avec `gcc 4.8.4` en utilisant les flags `-Wall -Werror -Wextra -pedantic`
- Style de code: Betty
- Pas de variables globales
- Maximum 5 fonctions par fichier
- Pas d'allocation dynamique de mémoire (malloc, calloc, etc.)

## Fichiers
- `0-is_palindrome.c`: Implémentation de la fonction qui vérifie si un nombre est un palindrome
- `palindrome.h`: Fichier d'en-tête contenant le prototype de la fonction

## Prototype de la fonction
```c
int is_palindrome(unsigned long n);
```
- Où `n` est le nombre à vérifier
- La fonction retourne `1` si `n` est un palindrome, et `0` sinon

## Algorithme
L'algorithme utilisé suit une approche simple et efficace:
1. Vérifier d'abord les cas particuliers (nombres à un seul chiffre)
2. Inverser le nombre en utilisant des opérations mathématiques
3. Comparer le nombre original avec sa version inversée
4. Si les deux sont identiques, c'est un palindrome

## Exemples d'utilisation
```
./palindrome 1
1 is a palindrome.

./palindrome 11
11 is a palindrome.

./palindrome 112
112 is not a palindrome.

./palindrome 121
121 is a palindrome.

./palindrome 12345678987654321
12345678987654321 is a palindrome.

./palindrome 1234567898654321
1234567898654321 is not a palindrome.
```

## Compilation
```
gcc -Wall -Wextra -Werror -pedantic -g3 -o palindrome 0-main.c 0-is_palindrome.c
```