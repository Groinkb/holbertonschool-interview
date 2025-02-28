# Log Parsing

## Description
This project involves creating a script that reads log data from stdin line by line and computes metrics. The script processes log entries in a specific format and outputs statistical information about file sizes and HTTP status codes.

## Requirements
### General
- **Allowed editors**: vi, vim, emacs
- **Environment**: Ubuntu 14.04 LTS
- **Python version**: Python 3.4.3
- **Style guide**: PEP 8 (version 1.7.x)
- **File requirements**:
  - All files must be executable
  - All files should end with a new line
  - First line must be exactly `#!/usr/bin/python3`

## Task: Log Parsing

### Input Format
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>

- Lines not matching this format must be skipped

### Output Requirements
After every 10 lines and/or a keyboard interruption (CTRL + C), print:
1. Total file size: `File size: <total size>`
2. Number of lines by status code in ascending order:
   - Possible status codes: 200, 301, 400, 401, 403, 404, 405, and 500
   - Format: `<status code>: <number>`
   - Only print status codes that have appeared and are integers

### Example
File size: 5213
200: 2
401: 1
403: 2
404: 1
405: 1
500: 3

## Project Structure
```
log_parsing/
├── 0-stats.py     - Main script implementation
└── README.md      - Project documentation
```

## Usage
```bash
./0-generator.py | ./0-stats.py
```

### Sample Output
```
File size: 5213
200: 2
401: 1
403: 2
404: 1
405: 1
500: 3
[...]
```

## Notes
- The script must handle keyboard interruption (CTRL + C) gracefully
- The script should process input line by line to handle large log files
- Status codes should only be counted if they are valid integers
- The total file size is the sum of all individual file sizes in the processed lines

## Author
[Groink]

## License
This project is part of the Holberton School curriculum.