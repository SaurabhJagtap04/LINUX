//Program that creates three level process hierarchy
//Process 1 creates Process 2
//Process 2 internally creates process 3

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int ret = 0;
    int cpid = 0;
    int Exit_status = 0;

    ret = fork();

    if(ret == 0)        //Child Process
    {
        printf("Inside Process 1\n");
        execl("./CP1","NULL",NULL);     //Create Process 2        
    }
    
    exit(0);
}