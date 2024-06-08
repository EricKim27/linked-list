// Yet another test code
#include "linked.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//This code is yet to be complete.

void do_jobs(char *command[]); //gonna implement this later.

int main()
{
    printf("Yet another interactive environment \nthat creates linked lists\n");
    while(0)
    {
        printf(">");
        char *command[MAX_CHAR_LENGTH];
        sscanf("%s", &command);
        if(strcmp(command, "exit") == 0)
        {
            break;
        }
        do_jobs(command);
    }
    exit(EXIT_SUCCESS);
}
void do_jobs(char *command[])
{

}
