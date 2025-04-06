#include "regex.h"

/**
 * match_helper - Recursive helper function for regex matching
 * @str: The string to scan
 * @pattern: The regular expression
 *
 * Return: 1 if the pattern matches the string, 0 if it doesn't
 */
static int match_helper(char const *str, char const *pattern)
{
  /* If pattern is empty, string must also be empty */
  if (*pattern == '\0')
    return (*str == '\0');

  /* Look ahead to check if the next character is '*' */
  int is_star = *(pattern + 1) == '*';

  /* If next char is not '*', standard matching for current character */
  if (!is_star)
  {
    /* Current char must match pattern or pattern is '.' and str not empty */
    if (*str != '\0' && (*pattern == '.' || *pattern == *str))
      return match_helper(str + 1, pattern + 1);
    return 0;
  }
  else /* Next char is '*' */
  {
    /* Try matching zero characters (skip the pattern with '*') */
    if (match_helper(str, pattern + 2))
      return 1;

    /* Try matching one or more characters */
    while (*str != '\0' && (*pattern == '.' || *pattern == *str))
    {
      /* Match one character and try again with rest of string */
      str++;
      if (match_helper(str, pattern + 2))
        return 1;
    }
    return 0;
  }
}

/**
 * regex_match - Checks whether a given pattern matches a given string
 * @str: The string to scan
 * @pattern: The regular expression
 *
 * Return: 1 if the pattern matches the string, 0 if it doesn't
 */
int regex_match(char const *str, char const *pattern)
{
  if (!str || !pattern)
    return 0;

  return match_helper(str, pattern);
}