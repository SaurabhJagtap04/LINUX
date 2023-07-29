//Program in which parent process waits till its child process termuinates

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/wait.h>

int main()
{
    int ret = 0;
    int cpid = 0;
    int exit_status = 0;

    ret = fork();

    if(ret == 0)
    {
        execl("./ChildProcess","NULL",NULL);
    }
    else
    {
        cpid = wait(exit_status);   //Parent waits till it receives signal from child

        printf("Child Process terminated with PID %d and exit status %d\n",cpid,exit_status);
    }

    return 0;
}