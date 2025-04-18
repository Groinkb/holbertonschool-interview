#include "substring.h"

/**
 * is_valid_concatenation - checks if substring is valid concatenation of words
 * @s: substring to check
 * @words: array of words
 * @nb_words: number of words
 * @word_len: length of each word
 *
 * Return: 1 if valid, 0 otherwise
 */
static int is_valid_concatenation(char const *s, char const **words,
                                  int nb_words, int word_len)
{
  int i, j, found;
  int *word_used;
  char *temp_substr;

  word_used = calloc(nb_words, sizeof(int));
  if (!word_used)
    return (0);

  temp_substr = malloc((word_len + 1) * sizeof(char));
  if (!temp_substr)
  {
    free(word_used);
    return (0);
  }
  temp_substr[word_len] = '\0';

  for (i = 0; i < nb_words; i++)
  {
    strncpy(temp_substr, s + i * word_len, word_len);
    found = 0;

    for (j = 0; j < nb_words; j++)
    {
      if (!word_used[j] && strcmp(temp_substr, words[j]) == 0)
      {
        word_used[j] = 1;
        found = 1;
        break;
      }
    }

    if (!found)
    {
      free(word_used);
      free(temp_substr);
      return (0);
    }
  }

  free(word_used);
  free(temp_substr);
  return (1);
}

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
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
  int s_len, word_len, total_len;
  int i, capacity = 10;
  int *indices, *temp;

  *n = 0;
  if (!s || !words || nb_words <= 0)
    return (NULL);

  s_len = strlen(s);
  word_len = strlen(words[0]);
  total_len = word_len * nb_words;

  indices = malloc(capacity * sizeof(int));
  if (!indices)
    return (NULL);

  for (i = 0; i <= s_len - total_len; i++)
  {
    if (is_valid_concatenation(s + i, words, nb_words, word_len))
    {
      if (*n >= capacity)
      {
        capacity *= 2;
        temp = realloc(indices, capacity * sizeof(int));
        if (!temp)
        {
          free(indices);
          return (NULL);
        }
        indices = temp;
      }
      indices[(*n)++] = i;
    }
  }

  if (*n == 0)
  {
    free(indices);
  return (NULL);
}

return (indices);
}