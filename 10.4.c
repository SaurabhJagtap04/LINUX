//Create a single thread that accepts one value from user
//Return same value to the main thread

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void* XThread(void *ptr)
{
    int No = 0;

    printf("Enter number : \n");
    scanf("%d",&No);

    pthread_exit((int *)No);
}

int main()
{
    pthread_t TID;
    int ret = 0;
    int value = 0;

    ret = pthread_create(&TID,NULL,XThread,NULL);
    
    if(ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is created with ID : %d\n",TID);

    pthread_join(TID,&value);

    printf("Entered value in caller thread : %d\n",value);

    return 0;
}
