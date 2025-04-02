#!/usr/bin/python3
"""
Module to count keywords in Reddit post titles using the Reddit API.

This s analyze the titles of
hot posts, and count eywords. The keywords are
case-insensitive, a descending order of
frequency.
"""

import requests
import sys


def count_words(subreddit, word_list, after=None, word_count=None):
    """
    Recursively queries the Reddit API, parses titles of hot articles,
    and counts occurrences of specified keywords.

    Args:
        subreddit (str): The name of  subreddit to query.
        word_list (list): List   to count (case-insensitive).
        after (str, optional):  for pagination. Defaults to None.
        word_count (dict, optional):  keyword counts.  to None.

    Returns:
        None: Prints the  keyword ounts to the console.
    """
    if word_count is None:
        # Initialize word_count with all words from the word_list, set to 0
        word_count = {word.lower(): 0 for word in word_list}

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {'User-Agent': 'MyAPI/0.0.1'}
    params = {'after': after}

    try:
        # Make the API request to fetch hot posts
        response = requests.get(url, headers=headers, params=params,
                                timeout=10)
        if response.status_code != 200:
            return  # Exit if the request fails
        data = response.json()
    except Exception:
        return  # Exit gracefully in case of any error

    # Process titles in the current page
    for post in data['data']['children']:
        title = post['data']['title'].lower()  # Convert title to lowercase
        for word in word_count:
            # Count occurrences in the title
            word_count[word] += title.split().count(word)

    # Recursively fetch the next  available
    after = data['data']['after']
    if after:
        count_words(subreddit, word_list, after, word_count)
    else:
        # Once  processed, sort and print the results
        sorted_results = sorted(
            word_count.items(), key=lambda x: (-x[1], x[0])
        )
        for word, count in sorted_results:
            if count > 0:
                print(f"{word}: {count}")


if __name__ == "__main__":
    """
    Main  point of the script.

    Usage:
        python3 scrpt_name.py <subreddit> <list of keywords>

    Example:
        python3 script_name.py programming 'python java javascript'

    The script expects at least two arguments:
    1. subreddit: 
    2. A space-separated l.
    """
    if len(sys.argv) < 3:
        print(
            "Usage: {} <subreddit> <list of keywords>".format(sys.argv[0])
        )
        print(
            "Example: {} programming 'python java javascript'".format(
                sys.argv[0]
            )
        )
    else:
        # Extract subreddit and word_list from command-line arguments
        subreddit = sys.argv[1]
        word_list = sys.argv[2].split()
        # Start counting words
        count_words(subreddit, word_list)