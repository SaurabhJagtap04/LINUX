//Program creates 4 number of threads.
//Main thread waits till all threads terminate.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* ThreadX1(void* ptr)
{
    printf("Inside Thread 1.\n");

    pthread_exit(NULL);
}

void* ThreadX2(void* ptr)
{
    printf("Inside Thread 2.\n");
    
    pthread_exit(NULL);
}

void* ThreadX3(void* ptr)
{
    printf("Inside Thread 3.\n");
    
    pthread_exit(NULL);
}

void* ThreadX4(void* ptr)
{
    printf("Inside Thread 4.\n");
    
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID1 = 0;
    pthread_t TID2 = 0;
    pthread_t TID3 = 0;
    pthread_t TID4 = 0;

    int ret1, ret2, ret3, ret4;

    ret1 = pthread_create(&TID1, NULL, ThreadX1, NULL);
    ret2 = pthread_create(&TID2, NULL, ThreadX2, NULL);
    ret3 = pthread_create(&TID3, NULL, ThreadX3, NULL);
    ret4 = pthread_create(&TID4, NULL, ThreadX4, NULL);

    if((ret1 != 0) || (ret2 != 0) || (ret3 != 0) || (ret4 != 0))
    {
        printf("Unable to create thread.\n");
        return -1;
    }

    pthread_join(TID1, NULL);
    pthread_join(TID1, NULL);
    pthread_join(TID1, NULL);
    pthread_join(TID1, NULL);

    printf("End of main thread.\n");

    pthread_exit(NULL);

    return 0;
}

