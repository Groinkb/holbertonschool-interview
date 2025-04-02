#!/usr/bin/python3
"""
Module to calculate how much rainwater is retained after it rains
"""


def rain(walls):
    """
    Calculate how many square units of water will be retained after it rains.

    Args:
        walls (list): A list of non-negative integers representing wall heigh

    Returns:
        int: Total amount of rainwater retained.
    """
    if not walls or len(walls) < 3:
        return 0

    n = len(walls)
    total_water = 0
    left, right = 0, n - 1
    left_max = walls[left]
    right_max = walls[right]

    while left < right:
        if walls[left] < walls[right]:
            # Move from the left
            left += 1
            # Update left_max if current wall is higher
            if walls[left] > left_max:
                left_max = walls[left]
            else:
                # Add water at current position
                total_water += left_max - walls[left]
        else:
            # Move from the right
            right -= 1
            # Update right_max if current wall is higher
            if walls[right] > right_max:
                right_max = walls[right]
            else:
                # Add water at current position
                total_water += right_max - walls[right]

    return total_water
