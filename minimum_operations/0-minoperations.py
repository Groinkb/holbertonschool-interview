#!/usr/bin/python3
"""
Module that contains the minOperations function
"""


def minOperations(n):
    """
    Calculates the fewest number of operations needed to result in exactly n H
    characters in the file.

    Args:
        n (int): The target number of H characters

    Returns:
        int: The minimum number of operations needed to get n H characters
             Returns 0 if n is impossible to achieve
    """
    if n <= 1:
        return 0

    operations = 0
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1

        # Optimization: if divisor squared is greater than n,
        # then n is prime (if it's greater than 1)
        if divisor * divisor > n and n > 1:
            operations += n
            break

    return operations
