#!/usr/bin/python3
# -*- coding: utf-8 -*-
# File mode: 0755
"""
Script that reads stdin line by line and computes metrics.

This script processes log entries from standard input and calculates:
    - Total file size
    - Count of each HTTP status code
"""

import sys
import re


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
        "200": 0, "301": 0, "400": 0, "401": 0,
        "403": 0, "404": 0, "405": 0, "500": 0
    }

    try:
        for line in sys.stdin:
            count += 1
            try:
                # Parse the line to extract status code and file size
                parts = line.split()
                if len(parts) > 2:
                    # The status code is the second-to-last element
                    # The file size is the last element
                    try:
                        status_code = parts[-2]
                        file_size = int(parts[-1])
                        
                        # Check if this is a valid status code
                        if status_code in codes:
                            codes[status_code] += 1
                        
                        # Always add the file size
                        size += file_size
                    except (ValueError, IndexError):
                        # Skip this line if we can't parse the code or size
                        pass
            except Exception:
                # Skip any line that causes an exception
                continue
            
            # Print stats every 10 lines
            if count % 10 == 0:
                print_stats(size, codes)

        # Print final stats if the loop ends normally
        print_stats(size, codes)

    except KeyboardInterrupt:
        # Print stats on CTRL+C
        print_stats(size, codes)
        raise


if __name__ == "__main__":
    process_metrics()
