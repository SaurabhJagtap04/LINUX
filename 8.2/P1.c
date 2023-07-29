#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int ret = 0;

    printf("Inside Process 2\n");

    ret = fork();

    if(ret == 0)
    {
        execl("./CP2","NULL",NULL);     //Create Process 3  
    }

    return 0;
}