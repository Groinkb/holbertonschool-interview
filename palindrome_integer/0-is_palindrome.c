#include "palindrome.h"

/**
 * reverse_number - Reverses an unsigned long integer
 * @n: Number to reverse
 *
 * Return: The reversed number
 */
unsigned long reverse_number(unsigned long n)
{
    unsigned long reversed = 0;
    unsigned long original = n;

    while (original > 0)
    {
        reversed = reversed * 10 + (original % 10);
        original /= 10;
    }

    return (reversed);
}

/**
 * is_palindrome - Checks if an unsigned integer is a palindrome
 * @n: Number to check
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
    unsigned long reversed;

    /* Single digit numbers are always palindromes */
    if (n < 10)
        return (1);

    reversed = reverse_number(n);

    /* If reversed equals original, it's a palindrome */
    return (n == reversed);
}