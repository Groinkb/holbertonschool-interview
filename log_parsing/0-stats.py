#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics.  Vindieu tu vas marcher oui 
"""

import sys
import re


def print_stats(total_size, status_codes):
    """
    Print statistics about the parsed logs
    Args:
        total_size: Total size of files
        status_codes: Dictionary with count of status codes
    """
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))


def main():
    """Main function to process the logs"""
    total_size = 0
    line_count = 0
    status_codes = {
        200: 0, 301: 0, 400: 0, 401: 0,
        403: 0, 404: 0, 405: 0, 500: 0
    }

    pattern = r'^\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3} - \[\d{4}-\d{2}-\d{2} ' \
              r'\d{2}:\d{2}:\d{2}\.\d+\] "GET /projects/260 HTTP/1.1" ' \
              r'(\d{3}) (\d+)$'

    try:
        for line in sys.stdin:
            line = line.strip()
            match = re.match(pattern, line)

            if match:
                status_code = int(match.group(1))
                file_size = int(match.group(2))

                # Update metrics
                if status_code in status_codes:
                    status_codes[status_code] += 1
                total_size += file_size
                line_count += 1

                # Print stats every 10 lines
                if line_count % 10 == 0:
                    print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        # Handle CTRL+C
        print_stats(total_size, status_codes)
        raise

if __name__ == "__main__":
    main()
