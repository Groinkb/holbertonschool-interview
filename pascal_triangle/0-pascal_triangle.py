#!/usr/bin/python3
"""
Module for pascal_triangle function
"""


def pascal_triangle(n):
    """
    Returns a list of lists of integers representing Pascal's triangle of n.

    Args:
        n (int): The number of rows in the triangle

    Returns:
        list: A list of lists representing Pascal's triangle,
              empty list if n <= 0
    """
    if n <= 0:
        return []

    # Initialize triangle with first row
    triangle = [[1]]

    # Generate each row based on the previous row
    for i in range(1, n):
        # Start with 1 (first element of each row is always 1)
        row = [1]

        # Get the previous row
        prev_row = triangle[i - 1]

        # Calculate middle elements using the sum of the two numbers above
        for j in range(1, i):
            row.append(prev_row[j - 1] + prev_row[j])

        # End with 1 (last element of each row is always 1)
        row.append(1)

        # Add the row to the triangle
        triangle.append(row)

    return triangle
