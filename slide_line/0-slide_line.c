#include "slide_line.h"

/**
 * slide_left - Slides and merges an array of integers to the left
 * @line: Points to an array of integers
 * @size: Number of elements in @line
 *
 * Return: 1 on success, 0 on failure
 */
static int slide_left(int *line, size_t size)
{
    size_t i, pos = 0;
    int merged[32] = {0};
    int prev_val = 0;

    /* First pass: merge identical numbers */
    for (i = 0; i < size; i++)
    {
        if (line[i] == 0)
            continue;

        if (prev_val == 0)
        {
            prev_val = line[i];
        }
        else if (prev_val == line[i])
        {
            /* Merge identical numbers */
            merged[pos++] = prev_val * 2;
            prev_val = 0;
        }
        else
        {
            /* Store previous value and set new value */
            merged[pos++] = prev_val;
            prev_val = line[i];
        }
    }

    /* Don't forget the last value if it wasn't merged */
    if (prev_val != 0)
        merged[pos++] = prev_val;

    /* Second pass: copy merged result back to the original array */
    for (i = 0; i < size; i++)
    {
        if (i < pos)
            line[i] = merged[i];
        else
            line[i] = 0;
    }

    return (1);
}

/**
 * slide_right - Slides and merges an array of integers to the right
 * @line: Points to an array of integers
 * @size: Number of elements in @line
 *
 * Return: 1 on success, 0 on failure
 */
static int slide_right(int *line, size_t size)
{
    int i;
    size_t pos = size - 1;
    int merged[32] = {0};
    int prev_val = 0;

    /* First pass: merge identical numbers from right to left */
    for (i = size - 1; i >= 0; i--)
    {
        if (line[i] == 0)
            continue;

        if (prev_val == 0)
        {
            prev_val = line[i];
        }
        else if (prev_val == line[i])
        {
            /* Merge identical numbers */
            merged[pos--] = prev_val * 2;
            prev_val = 0;
        }
        else
        {
            /* Store previous value and set new value */
            merged[pos--] = prev_val;
            prev_val = line[i];
        }
    }

    /* Don't forget the last value if it wasn't merged */
    if (prev_val != 0)
        merged[pos--] = prev_val;

    /* Second pass: copy merged result back to the original array */
    for (i = 0; i < (int)size; i++)
    {
        line[i] = merged[i];
    }

    return (1);
}

/**
 * slide_line - Slides and merges an array of integers
 * @line: Points to an array of integers
 * @size: Number of elements in @line
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
    if (line == NULL || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return (0);

    if (direction == SLIDE_LEFT)
        return (slide_left(line, size));
    else
        return (slide_right(line, size));
}