# Double Circular Linked List

This project implements functions to manipulate a double circular linked list in C.

## Requirements

### General
- Allowed editors: `vi`, `vim`, `emacs`
- All files will be compiled on Ubuntu 14.04 LTS
- Programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall -Werror -Wextra` and `-pedantic`
- All files should end with a new line
- Code should follow the `Betty` style
- No global variables allowed
- No more than 5 functions per file
- Only allowed C standard library functions are `malloc`, `free`, and `strdup`
- All function prototypes are included in the `list.h` header file

## Data Structure

The project uses the following structure for the doubly linked list nodes:

```c
/**
 * struct List - doubly linked list
 * @str: string - (malloc'ed string)
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */
typedef struct List
{
    char *str;
    struct List *prev;
    struct List *next;
} List;
```

## Functions

### 1. Add a node to the end of a double circular linked list

```c
List *add_node_end(List **list, char *str);
```

**Parameters:**
- `list`: Pointer to the pointer of the head of the list
- `str`: String to be duplicated and stored in the new node

**Return Value:**
- Address of the new node, or NULL on failure

### 2. Add a node to the beginning of a double circular linked list

```c
List *add_node_begin(List **list, char *str);
```

**Parameters:**
- `list`: Pointer to the pointer of the head of the list
- `str`: String to be duplicated and stored in the new node

**Return Value:**
- Address of the new node, or NULL on failure

## Implementation Details

### Circular Doubly Linked List Properties

In a circular doubly linked list:
- The `next` pointer of the last node points to the first node
- The `prev` pointer of the first node points to the last node
- This creates a circular structure where you can traverse the list in both directions indefinitely

### Key Implementation Points

Both functions handle these cases:
- Empty list: When the list is empty, the new node becomes the only node in the list, with both `next` and `prev` pointers pointing to itself
- Non-empty list: Proper connections are established to maintain the circular nature of the list

### Error Handling

The functions include checks for:
- NULL list or string
- Memory allocation failures
- String duplication failures

## Usage Example

```c
List *list = NULL;

// Add nodes to the end
add_node_end(&list, "Holberton");
add_node_end(&list, "School");

// Add nodes to the beginning
add_node_begin(&list, "Hello");
add_node_begin(&list, "World");
```

## Author
BM