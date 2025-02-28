# Linked List Palindrome

## Description
This project contains a C function that checks if a singly linked list is a palindrome. A palindrome is a sequence that reads the same forwards and backwards.

## Requirements
### General
- **Allowed editors**: vi, vim, emacs
- **Compilation**: Ubuntu 14.04 LTS, gcc 4.8.4
- **Compiler flags**: -Wall -Werror -Wextra -pedantic
- **Coding style**: Betty style
- **Restrictions**:
  - No global variables
  - Maximum 5 functions per file
  - No Google searches allowed during the interview

## Function Prototype
```c
int is_palindrome(listint_t **head);
```

### Parameters
- `head`: Double pointer to the head of the linked list

### Return Value
- `1`: If the linked list is a palindrome
- `0`: If the linked list is not a palindrome

### Note
- An empty list is considered a palindrome

## Data Structure
```c
/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;
```

## Example
```c
listint_t *head = NULL;
add_nodeint_end(&head, 1);
add_nodeint_end(&head, 17);
add_nodeint_end(&head, 972);
add_nodeint_end(&head, 50);
add_nodeint_end(&head, 98);
add_nodeint_end(&head, 98);
add_nodeint_end(&head, 50);
add_nodeint_end(&head, 972);
add_nodeint_end(&head, 17);
add_nodeint_end(&head, 1);

// Should return 1 (is palindrome)
is_palindrome(&head);
```

## Project Structure
linked_list_palindrome/
├── 0-is_palindrome.c
├── lists.h
└── README.md

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-is_palindrome.c -o palindrome
```

## Author
[Groink]

## License
This project is part of the Holberton School curriculum.

