#define MAX_CHAR_LENGTH 1024
#define INITIAL_NODE(node_header) ((node_header)->next)

typedef struct node NODE;
typedef struct node_header NODE_HEADER;

typedef struct node {
    char data[MAX_CHAR_LENGTH];
        struct node *next;
        NODE *prev;
        NODE_HEADER *prev_header;
} NODE;

typedef struct node_header {
    char list_name[256];
    NODE *next;
}NODE_HEADER;

//initializes linked list.
NODE_HEADER *init_node(char *name, char data[MAX_CHAR_LENGTH]);

//adds an entry to list.
NODE *add_node(NODE *prev_node, char data[MAX_CHAR_LENGTH]);

//moves the cursor to seek through lists.
void node_seek(NODE** node, int offset);

//flushes the entire list
void flush_node(NODE_HEADER *header);
