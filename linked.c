#include "linked.h"
#include <string.h>
#include <stdlib.h>

NODE_HEADER *init_node(char* name, char data[MAX_CHAR_LENGTH])
{
    NODE_HEADER* header = (NODE_HEADER*)malloc(sizeof(NODE_HEADER));
    strncpy(header->list_name, name, sizeof(header->list_name) - 1);
    header->list_name[sizeof(header->list_name) - 1] = '\0';
    NODE *node = (NODE*)malloc(sizeof(NODE));
    strncpy(node->data, data, sizeof(node->data) - 1);
    node->data[sizeof(node->data) - 1] = '\0';
    node->prev = header;
    node->next = NULL;
    header->next = node;
    return header;
}
NODE *add_node(NODE *prev_node, char data[MAX_CHAR_LENGTH])
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->next = NULL;
    node->prev = prev_node;
    node->prev_header = NULL;
    strncpy(node->data, data, sizeof(node->data) - 1);
    node->data[sizeof(node->data) - 1] = '\0';
    return node;
}

//a static function that moves the cursor.
static NODE *move_node_cursor(NODE *current, int offset)
{
    NODE *cursor = current;
    if(offset > 0)
    {
        for(int i = 0; i<offset; i++)
        {
            if(cursor->next != NULL)
            {
                cursor = cursor->next;
            }
        }
    } else
    {
        for(int i = 0; i<abs(offset); i++)
        {
            if(cursor->prev != NULL){
                cursor = cursor->prev;
            }
        }
    }
    return cursor;
}

void node_seek(NODE **node, int offset)
{
    node = move_node_cursor(node, offset);
}

void flush_list(NODE_HEADER *header)
{
    NODE *node = INITIAL_NODE(header);
    while(node->next != NULL)
    {
        NODE *node_cur = node;
        NODE *node = node->next;
        free(node_cur);
    }
    free(header);
}