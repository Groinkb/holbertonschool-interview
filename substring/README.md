# Substring with Concatenated Words

This project implements a C function that finds all possible substrings containing a list of words, within a given string.

## Description

The `find_substring` function scans a string and finds all indices where a substring begins that is a concatenation of all the words from a given array, with each word used exactly once and without any intervening characters.

### Function Prototype

```c
int *find_substring(char const *s, char const **words, int nb_words, int *n);
```

Where:
- `s` is the string to scan
- `words` is the array of words all substrings must be a concatenation arrangement of
- `nb_words` is the number of elements in the array `words`
- `n` holds the address at which to store the number of elements in the returned array

### Return Value

The function returns an allocated array storing each index in `s` at which a substring was found. If no solution is found, NULL is returned.

### Constraints

- All words in the array `words` are the same length
- A valid substring of `s` is the concatenation of each word in `words` exactly once and without any intervening characters

## Example

```c
s = "barfoothefoobarman"
words = ["foo", "bar"]
Output: [0, 9]
```

In this example:
- At index 0, we have "barfoo" which is a concatenation of "bar" and "foo"
- At index 9, we have "foobar" which is a concatenation of "foo" and "bar"

## Compilation

The code can be compiled with:

```
gcc -Wall -Werror -Wextra -pedantic substring.c main.c -o substring
```

## Files

- `substring.h`: Header file containing function prototype
- `substring.c`: Implementation of the function