#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @left: The left index of the array
 * @right: The right index of the array
 */
void print_array(int *array, size_t left, size_t right)
{
  size_t i;

  printf("Searching in array: ");
  for (i = left; i <= right; i++)
  {
    printf("%d", array[i]);
    if (i < right)
      printf(", ");
  }
  printf("\n");
}

/**
 * binary_search_recursive - Searches recursively for a value in a sorted
 *                          array of integers using binary search
 * @array: Pointer to the first element of the array to search in
 * @left: Left index of the subarray
 * @right: Right index of the subarray
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found
 */
int binary_search_recursive(int *array, size_t left, size_t right, int value)
{
  size_t mid;

  if (left > right)
    return (-1);

  print_array(array, left, right);

  mid = left + (right - left) / 2;

  /* If value found and it's the first occurrence or the leftmost element */
  if ((mid == left || array[mid - 1] < value) && array[mid] == value)
    return (mid);

  /* If mid value >= value, search in the left subarray to find the leftmost occurrence */
  if (array[mid] >= value)
    return (binary_search_recursive(array, left, mid, value));
  else
    return (binary_search_recursive(array, mid + 1, right, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 *                  Returns the index of the first value in the array
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found or array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
  if (array == NULL || size == 0)
    return (-1);

  return (binary_search_recursive(array, 0, size - 1, value));
}