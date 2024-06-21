#include <stdio.h>
#include "palindrome.h"

/**
 * is_palindrome - Checks whether or not a given unsigned integer
 *				is a palindrome
 *
 * @n: The number to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0;
	unsigned long original = n;

	/* Reversing the number */
	while (n != 0)
	{
		reversed = reversed * 10 + n % 10;
		n /= 10;
	}

	/* Checking if the reversed number is equal to the original number */
	if (original == reversed)
		return (1); /* It's a palindrome */
	else
		return (0); /* It's not a palindrome */
}
