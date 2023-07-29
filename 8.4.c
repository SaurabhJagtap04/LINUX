//Program which creates 2 processes
//Parent proccess does not terminate until both the child processes terminate

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int ret1 = 0, ret2 = 0;
    int cpid = 0;
    int Exit_status = 0;

    ret1 = fork();
    ret2 = fork();

    if((ret1 == 0) && (ret2 == 0))
    {
        printf("Process 2 & Process 3 created successfully.\n");
    }
    else
    {
        cpid = wait(&Exit_status);
        if(cpid > 1)
        {
            printf("Procces with pid %d terminated.\n",cpid);
        }
    }


    return 0;
    
}