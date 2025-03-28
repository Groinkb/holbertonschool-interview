# Making Change

## Description
This project contains a solution to the coin change problem: determining the fewest number of coins needed to meet a given amount total.

## Problem Statement
Given a pile of coins of different values, determine the fewest number of coins needed to meet a given amount `total`.

## Requirements
- All files interpreted/compiled on Ubuntu 14.04 LTS using `python3` (version 3.4.3)
- All files should end with a new line
- The first line of all files should be exactly `#!/usr/bin/python3`
- Code should use the `PEP 8` style (version 1.7.x)
- All files must be executable

## Files
- `0-making_change.py`: Contains the solution to the problem
- `0-main.py`: Example main file for testing

## Function
- `makeChange(coins, total)`: Determines the fewest number of coins needed to meet `total`
  - Returns: Fewest number of coins needed to meet `total`
  - If `total` is `0` or less, returns `0`
  - If `total` cannot be met by any number of coins, returns `-1`
  - `coins` is a list of the values of the coins in your possession
  - The value of a coin will always be an integer greater than `0`
  - You can assume you have an infinite number of each denomination of coin in the list

## Algorithm
The solution uses dynamic programming to solve the problem efficiently.

## Author
BM