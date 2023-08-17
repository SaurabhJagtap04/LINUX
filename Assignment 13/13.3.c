// Program that creates such a process that 
// accepts signals from the terminal

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void ex1();
void ex2();
void ex3();

int main()
{
    signal(SIGHUP, ex1);
    signal(SIGINT, ex2);
    signal(SIGQUIT, ex3);

    for(;;); 
}

void ex1()
{
    signal(SIGHUP, ex1);
    printf("Signal received from SIGHUP.\n");
}

void ex2()
{
    signal(SIGINT, ex1);
    printf("Signal received from SIGINT.\n");
    exit(0);
}

void ex3()
{
    signal(SIGQUIT, ex1);
    printf("Killing process.\n");
    exit(0);
}


/*
    In other terminal, get process Id by using command 'ps'.

    Enter following commands after getting process ID

    kill <pid> SIGHUP

    kill <pid> SIGINT

    kill <pid> SIGQUUIT

*/