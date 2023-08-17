// Program that creates child process and parent process.
// Parent process will communicate with child process by sending signals.

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void sighup();
void sigint();
void sigquit();

int main()
{
    int pid;

    pid = fork();

    if(pid < 0)
    {
        exit(1);
    }

    if(pid == 0)
    {
        signal(SIGHUP, sighup);
        signal(SIGINT, sigint);
        signal(SIGQUIT, sigquit);
        
        for(;;);
    }
    else
    {
        printf("\nPARENT : sending SIGUP\n\n");
        kill(pid, SIGHUP);
        sleep(2);

        printf("\nPARENT : sending SIGINT\n\n");
        kill(pid, SIGINT);
        sleep(2);

        printf("\nPARENT : sending SIGQUIT\n\n");
        kill(pid, SIGQUIT);
        sleep(2);
    }

    wait(NULL);
}

void sighup()
{
    signal(SIGHUP, sighup);
    printf("CHILD : I have received a SIGHUP\n");
    fflush(stdout);
}
void sigint()
{
    signal(SIGINT, sigint);
    printf("CHILD : I have received a SIGINT\n");
    fflush(stdout);
}

void sigquit()
{
    printf("Parent process kills child\n");
    exit(0);
}
