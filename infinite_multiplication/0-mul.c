#include "holberton.h"
#include <stdlib.h>

/**
 * _strlen - Calculates the length of a string
 * @s: The string to measure
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
int len = 0;

while (s[len])
len++;
return (len);
}

/**
 * is_digit - Checks if a string contains only digits
 * @s: The string to check
 *
 * Return: 1 if all chars are digits, 0 otherwise
 */
int is_digit(char *s)
{
int i = 0;

while (s[i])
{
if (s[i] < '0' || s[i] > '9')
return (0);
i++;
}
return (1);
}
/**
 * error_exit - Prints error message and exits with status 98
 */
void error_exit(void)
{
char *error = "Error\n";
int i = 0;

while (error[i])
{
_putchar(error[i]);
i++;
}
exit(98);
}
/**
 * print_result - Prints the result of the multiplication
 * @result: Array containing the multiplication result
 * @len: Length of the result
 */
void print_result(int *result, int len)
{
int i, start = 0;
  /* Skip leading zeros */
for (i = 0; i < len - 1; i++)
{
if (result[i] != 0)
{
start = 1;
}
if (start)
_putchar(result[i] + '0');
}
  /* Always print last digit */
_putchar(result[len - 1] + '0');
_putchar('\n');
}
/**
 * main - Entry point, multiplies two positive numbers
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
char *num1, *num2;
int len1, len2, len_result, i, j, digit1, digit2, carry, product;
int *result;
  /* Check number of arguments */
if (argc != 3)
error_exit();
num1 = argv[1];
num2 = argv[2];
  /* Check if arguments contain only digits */
if (!is_digit(num1) || !is_digit(num2))
error_exit();

len1 = _strlen(num1);
len2 = _strlen(num2);
len_result = len1 + len2;
  /* Allocate memory for result */
result = malloc(sizeof(int) * len_result);
if (result == NULL)
error_exit();
  /* Initialize result array with zeros */
for (i = 0; i < len_result; i++)
result[i] = 0;
  /* Multiplication algorithm */
for (i = len1 - 1; i >= 0; i--)
{
carry = 0;
digit1 = num1[i] - '0';
for (j = len2 - 1; j >= 0; j--)
{
digit2 = num2[j] - '0';
product = (digit1 * digit2) + result[i+j+1] +carry;
carry = product / 10;
result[i + j + 1] = product % 10;
}
result[i] += carry;
}
  /* Print result */
print_result(result, len_result);
free(result);
return (0);
}
