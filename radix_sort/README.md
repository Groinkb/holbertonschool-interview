# Radix Sort

This project implements the Radix Sort algorithm in C, specifically the Least Significant Digit (LSD) approach.

## Requirements

### General
- Allowed editors: `vi`, `vim`, `emacs`
- All files compiled on Ubuntu 14.04 LTS
- Programs and functions compiled with `gcc 4.8.4` using flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- All files should end with a new line
- Code should follow the `Betty` style
- No global variables allowed
- No more than 5 functions per file
- Standard library usage is limited to `malloc` and `free`
- Function prototypes included in the header file `sort.h`
- Header files should be include guarded

## Task: Radix Sort

### Description
Implement the LSD (Least Significant Digit) Radix Sort algorithm to sort an array of integers in ascending order.

### Prototype
```c
void radix_sort(int *array, size_t size);
```

### Requirements
- The implementation must use the LSD radix sort algorithm
- The array will contain only numbers `>= 0`
- The `array` must be printed each time the significant digit is increased

## Algorithm Explanation

Radix Sort is a non-comparative sorting algorithm that works by distributing elements into buckets according to their individual digits. The process starts with the least significant digit (rightmost) and moves towards the most significant digit (leftmost).

### LSD (Least Significant Digit) Approach:

1. Find the maximum number in the array to determine the number of digit positions
2. For each digit position (starting from the least significant):
   - Use counting sort to sort the array based on the current digit position
   - Print the array after each pass
3. The array will be sorted after processing all digit positions

### Time Complexity
- **Best case**: O(nk) where n is the number of elements and k is the number of digits in the maximum number
- **Average case**: O(nk)
- **Worst case**: O(nk)

### Space Complexity
- O(n+k) where n is the number of elements and k is the range of input (10 for decimal digits)

## Usage Example

```c
int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
size_t n = sizeof(array) / sizeof(array[0]);

radix_sort(array, n);
```

Output:
```
71, 52, 13, 73, 96, 86, 7, 48, 19, 99  // After sorting by ones digit
7, 13, 19, 48, 52, 71, 73, 86, 96, 99  // After sorting by tens digit
```

## Author
BM