#!/usr/bin/python3
"""
A module that queries the  the occurrences of  keywords
in the titles of hot articles for a given subreddit.
"""
import requests


def count_words(subreddit, word_list, after=None, count_dict=None):
    """
    Recursively queries the Reddit API 
    Args:
        subreddit (str): The subreddit to search in.
        word_list (list): List of keywords to count.
        after (str, optional): Token 
        count_dict (dict, optional):  
    Returns:
        None: Prints the results as per the requirements.
    """
    # Initialize count_dict on first call
    if count_dict is None:
        count_dict = {}
        # Convert word_list to lowercase and create dictionary with set to 0
        for word in word_list:
            word_lower = word.lower()
            if word_lower in count_dict:
                continue
            count_dict[word_lower] = 0
    # Base URL for Reddit API
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    # Set user agent to avoid too many requests error
    headers = {"User-Agent": "linux:0-count:v1.0 (by /u/holbertonschool)"}
    # Parameters for the API request
    params = {"limit": 100}
    if after:
        params["after"] = after
    # Make the request to the Reddit API
    response = requests.get(url, headers=headers, params=params,
                             allow_redirects=False)
    # If the subreddit is invalid , return without printing
    if response.status_code != 200:
        return
    # Parse response data
    data = response.json().get("data", {})
    children = data.get("children", [])
    after = data.get("after")
    # Process titles of posts and count keywords
    for child in children:
        title = child.get("data", {}).get("title", "").lower()
        # Split title into words
        words = title.split()
        # Count occurrences of each keyword in the title
        for word in words:
            # Remove any punctuation attached to the word
            cleaned_word = ''.join(c for c in word if c.isalnum())
            
            # Check if the cleaned word is in our word_list
            for keyword in count_dict:
                if cleaned_word == keyword:
                    count_dict[keyword] += 1
    # If there are more posts a call
    if after:
        return count_words(subreddit, word_list, after, count_dict)
    else:
        # Printg order by count, then alphabetically
        sorted_counts = sorted(count_dict.items(), key=lambda x: (-x[1], x[0]))
        # Print only keywords with counts > 0
        for keyword, count in sorted_counts:
            if count > 0:
                print("{}: {}".format(keyword, count))
