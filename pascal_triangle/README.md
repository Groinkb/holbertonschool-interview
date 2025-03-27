# Pascal's Triangle

## Description
This project implements a function `pascal_triangle(n)` that returns a list of lists of integers representing Pascal's triangle of height `n`.

Pascal's triangle is a triangular array of binomial coefficients where:
- Each number is the sum of the two numbers above it
- The first and last number in each row is always 1

## Function Specification
```python
def pascal_triangle(n):
    """
    Returns a list of lists of integers representing Pascal's triangle of n.
    
    Args:
        n (int): The number of rows in the triangle
        
    Returns:
        list: A list of lists representing Pascal's triangle, 
              empty list if n <= 0
    """
```

## Examples
### Example 1: Pascal's Triangle with n = 5
```
[1]
[1,1]
[1,2,1]
[1,3,3,1]
[1,4,6,4,1]
```

### Example 2: Pascal's Triangle with n = 0 or negative
```
[]
```

## Mathematical Properties
In Pascal's triangle:
1. Each row starts and ends with 1
2. Each element inside a row is the sum of the two elements above it
3. The i-th row contains the binomial coefficients C(i,j) for j = 0, 1, ..., i

## Implementation Details
The implementation uses an iterative approach to build the triangle row by row:
1. Start with the first row which is always [1]
2. For each new row:
   - Start with 1
   - Calculate the middle elements by adding pairs from the previous row
   - End with 1
   - Add the row to the triangle

## Time and Space Complexity
- Time Complexity: O(n²) - We need to calculate each element in the triangle
- Space Complexity: O(n²) - We store all elements of the triangle

## Testing
The function can be tested using the provided main file:
```python
#!/usr/bin/python3
"""
0-main
"""
pascal_triangle = __import__('0-pascal_triangle').pascal_triangle

def print_triangle(triangle):
    """
    Print the triangle
    """
    for row in triangle:
        print("[{}]".format(",".join([str(x) for x in row])))


if __name__ == "__main__":
    print_triangle(pascal_triangle(5))
```

## Author
BM