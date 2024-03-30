#include "linked.h"
#include <stdio.h>
#include <stdlib.h>
/*
 * This code is for testing the linked list library that I made.
 * It creates a list then prints the value. 
 * based on the number provided in the arguments, it creates that amount of entries.
 */
int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("usage: %s <number of lists>\n", argv[0]);
        return EXIT_FAILURE;
    } else 
    {
        char *name = "example";
        char *data = "example data";
        NODE_HEADER *test = init_node(name, data);
        NODE *prev_node = test->next;
        NODE *cursor;
        for(int i = 0; i<atoi(argv[1]) - 1; i++)
        {
            cursor = add_node(prev_node, data);
            prev_node = cursor;
        }
        NODE *current = INITIAL_NODE(test);
        while(current->next != NULL)
        {
            printf("Data: %s\n", current->data);
            current = current->next;
        }
        flush_node(test);
        return EXIT_SUCCESS;
    }
}