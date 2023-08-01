//Create a single thread
//Pass a parameter to that thread

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void* XThread(void *ptr)
{
    printf("Received : %d\n", (int)ptr);
}

int main()
{
    pthread_t TID;
    int ret = 0;
    int No = 108;

    ret = pthread_create(&TID,NULL,XThread,(int *)No);
    
    if(ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is created with ID : %d\n",TID);

    pthread_join(TID,NULL);

    return 0;
}
