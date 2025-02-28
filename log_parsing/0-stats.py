#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics.

This script processes log entries from standard input and calculates:
    - Total file size
    - Count of each HTTP status code
"""

import sys


def print_stats(size, codes):
    """Print the statistics"""
    print("File size: {}".format(size))
    for code in sorted(codes.keys()):
        if codes[code] > 0:
            print("{}: {}".format(code, codes[code]))


def process_metrics():
    """Process the input and compute metrics"""
    size = 0
    count = 0
    codes = {
        200: 0, 301: 0, 400: 0, 401: 0,
        403: 0, 404: 0, 405: 0, 500: 0
    }

    try:
        for line in sys.stdin:
            try:
                parts = line.split()
                if len(parts) >= 2:
                    status_code = int(parts[-2])
                    file_size = int(parts[-1])
                    if status_code in codes:
                        codes[status_code] += 1
                        size += file_size
                        count += 1

                    if count % 10 == 0:
                        print_stats(size, codes)
            except:
                continue

        print_stats(size, codes)

    except KeyboardInterrupt:
        print_stats(size, codes)
        raise


if __name__ == "__main__":
    process_metrics()