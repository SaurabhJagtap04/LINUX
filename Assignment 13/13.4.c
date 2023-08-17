// Program that accepts user defined signal from terminal

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void ex1();
void ex2();

int main()
{
    int MY_SIGNAL = SIGRTMIN + 1;


    signal(MY_SIGNAL, ex1);
    signal(SIGQUIT, ex2);

    for(;;);
}

void ex1()
{

    printf("User Defines Signal Received from terminal.\n");
}

void ex2()
{
    signal(SIGQUIT, ex2);
    printf("Terminating Process.\n");
    exit(0);
}

/*
    In terminal get process id.

    Enter command : kill -SIGRTMIN+1 <pid>
*/