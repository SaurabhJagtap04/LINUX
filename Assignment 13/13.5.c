// Program that creates two processes as sender and receiver
// Sender process sends signal to receiver process

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void ex1();
void ex2();

int main()
{
    int ret1, ret2;
    
    int pid;

    ret1 = fork();

    if(ret1 == 0)
    {
        printf("Inside Receiver Process.\n");
     
        printf("ret1 in receiver (og) : %d\n",getpid());

        signal(SIGINT, ex1);
        signal(SIGQUIT, ex2);
    }
    else
    {
        ret2 = fork();
        
        if(ret2 == 0)
        {
       
        printf("Inside Sender Process.\n");

        printf("ret1 in sender : %d\n",ret1);


        printf("PARENT : Sending singal SIGUP.\n\n");
        kill(ret1, SIGHUP);

        sleep(2);

        printf("PARENT : Sending singal SIGQUIT.\n\n");
        kill(ret1, SIGQUIT);

        sleep(2); 

        }
        else
        {
            wait(NULL);
            wait(NULL);

        }
    }   
}

void ex1()
{
    signal(SIGHUP, ex1);
    printf("CHILD : Received signal SIGHUP.\n");
    fflush(stdout);
}

void ex2()
{
    signal(SIGQUIT, ex2);
    printf("CHILD : Terminating process.\n");
    fflush(stdout);
    exit(0);
}