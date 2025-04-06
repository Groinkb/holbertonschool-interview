# Regular Expression Matching

## Description

This project implements a simple regular expression matching algorithm. The function `regex_match` checks whether a given pattern matches a given string.

The implementation supports the following special characters:

- `.` - Matches any single character
- `*` - Matches zero or more of the preceding character

## Files

- `regex.h` - Header file containing the function prototype
- `regex.c` - Implementation of the regex matching function

## Function Prototype

```c
int regex_match(char const *str, char const *pattern);
```

Where:
- `str` is the string to scan (can be empty and can contain any ASCII character except `.` and `*`)
- `pattern` is the regular expression (can be empty and can contain any ASCII character, including `.` and `*`)

The function returns:
- `1` if the pattern matches the string
- `0` if it doesn't match

## Algorithm

The implementation uses a recursive approach to match the pattern with the string:

1. If the pattern is empty, the match is successful only if the string is also empty.
2. If the next character in the pattern is not followed by `*`, we simply match the current character and move to the next character in both the string and pattern.
3. If the next character in the pattern is followed by `*`, we have two options:
   - Skip the pattern with `*` (match zero occurrences)
   - Match the current character and try to match the rest of the string with the same pattern

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic main.c regex.c -o regex
```

## Example

```c
regex_match("H", "H");           // Returns 1
regex_match("HH", "H");          // Returns 0
regex_match("HH", "H*");         // Returns 1
regex_match("Holberton", ".*");  // Returns 1
```


## Author
BM
