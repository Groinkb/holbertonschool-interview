# Heap Sort

## Description
This project implements the Heap sort algorithm in C. Heap sort is a comparison-based sorting algorithm that uses a binary heap data structure. It's divided into two parts:
1. Building a max heap from the input data
2. Repeatedly extracting the maximum element from the heap and rebuilding the heap

## Requirements
- All files will be compiled on Ubuntu 14.04 LTS
- Programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
- Code follows the Betty style
- No global variables
- No more than 5 functions per file
- Standard library functions like printf and puts are forbidden

## Files
- `0-heap_sort.c`: Contains the implementation of heap sort
- `0-O`: Contains the big O notations of the time complexity of Heap sort
- `sort.h`: Header file with function prototypes
- `print_array.c`: Function to print arrays (provided)

## Big O Notation
The time complexity of Heap sort is:
- Best case: O(nlog(n))
- Average case: O(nlog(n))
- Worst case: O(nlog(n))

## Algorithm
The implementation uses the sift-down approach which consists of:
1. Building a max heap (heapify)
2. Extracting elements one by one from the heap
   - Swap the root (maximum) with the last element
   - Reduce the heap size by one
   - Sift down the new root to maintain the max heap property

## Compilation
```
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-heap_sort.c print_array.c -o 0-heap
```

## Usage
```
./0-heap
```

## Author
BM