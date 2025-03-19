#!/usr/bin/python3
"""
UTF-8 Validation module
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding

    Args:
        data: A list of integers where each integer represents 1 byte of data

    Returns:
        True if data is a valid UTF-8 encoding, else False
    """
    # Number of bytes still to process in current UTF-8 character
    remaining_bytes = 0

    # Check each byte (represented as an integer)
    for byte in data:
        # Keep only the 8 least significant bits of each integer
        byte = byte & 0xFF

        # If we're not processing a multi-byte character
        if remaining_bytes == 0:
            # Single byte character (0xxxxxxx)
            if byte >> 7 == 0:
                continue
            # 2-byte character (110xxxxx)
            elif byte >> 5 == 0b110:
                remaining_bytes = 1
            # 3-byte character (1110xxxx)
            elif byte >> 4 == 0b1110:
                remaining_bytes = 2
            # 4-byte character (11110xxx)
            elif byte >> 3 == 0b11110:
                remaining_bytes = 3
            # Invalid UTF-8 start byte
            else:
                return False
        # If we're processing continuation bytes (10xxxxxx)
        else:
            # Check if this byte is a continuation byte
            if byte >> 6 != 0b10:
                return False
            # Decrement the counter of remaining bytes
            remaining_bytes -= 1

    # If we've processed all bytes and there are no remaining bytes to process
    # then the data is valid UTF-8
    return remaining_bytes == 0
