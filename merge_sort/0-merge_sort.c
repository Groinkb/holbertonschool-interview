#include "sort.h"

/**
 * merge - Merges two subarrays into one sorted array
 * @array: Original array
 * @temp: Temporary array for merging
 * @left: Start index of left subarray
 * @mid: End index of left subarray
 * @right: End index of right subarray
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
size_t i, j, k;

printf("Merging...\n");
printf("[left]: ");
for (i = left; i < mid; i++)
{
if (i > left)
printf(", ");
printf("%d", array[i]);
}
printf("\n[right]: ");
for (i = mid; i < right; i++)
{
if (i > mid)
printf(", ");
printf("%d", array[i]);
}
printf("\n");

    /* Copy data to temp arrays */
for (i = left; i < right; i++)
temp[i] = array[i];

    /* Merge the temp arrays back into array[left..right] */
i = left; /* Initial index of left subarray */
j = mid;  /* Initial index of right subarray */
k = left; /* Initial index of merged subarray */

while (i < mid && j < right)
{
if (temp[i] <= temp[j])
array[k++] = temp[i++];
else
array[k++] = temp[j++];
    }

    /* Copy the remaining elements of left subarray, if any */
while (i < mid)
array[k++] = temp[i++];

    /* Copy the remaining elements of right subarray, if any */
while (j < right)
array[k++] = temp[j++];

printf("[Done]: ");
for (i = left; i < right; i++)
{
if (i > left)
printf(", ");
printf("%d", array[i]);
}
printf("\n");
}

/**
 * merge_sort_recursive - Recursive function to implement merge sort
 * @array: Array to be sorted
 * @temp: Temporary array for merging
 * @left: Start index
 * @right: End index
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
size_t mid;

if (right - left > 1)
{
        /* Calculate mid ensuring left array is <= right array in size */
mid = left + (right - left) / 2;

        /* Sort first and second halves */
merge_sort_recursive(array, temp, left, mid);
merge_sort_recursive(array, temp, mid, right);

        /* Merge the sorted halves */
merge(array, temp, left, mid, right);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
int *temp;

if (!array || size < 2)
return;

    /* Allocate temporary array for merging */
temp = malloc(sizeof(int) * size);
if (!temp)
return;

    /* Call the recursive merge sort function */
merge_sort_recursive(array, temp, 0, size);

    /* Free the temporary array */
free(temp);
}