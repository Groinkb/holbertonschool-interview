#!/usr/bin/python3
"""
    Determines if a given data set represents a valid UTF-8 encoding.

    Args:
    - data (list): A list of integers representing individual bytes of data.

    Returns:
    - bool: True if data is a valid UTF-8 encoding, otherwise False.
"""


def validUTF8(data):
    num_bytes = 0

    for byte in data:
        if num_bytes == 0:
            if byte >> 7 == 0:  # Single byte character (0xxxxxxx)
                num_bytes = 0
            elif byte >> 5 == 0b110:  # Two byte character (110xxxxx)
                num_bytes = 1
            elif byte >> 4 == 0b1110:  # Three byte character (1110xxxx)
                num_bytes = 2
            elif byte >> 3 == 0b11110:  # Four byte character (11110xxx)
                num_bytes = 3
            else:
                return False
        else:
            if byte >> 6 != 0b10:  # Continuation byte (10xxxxxx)
                return False
            num_bytes -= 1

    return num_bytes == 0
