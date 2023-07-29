//Program that creates 3 different processes internally.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int ret = 0;
    int iCnt = 0;
    int ProcessNos = 3;       //ProcessNos = Number of Processes to create

    for(iCnt = 1; iCnt <= ProcessNos; iCnt++)
    {
        ret = fork();

        if(ret == 0)
        {
            printf("Process%d created.\n",iCnt);
            exit(0);
        }       
    }

    return 0;
}