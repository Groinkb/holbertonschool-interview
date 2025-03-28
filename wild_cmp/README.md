# Wild Compare

This project implements a function that compares two strings, where one of them can contain the special character `*` which can replace any string (including an empty string).

## Requirements

### General
- Allowed editors: `vi`, `vim`, `emacs`
- All files will be compiled on Ubuntu 14.04 LTS
- Programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall`, `-Werror`, `-Wextra`, and `-pedantic`
- All files should end with a new line
- Code should use the `Betty` style
- No global or static variables allowed
- No more than 5 functions per file
- Standard library is not allowed
- Function prototypes are included in the header file `holberton.h`
- No loops of any kind are allowed

## Task: Wild Compare

### Description
Write a function that compares two strings and returns 1 if the strings can be considered identical, otherwise return 0.

### Prototype
```c
int wildcmp(char *s1, char *s2);
```

### Parameters
- `s1`: First string to compare
- `s2`: Second string to compare, which can contain the special character `*`

### Special Character
- The special char `*` can replace any string (including an empty string)

### Return Value
- `1` if the strings can be considered identical
- `0` otherwise

### Example
```c
wildcmp("main.c", "*.c") -> 1
wildcmp("main.c", "m*a*i*n*.*c*") -> 1
wildcmp("main.c", "main.c") -> 1
wildcmp("main.c", "m*c") -> 1
wildcmp("main.c", "ma********************************c") -> 1
wildcmp("main.c", "*") -> 1
wildcmp("main.c", "***") -> 1
wildcmp("main.c", "m.*c") -> 0
wildcmp("main.c", "**.*c") -> 1
wildcmp("main-main.c", "ma*in.c") -> 1
wildcmp("main", "main*d") -> 0
wildcmp("abc", "*b") -> 0
```

## Algorithm Approach

The `wildcmp` function uses recursion to compare the strings. The approach is as follows:

1. If both strings are empty, they are identical
2. If `s2` has a `*`:
   - If the next character in `s2` is also `*`, skip it
   - If `s1` is empty, check if the rest of `s2` can match an empty string
   - Otherwise, try two possibilities:
     - Use the `*` to match the current character in `s1`
     - Don't use the `*` and move to the next character in `s2`
3. If current characters match, continue with next characters
4. Otherwise, the strings are not identical

This recursive approach handles all cases without using any loops, as required by the project specifications.

## Author
BM