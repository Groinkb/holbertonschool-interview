# Merge Sort Implementation

## Description
This project implements the Merge Sort algorithm to sort an array of integers in ascending order. The implementation uses the top-down approach of the Merge Sort algorithm.

## Merge Sort Algorithm
Merge Sort is a divide-and-conquer algorithm that:
1. Divides the input array into two halves
2. Recursively sorts the two halves
3. Merges the sorted halves to produce the final sorted array

### Time Complexity
- Best case: O(nlog(n))
- Average case: O(nlog(n))
- Worst case: O(nlog(n))

### Space Complexity
- O(n) - requires additional space proportional to the input size

## Requirements
- Allowed editors: vi, vim, emacs
- All files will be compiled on Ubuntu 14.04 LTS
- Programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
- All files should end with a new line
- Code should use the Betty style
- No global variables
- No more than 5 functions per file
- Limited use of standard library functions (printf is allowed)
- malloc and free can only be called once

## Files
- `0-merge_sort.c`: Contains the implementation of the merge sort algorithm
- `sort.h`: Header file containing function prototypes
- `0-O`: Big O notations for the time complexity of Merge Sort

## Implementation Details
- The top-down merge sort algorithm is implemented
- When dividing an array into two sub-arrays, the size of the left array is always <= the size of the right array
- The left array is sorted before the right array
- Temporary storage is allocated once at the beginning and freed at the end

## Compilation & Usage
```
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-merge_sort.c print_array.c -o merge
./merge
```

## Example Output
```
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

Merging...
[left]: 19
[right]: 48
[Done]: 19, 48
Merging...
[left]: 71
[right]: 13
[Done]: 13, 71
...
Merging...
[left]: 13, 19, 48, 71, 99
[right]: 7, 52, 73, 86, 96
[Done]: 7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```
## Author
BM