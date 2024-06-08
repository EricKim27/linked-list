#include "linked.h"
#include <string.h>
#include <stdlib.h>

NODE_HEADER *init_node(char* name, void *data, dtype_t type)
{
    NODE_HEADER* header = (NODE_HEADER*)malloc(sizeof(NODE_HEADER));
    strncpy(header->list_name, name, sizeof(header->list_name) - 1);
    header->list_name[sizeof(header->list_name) - 1] = '\0';
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->type = type;
    switch(type)
    {
        case INT:
            node->data.int_data = *(int*)data;
            break;
        case DOUBLE:
            node->data.int_data = *(double*)data;
            break;
        case CHAR:
            strncpy(node->data.char_data, (char*)data, sizeof(node->data.char_data) - 1);
            node->data.char_data[sizeof(node->data.char_data) - 1] = '\0';
            break;
    }
    node->prev_header = header;
    node->next = NULL;
    header->next = node;
    return header;
}
NODE *add_node(NODE *prev_node, void *data, dtype_t type)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->next = NULL;
    node->prev = prev_node;
    node->prev_header = NULL;
    prev_node->next = node;
    node->type = type;
    switch(type)
    {
        case INT:
            node->data.int_data = *(int*)data;
            break;
        case CHAR:
            strncpy(node->data.char_data, (char*)data, sizeof(node->data.char_data) - 1);
            node->data.char_data[sizeof(node->data.char_data) - 1] = '\0';
            break;
        case DOUBLE:
            node->data.double_data = *(double*)data;
            break;
    }
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
            } else 
            {
                break;
            }
        }
    } else
    {
        for(int i = 0; i<abs(offset); i++)
        {
            if(cursor->prev != NULL){
                cursor = cursor->prev;
            } else
                break;
        }
    }
    return cursor;
}

void inline node_seek(NODE **node, int offset)
{
    *node = move_node_cursor(*node, offset);
}

void flush_list(NODE_HEADER *header)
{
    NODE *node = INITIAL_NODE(header);
    while(node != NULL)
    {
        NODE *next_node = node->next;
        free(node);
        node = next_node;
    }
    node = NULL;
    free(header);
}
void remove_node(NODE_HEADER *header, int offset)
{
    NODE *node = INITIAL_NODE(header);
    node_seek(&node, offset - 1);
    if(node == NULL)
        return;
    if(node->prev != NULL)
        node->prev->next = node->next;
    else
        header->next = node->next;
    if(node->next != NULL)
        node->next->prev = node->prev;
    free(node);
}
