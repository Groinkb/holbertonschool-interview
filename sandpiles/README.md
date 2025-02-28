# Sandpiles Sum

## Description
This project implements a function that computes the sum of two sandpiles following the sandpile model. A sandpile is represented as a 3x3 grid where each cell contains a number of grains. When a cell exceeds 3 grains, it topples, distributing one grain to each adjacent cell.

## Requirements
### General
- **Allowed editors**: vi, vim, emacs
- **Compilation**: Ubuntu 14.04 LTS, gcc 4.8.4
- **Compiler flags**: -Wall -Werror -Wextra -pedantic
- **Coding style**: Betty style
- **Restrictions**:
  - No global variables
  - Maximum 5 functions per file
  - No dynamic memory allocation

## Function Prototype
```c
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
```

### Parameters
- `grid1`: First 3x3 sandpile grid (will contain the final result)
- `grid2`: Second 3x3 sandpile grid

### Rules
1. Both input grids are initially stable (no cell contains more than 3 grains)
2. A cell topples when it has more than 3 grains
3. When toppling occurs, the cell loses 4 grains and each adjacent cell gains 1 grain
4. The function must print `grid1` before each toppling round if it's unstable
5. The final state must be stable

## Example
3 3 3 1 3 1
3 3 3 + 3 3 3
3 3 3 1 3 1
=
4 6 4
6 6 6
4 6 4
=
2 5 2
5 6 5
2 5 2
...
2 2 2
2 2 2
2 2 2

## Project Structure
sandpiles/
├── 0-sandpiles.c - Implémentation de la fonction sandpiles_sum
├── sandpiles.h   - Fichier d'en-tête avec les prototypes
└── README.md     - Documentation du projet

## Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-sandpiles.c -o 0-sandpiles
```

## Resources
- [Sandpiles - Numberphile](https://www.youtube.com/watch?v=1MtEUErz7Gg)

## Author
[groinkb]

## License
This project is part of the Holberton School curriculum.
