#include "linked.h"
#include <string.h>
#include <stdlib.h>

NODE_HEADER *init_node(char* name)
{
    NODE_HEADER* header = (NODE_HEADER*)malloc(sizeof(NODE_HEADER));
    strncpy(header->list_name, name, sizeof(header->list_name) - 1);
    header->list_name[sizeof(header->list_name) - 1] = '\0';
    header->next = NULL;
    return header;
}
NODE *add_node_to_header(NODE_HEADER *header, char *data[MAX_CHAR_LENGTH])
{
    NODE *node;
    node->next = NULL;
    node->prev = NULL;
    strncpy(node->data, data, sizeof(node->data) - 1);
    node->data[sizeof(node->data) - 1] = '\0';
    return node;
}
NODE *add_node(NODE *prev_node, char *data[MAX_CHAR_LENGTH])
{
    NODE *node;
    node->next = NULL;
    node->prev = prev_node;
    node->prev_header = NULL;
    strncpy(node->data, data, sizeof(node->data) - 1);
    node->data[sizeof(node->data) - 1] = '\0';
    return node;
}
NODE *move_node_cursor(NODE *current, int offset)
{
    NODE *cursor = current;
    for(int i = 0; i<offset; i++)
    {
        cursor = cursor->next;
    }
    return cursor;
}