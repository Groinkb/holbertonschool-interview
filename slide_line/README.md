# 2048 Slide Line

## Description
Ce projet implémente une version simplifiée du mécanisme de jeu 2048, limité à une seule ligne horizontale. L'objectif est de reproduire les mécanismes de glissement et de fusion des tuiles du jeu 2048 sur une ligne.

## Fonctionnalité
La fonction principale, `slide_line()`, prend un tableau d'entiers et permet de :
- Faire glisser tous les entiers vers la gauche ou la droite
- Fusionner les nombres identiques s'ils sont contigus ou séparés par des zéros
- Maintenir l'ordre des nombres non fusionnés

## Règles
- Les nombres identiques doivent être fusionnés pour former un nouveau nombre qui est la somme des deux
- Les nombres ne peuvent être fusionnés qu'une seule fois par opération
- Les zéros sont considérés comme des cases vides et sont ignorés lors de la fusion
- Après glissement et fusion, tous les nombres sont regroupés à gauche ou à droite (selon la direction), sans espace vide entre eux

## Utilisation
```c
#include "slide_line.h"

int main(void)
{
    int line[] = {2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 4};
    size_t size = sizeof(line) / sizeof(line[0]);
    
    // Glisser la ligne vers la gauche
    slide_line(line, size, SLIDE_LEFT);
    
    // Ou glisser la ligne vers la droite
    slide_line(line, size, SLIDE_RIGHT);
    
    return (0);
}
```

## Exemples

### Glisser vers la gauche
Entrée: `[2, 2, 0, 0]`  
Sortie: `[4, 0, 0, 0]`

Entrée: `[2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 4]`  
Sortie: `[4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]`

### Glisser vers la droite
Entrée: `[2, 2, 2, 2]`  
Sortie: `[0, 0, 4, 4]`

Entrée: `[2, 2, 2, 2, 2]`  
Sortie: `[0, 0, 2, 4, 4]`

## Compilation
```
gcc -Wall -Werror -Wextra -pedantic -o 0-slide_line 0-main.c 0-slide_line.c
```

## Exécution
```
./0-slide_line L 2 2 0 0
./0-slide_line R 2 2 2 2
```