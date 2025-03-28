#include "sort.h"

/**
 * get_max - Gets the maximum value in an array
 * @array: The array to find the maximum value in
 * @size: Size of the array
 *
 * Return: The maximum value
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return (max);
}

/**
 * counting_sort_radix - Sorts an array based on a specific digit position
 * @array: The array to sort
 * @size: Size of the array
 * @exp: The current digit position (1, 10, 100, ...)
 * @output: Temporary array to store the sorted elements
 */
void counting_sort_radix(int *array, size_t size, int exp, int *output)
{
    int count[10] = {0};
    size_t i;

    /* Count occurrences of each digit at the current position */
    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    /* Adjust count to store actual positions */
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Build the output array */
    for (i = size - 1; i < size; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    /* Copy the output array to the original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix sort
 * @array: The array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;
    int *output;

    /* Check if array is NULL or size < 2 */
    if (array == NULL || size < 2)
        return;

    /* Find the maximum number to determine the number of digits */
    max = get_max(array, size);

    /* Allocate memory for output array */
    output = malloc(sizeof(int) * size);
    if (output == NULL)
        return;

    /* Perform counting sort for each digit position */
    for (exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort_radix(array, size, exp, output);
        print_array(array, size);
    }

    free(output);
}