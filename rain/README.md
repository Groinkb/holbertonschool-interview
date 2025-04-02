# Rain

## Description
This project contains a solution to the rainwater trapping problem. Given a list of non-negative integers representing the heights of walls with unit width 1, the program calculates how many square units of water will be retained after it rains.

## Requirements
- All files are interpreted/compiled on Ubuntu 14.04 LTS using `python3` (version 3.4.3)
- All files end with a new line
- The first line of all files is exactly `#!/usr/bin/python3`
- Code follows the `PEP 8` style guide (version 1.7.x)
- No imported modules are used
- All modules and functions are documented
- All files are executable

## Task: Rain
Write a function `rain(walls)` that calculates how many square units of water will be retained after it rains.

### Prototype
```python
def rain(walls)
```

### Parameters
- `walls`: a list of non-negative integers representing wall heights

### Return
- Integer indicating total amount of rainwater retained
- If the list is empty, return `0`

### Notes
- Assume that the ends of the list (before index 0 and after index walls[-1]) are not walls, meaning they will not retain water

## Algorithm
The solution uses a two-pointer approach to efficiently calculate the trapped water:
1. Initialize pointers at the left and right ends of the array
2. Track the maximum height seen from both sides
3. Move the pointer from the side with the smaller height inward
4. Add trapped water at each position based on the difference between the current height and the maximum height seen from that side

This approach has a time complexity of O(n) and a space complexity of O(1), where n is the length of the input array.

## Example
```
walls = [0, 1, 0, 2, 0, 3, 0, 4]
rain(walls) => 6

walls = [2, 0, 0, 4, 0, 0, 1, 0]
rain(walls) => 6
```

## File Structure
- `0-rain.py`: Contains the implementation of the `rain` function
- `README.md`: This file, containing information about the project

## Author
BM

