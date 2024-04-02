# About
This is a code that I made to implement linked lists.

| filename | description |
| ----------- | ----------- |
| linked.h | header files |
| linked.c | code that implements the functions |
| test.c | code for testing |

# Structures
There's currently two structures.

## entry structure
```
typedef struct node NODE;
```

This structure contains the data, address to the next entry, the previous entry, and then the address to the header. The header address is NULL when it's not the initial entry. 
## header structure
```
typedef struct node_header NODE_HEADER;
```
This structure contains the name of the list, and then the address to the first entry.
# Functions
As of now, 5 functions are implemented.

| function | args | description |
| ---------- | ----------- | ------------ |
| init\_node | name, data | takes in the name of the list and data and creates a linked list with one entry. |
| add\_node | previous entry, data | appends an entry at the back of the list. |
| node\_seek | entry, offset | moves the cursor from the current position to another. |
| remove\_node | header, offset | removes an entry. |
| flush\_list | header | removes the entire list. | 
 
