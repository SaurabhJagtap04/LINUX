// Program that performs interprocess communication
// Using the concept of message queue

//CLIENT CODE

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/msg.h>
#include <stdlib.h>

#define MAX_TEXT 512

struct my_msg_st
{
    long int my_msg_type;
    char some_text[MAX_TEXT];
};

int main()
{
    int running = 1, msgid;
    struct my_msg_st some_data;
    long int msg_to_receive = 0;
    char buffer[BUFSIZ];

    msgid = msgget((key_t)1234, 0666);

    if(msgid == -1)
    {
        printf("Failed to create.\n");
        exit(EXIT_FAILURE);
    }

    printf("Fetching the message from message queue.\n");

    while(running)
    {
        msgrcv(msgid, (void *)&some_data, BUFSIZ, msg_to_receive, 0);

        printf("Received Message : %s\n",some_data.some_text);

        if(strncmp(some_data.some_text,"end", 3) == 0)
        {
            running = 0;
        }
    }

    printf("Terminating the client process\n");

    exit(EXIT_SUCCESS);
}