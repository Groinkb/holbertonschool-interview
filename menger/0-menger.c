#include "menger.h"

/**
 * is_empty - Determines if a cell should be empty
 * @row: Row position
 * @col: Column position
 *
 * Return: 1 if the cell should be empty, 0 otherwise
 */
int is_empty(int row, int col)
{
    while (row > 0 && col > 0)
    {
        if (row % 3 == 1 && col % 3 == 1)
            return (1);
        row /= 3;
        col /= 3;
    }
    return (0);
}

/**
 * menger - Draws a 2D Menger Sponge
 * @level: Level of the Menger Sponge
 *
 * Return: void
 */
void menger(int level)
{
    int size, row, col;

    if (level < 0)
        return;

    /* Calculate size of the sponge: 3^level */
    size = pow(3, level);

    /* Print the Menger Sponge pattern */
    for (row = 0; row < size; row++)
    {
        for (col = 0; col < size; col++)
        {
            if (is_empty(row, col))
                putchar(' ');
            else
                putchar('#');
        }
        putchar('\n');
    }
}