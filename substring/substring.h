#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * find_substring - finds all possible substrings containing a list of words
 * @s: string to scan
 * @words: array of words all substrings must be a concatenation of
 * @nb_words: number of elements in the array words
 * @n: holds the address at which to store the number of elements in returned array
 *
 * Return: allocated array storing each index in s at which a substring was found
 *         NULL if no solution is found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif /* SUBSTRING_H */