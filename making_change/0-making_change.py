#!/usr/bin/python3
"""
Module for determining the fewest number of coins needed to meet a given amount
"""


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet a given amount total.

    Args:
        coins: List of values of coins available
        total: Target amount

    Returns:
        Fewest number of coins needed to meet total
        0 if total is 0 or less
        -1 if total cannot be met by any number of coins
    """
    # Handle edge cases
    if total <= 0:
        return 0

    # Initialize dp array with infinity except for dp[0] which is 0
    # (it takes 0 coins to make 0 change)
    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    # For each coin value, update the dp array
    for coin in coins:
        for amount in range(coin, total + 1):
            # If we can use the current coin to make change
            # and it results in fewer coins than the current best solution
            dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    # If dp[total] is still infinity, it means total cannot be met
    return dp[total] if dp[total] != float('inf') else -1
