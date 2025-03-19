# 2D Menger Sponge

## Description
Ce projet implémente une fonction qui dessine une éponge de Menger 2D à l'écran. L'éponge de Menger est une fractale cubique qui est l'équivalent tridimensionnel du tapis de Sierpiński.

## Théorie
Une éponge de Menger de niveau N est une grille 3x3 d'éponges de Menger de niveau N-1, à l'exception de l'éponge centrale qui est laissée vide.

- Une éponge de niveau 0 est représentée par un simple caractère `#`
- Une éponge de niveau 1 est une grille 3x3 d'éponges de niveau 0, avec le centre vide
- Une éponge de niveau 2 est une grille 3x3 d'éponges de niveau 1, avec le centre vide
- Et ainsi de suite...

La taille d'une éponge de Menger de niveau N est calculée comme suit: 3^N

## Fonction principale
```c
void menger(int level);
```
- `level`: Niveau de l'éponge de Menger à dessiner
- Si level est inférieur à 0, la fonction ne fait rien

## Algorithme
L'algorithme utilise une approche récursive pour déterminer quels "pixels" doivent être vides:
1. Pour chaque position (row, col) dans la grille 3^level x 3^level
2. Si la position est au centre d'un carré 3x3 à n'importe quel niveau de récursion, elle est vide
3. Sinon, elle est remplie avec le caractère '#'

## Exemples
### Niveau 0
```
#
```

### Niveau 1
```
###
# #
###
```

### Niveau 2
```
#########
# ## ## #
#########
###   ###
# #   # #
###   ###
#########
# ## ## #
#########
```

## Compilation
```
gcc -Wall -Wextra -Werror -pedantic -o 0-menger 0-menger.c 0-main.c -lm
```

## Exécution
```
./0-menger <level>
```
Où `<level>` est l'entier qui indique le niveau de l'éponge de Menger à dessiner.