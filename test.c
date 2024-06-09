#include "linked.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#define errExit(msg)    \
  do {                  \
    perror(msg);        \
    exit(EXIT_FAILURE); \
  } while (0)
/*
 * This code is for testing the linked list library that I made.
 * It creates a list then prints the value. 
 * based on the number provided in the arguments, it creates that amount of entries.
 */
NODE_HEADER *test;

static void sigintHandler(int sig) {
  write(STDERR_FILENO, "Caught SIGINT!\n", 15);
}

int main(int argc, char *argv[])
{
    int verbose = 1;
    if(signal(SIGINT, sigintHandler) == SIG_ERR) errExit("interrupted!"); 
    if(argc < 2)
    {
        printf("usage: %s [-v] <number of lists>\n", argv[0]);
        return EXIT_FAILURE;
    } else if(strcmp(argv[1], "help") == 0){
        printf("This program creates a linked list with a number of entries according to the arguments.\n");
        return 0;
    } else if(strcmp(argv[1], "-v") == 0){
        verbose = 0;
    }
    {
        char *name = "example";
        char data[MAX_CHAR_LENGTH];
        char data_to_write[20];
        sprintf(data_to_write, "example data %d", 0);
        strncpy(data, data_to_write, sizeof(data_to_write) - 1);
        data[sizeof(data_to_write) - 1] = '\0';
        test = init_node(name, &data, CHAR);
        NODE *prev_node = test->next;
        NODE *cursor;
        for(int i = 0; i<atoi(argv[argc - 1]); i++)
        {
            sprintf(data_to_write, "example data %d", i + 1);
            strncpy(data, data_to_write, sizeof(data_to_write) - 1);
            data[sizeof(data_to_write) - 1] = '\0';
            cursor = add_node(prev_node, &data, CHAR);
            prev_node = cursor;
        }
        NODE *current = INITIAL_NODE(test);
        while(current->next != NULL)
        {
            printf("Address: %p\n", current);
            if(verbose == 0){
                printf("Current entry value: %s\n", current->data.char_data);
            }
            node_seek(&current, 1);
        }
        flush_list(test);
        return EXIT_SUCCESS;
    }
}
