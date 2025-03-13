#!/usr/bin/python3
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
                # Parse using regex to ensure format is correct
                match = re.match(
                    r'^\S+ - \[.*\] "GET /projects/260 HTTP/1\.1" (\d+) (\d+)$', 
                    line.strip()
                )
                
                if match:
                    status_code = match.group(1)
                    file_size = int(match.group(2))
                    
                    # Only update stats if status code is in our list
                    if status_code in codes:
                        codes[status_code] += 1
                    
                    # Always update file sizee for valid format
                    size += file_size
            except (ValueError, IndexError):
                # Skip lines that don't match the expected format
                pass
            
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