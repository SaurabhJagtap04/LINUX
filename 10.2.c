//Create two threads
//First Thread prints numbers from 1 to 500
//Seconf Thread prints numbers from 500 to 1

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void* XThread1(void *ptr)
{
    for(int i = 1; i <= 500; i++)
    {
        printf("%d\n",i);
    }
    pthread_exit(NULL);
}

void* XThread2(void *ptr)
{
    for(int i = 500; i > 0; i--)
    {
        printf("%d\n",i);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID1;
    pthread_t TID2;
    int ret1 = 0, ret2 = 0;

    ret1 = pthread_create(&TID1,NULL,XThread1,NULL);
    
    if(ret1 != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is created with ID : %d\n",TID1);

    ret2 = pthread_create(&TID2,NULL,XThread2,NULL);
    
    if(ret2 != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is created with ID : %d\n",TID2);

    pthread_join(TID1, NULL);
    pthread_join(TID2, NULL);

    pthread_exit(NULL);

    return 0;
}
