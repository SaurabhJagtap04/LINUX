//Get thread ID inside thread.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void* XThread(void *ptr)
{
    int No = 0;

    pthread_t id = pthread_self();

    printf("Thread ID inside thred : %ld\n",id);  

    pthread_exit(NULL);
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

    printf("Thread is created with ID : %ld\n",TID);

    pthread_join(TID,NULL);

    

    return 0;
}
