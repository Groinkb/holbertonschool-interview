#!/usr/bin/python3
"""
Module to calculate the perimeter of an island in a grid.
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in grid.

    Args:
        grid (List[List[int]]): A list of list of integers where:
            - 0 represents water
            - 1 represents land

    Returns:
        int: The perimeter of the island

    Notes:
        - Each cell is square with side length of 1
        - Cells are connected horizontally/vertically (not diagonally)
        - The grid is completely surrounded by water
        - There is only one island (or nothing)
        - The island doesn't have "lakes"
    """
    if not grid:
        return 0

    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 1:
                # Check each land cell for adjacent water cells or borders
                # Each water cell or border contributes 1 to the perimeter

                # Check top side
                if r == 0 or grid[r-1][c] == 0:
                    perimeter += 1

                # Check left side
                if c == 0 or grid[r][c-1] == 0:
                    perimeter += 1

                # Check right side
                if c == cols-1 or grid[r][c+1] == 0:
                    perimeter += 1

                # Check bottom side
                if r == rows-1 or grid[r+1][c] == 0:
                    perimeter += 1

    return perimeter