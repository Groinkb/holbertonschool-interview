# Count It!

This project contains a Python function that queries the Reddit API to count the occurrences of specific keywords in the titles of hot articles for a given subreddit.

## Requirements

* Ubuntu 14.04 LTS
* Python 3.4.3
* PEP 8 style
* Requests module

## Task Description

The main task is to implement a recursive function that:

1. Queries the Reddit API for hot articles in a specified subreddit
2. Parses the titles of these articles
3. Counts occurrences of given keywords (case-insensitive)
4. Prints the results in descending order by count, and alphabetically for equal counts

### Specifications

* Function prototype: `def count_words(subreddit, word_list)`
* Words are counted case-insensitively (e.g., "Java" and "java" count as the same word)
* Keywords must be matched exactly (e.g., "java" should not match "javascript")
* Words with punctuation (like "java." or "java!") don't count as matches
* Results are based on the number of occurrences, not the number of titles containing the word
* If no posts match or the subreddit is invalid, nothing is printed
* The function must be implemented recursively (loops are not allowed for the recursion part)

## Files

* `0-count.py`: Contains the `count_words` function implementation
* `0-main.py`: Test script to demonstrate the functionality

## Usage

```bash
python3 0-main.py <subreddit> '<list of keywords>'
```

### Example

```bash
python3 0-main.py programming 'python java javascript'
```

## Implementation Details

The implementation uses the Reddit API to fetch hot posts from a specified subreddit. It performs pagination using the "after" parameter to fetch all available posts recursively. For each post, it processes the title and counts occurrences of the specified keywords.

The API requests are made with a custom User-Agent to avoid rate limiting issues, and the function handles invalid subreddits gracefully by checking the response status code.


## Author
BM

