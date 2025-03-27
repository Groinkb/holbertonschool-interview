#!/usr/bin/python3
# -*- coding: utf-8 -*-
# File mode: 0755
"""
N-Queens Problem Solver

This module solves the N-Queens problem: placing N non-attacking queens
on an N×N chessboard.
"""

import sys


def is_safe(board, row, col, n):
    """
    Check if it's safe to place a queen at board[row][col]

    Args:
        board: 2D array representing the chessboard
        row: Row to check
        col: Column to check
        n: Size of the board

    Returns:
        True if it's safe to place a queen, False otherwise
    """
    # Check this row on left side
    for i in range(col):
        if board[row][i] == 1:
            return False

    # Check upper diagonal on left side
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    # Check lower diagonal on left side
    for i, j in zip(range(row, n, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True


def solve_nqueens_util(board, col, n, solutions):
    """
    Recursive utility function to solve N-Queens problem

    Args:
        board: 2D array representing the chessboard
        col: Current column to consider
        n: Size of the board
        solutions: List to store the solutions

    Returns:
        True if a solution is found, False otherwise
    """
    # Base case: If all queens are placed
    if col >= n:
        solution = []
        for i in range(n):
            for j in range(n):
                if board[i][j] == 1:
                    solution.append([i, j])
        solutions.append(solution)
        return True

    # Try placing queen in each row of the current column
    res = False
    for i in range(n):
        if is_safe(board, i, col, n):
            # Place this queen in board[i][col]
            board[i][col] = 1

            # Recur to place queens in the rest of the columns
            # Don't shortcut even if we found a solution
            new_res = solve_nqueens_util(board, col + 1, n, solutions)
            res = new_res or res

            # Backtrack: remove the queen from board[i][col]
            board[i][col] = 0

    return res


def solve_nqueens(n):
    """
    Solve the N-Queens problem and print all solutions

    Args:
        n: Size of the board and number of queens
    """
    # Initialize the board
    board = [[0 for _ in range(n)] for _ in range(n)]

    # List to store the solutions
    solutions = []

    # Solve the problem
    solve_nqueens_util(board, 0, n, solutions)

    # Print the solutions in the required format
    for solution in solutions:
        print(solution)


if __name__ == "__main__":
    # Check for correct number of arguments
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    # Try