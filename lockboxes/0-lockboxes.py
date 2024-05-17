#!/usr/bin/python3
"""
17/01/2024
0-lockboxes.py
BM
"""


def canUnlockAll(boxes):
    """
    Determines if all the boxes can be opened.
    Args:
        boxes: List of list
    Returns:
        True or false
    """
    if not boxes or not boxes[0]:
        return False

    n = len(boxes)
    keys = set(boxes[0])
    opened_boxes = {0}

    while keys:
        box_number = keys.pop()
        if box_number < n and box_number not in opened_boxes:
            opened_boxes.add(box_number)
            keys.update(boxes[box_number])

    return len(opened_boxes) == n