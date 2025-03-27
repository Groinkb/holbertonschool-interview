# N Queens

## Description
This project implements a solution for the N Queens puzzle - the challenge of placing N non-attacking queens on an N×N chessboard. 

The N Queens problem is a classic example of a constraint satisfaction problem. In chess, a queen can attack any piece that lies in the same row, column, or diagonal as the queen. The challenge is to place N queens on an N×N chessboard such that no two queens attack each other.

## Requirements
- The program must be written in Python
- Only the `sys` module may be imported
- The program should be executable as `./0-nqueens.py N`
- Program accepts one argument: N (the size of the board and number of queens)

## Usage
```
./0-nqueens.py N
```

Where `N` is an integer greater than or equal to 4.

### Error Handling
- If the user calls the program with the wrong number of arguments, it prints `Usage: nqueens N` and exits with status code 1
- If N is not an integer, it prints `N must be a number` and exits with status code 1
- If N is smaller than 4, it prints `N must be at least 4` and exits with status code 1

## Output Format
The program prints every possible solution to the problem. Each solution is represented as a list of queen positions, where each position is a pair [row, column] with both row and column indexed from 0.

Example:
```
[[0, 1], [1, 3], [2, 0], [3, 2]]
```

This means:
- A queen at row 0, column 1
- A queen at row 1, column 3
- A queen at row 2, column 0
- A queen at row 3, column 2

## Algorithm
The solution uses a backtracking algorithm:
1. Start with an empty board
2. Place queens one by one in different columns, starting from the leftmost column
3. When placing a queen, check if it is safe from attack by already placed queens
4. If it is safe, mark this position and recursively place the rest of the queens
5. If placing the remaining queens is not possible, backtrack and try another position
6. Once N queens are placed successfully, add the solution to the list
7. Continue the process to find all possible solutions

## Examples
```
$ ./0-nqueens.py 4
[[0, 1], [1, 3], [2, 0], [3, 2]]
[[0, 2], [1, 0], [2, 3], [3, 1]]

$ ./0-nqueens.py 6
[[0, 1], [1, 3], [2, 5], [3, 0], [4, 2], [5, 4]]
[[0, 2], [1, 5], [2, 1], [3, 4], [4, 0], [5, 3]]
[[0, 3], [1, 0], [2, 4], [3, 1], [4, 5], [5, 2]]
[[0, 4], [1, 2], [2, 0], [3, 5], [4, 3], [5, 1]]
```

## Files
- `0-nqueens.py`: Main program that solves the N Queens problem