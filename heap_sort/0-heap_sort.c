#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
 * sift_down - Implements the sift-down heap sort algorithm
 * @array: Array to sort
 * @start: Start index
 * @end: End index
 * @size: Size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
size_t root = start;
size_t child, swap_idx;

  while (2 * root + 1 <= end)
{
child = 2 * root + 1;
swap_idx = root;

/* Compare root with left child */
if (array[swap_idx] < array[child])
swap_idx = child;

/* Compare with right child if it exists */
if (child + 1 <= end && array[swap_idx] < array[child + 1])
swap_idx = child + 1;

/* If root is already the largest, we're done */
if (swap_idx == root)
return;

/* Swap root with the larger child */
swap(&array[root], &array[swap_idx]);
print_array(array, size);
root = swap_idx; /* Continue sifting down the child */
}
}

/**
 * heapify - Builds a max heap from an array
 * @array: Array to heapify
 * @size: Size of the array
 */
void heapify(int *array, size_t size)
{
size_t start;

/* Start from the last non-leaf node and sift down each node */
start = (size - 2) / 2;
while (1)
{
sift_down(array, start, size - 1, size);
if (start == 0)
break;
start--;
}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: Array to sort
 * @size: Size of the array
 *
 * Description: Implements the sift-down heap sort algorithm and prints
 * the array after each swap
 */
void heap_sort(int *array, size_t size)
{
size_t end;

if (array == NULL || size < 2)
return;

/* Build max heap */
heapify(array, size);

/* Extract elements from the heap one by one */
end = size - 1;
while (end > 0)
{
/* Swap the root (max value) with the last element */
swap(&array[0], &array[end]);
print_array(array, size);

/* Reduce heap size and restore max heap property */
end--;
sift_down(array, 0, end, size);
}
}
