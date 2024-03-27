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