# Island Perimeter

This project implements a function to calculate the perimeter of an island in a grid.

## Requirements

### General
- Allowed editors: `vi`, `vim`, `emacs`
- All files will be interpreted/compiled on Ubuntu 14.04 LTS using `python3` (version 3.4.3)
- All files should end with a new line
- The first line of all files should be exactly `#!/usr/bin/python3`
- Code should use the `PEP 8` style (version 1.7)
- No module imports allowed
- All modules and functions must be documented
- All files must be executable

## Task: Island Perimeter

### Description
Create a function `island_perimeter(grid)` that returns the perimeter of the island described in `grid`.

### Parameters
- `grid` is a list of list of integers:
  - 0 represents water
  - 1 represents land
  - Each cell is square, with a side length of 1
  - Cells are connected horizontally/vertically (not diagonally)
  - `grid` is rectangular, with its width and height not exceeding 100
  - The grid is completely surrounded by water
  - There is only one island (or nothing)
  - The island doesn't have "lakes" (water inside that isn't connected to the water surrounding the island)

### Return Value
- The perimeter of the island (integer)

### Example

```python
grid = [
    [0, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0]
]
island_perimeter(grid)  # Returns: 12
```

## Algorithm Approach

The algorithm calculates the perimeter by examining each land cell (represented by 1 in the grid) and counting its adjacent water cells or borders:

1. Iterate through each cell in the grid.
2. When a land cell (1) is found, check all four sides:
   - If a side is adjacent to water (0) or is at the grid boundary, add 1 to the perimeter.
   - For each land cell, check top, left, right, and bottom neighbors.
3. Return the total perimeter count.

The implementation has O(n×m) time complexity, where n and m are the dimensions of the grid.

## Author
BM