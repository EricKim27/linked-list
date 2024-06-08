#ifndef _LINKED_H_
#define _LINKED_H_

#define MAX_CHAR_LENGTH 1024
#define INITIAL_NODE(node_header) ((node_header)->next)
typedef enum {INT, CHAR, DOUBLE} dtype_t;
//structure for a single entry.
typedef struct node NODE;
//structure for a header file of an entry.
typedef struct node_header NODE_HEADER;

typedef struct node {
    union {
        int int_data;
        double double_data;
        char char_data[MAX_CHAR_LENGTH];
    } data;
    dtype_t type;
    struct node *next;
    NODE *prev;
    NODE_HEADER *prev_header;
} NODE;

typedef struct node_header {
    char list_name[256];
    NODE *next;
}NODE_HEADER;

//initializes linked list.
extern NODE_HEADER *init_node(char* name, void *data, dtype_t type);

//adds an entry to list.
extern NODE *add_node(NODE *prev_node, void *data, dtype_t type);

//moves the cursor to seek through lists.
extern inline void node_seek(NODE** node, int offset);

//flushes the entire list.
extern void flush_list(NODE_HEADER *header);

//removes an entry from the list.
extern void remove_node(NODE_HEADER *header, int offset);
#endif