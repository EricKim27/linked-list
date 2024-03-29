#define MAX_CHAR_LENGTH 1024
#define INITIAL_NODE(node_header) ((node_header)->next)

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

//functions that manipulates linked lists.
NODE_HEADER *init_node(char* name);
NODE *add_node_to_header(NODE_HEADER *header, char *data[MAX_CHAR_LENGTH]);
NODE *add_node(NODE *prev_node, char *data[MAX_CHAR_LENGTH]);
void node_seek(NODE* node, int offset);