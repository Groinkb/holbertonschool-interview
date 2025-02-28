#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics.

This script processes log entries from standard input and calculates:
    - Total file size
    - Count of each HTTP status code
"""

import sys


def print_stats(total_size, status_codes):
    """
    Print statistics about the parsed logs.

    Args:
        total_size (int): Total size of files processed
        status_codes (dict): Dictionary with count of status codes

    Returns:
        None
    """
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))


def process_line(line):
    """
    Process a single line of log input.

    Args:
        line (str): Input line to process

    Returns:
        tuple: (status_code, file_size) or None if invalid
    """
    try:
        parts = line.split()
        if len(parts) >= 2:
            return int(parts[-2]), int(parts[-1])
    except (ValueError, IndexError):
        return None
    return None


def main():
    """Main function to process logs."""
    total_size = 0
    status_codes = {
        200: 0, 301: 0, 400: 0, 401: 0,
        403: 0, 404: 0, 405: 0, 500: 0
    }
    count = 0

    try:
        for line in sys.stdin:
            result = process_line(line.strip())
            if result:
                status_code, file_size = result
                if status_code in status_codes:
                    status_codes[status_code] += 1
                    total_size += file_size
                    count += 1

                    if count % 10 == 0:
                        print_stats(total_size, status_codes)

        print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        print_stats(total_size, status_codes)
        sys.exit(0)


if __name__ == "__main__":
    main()