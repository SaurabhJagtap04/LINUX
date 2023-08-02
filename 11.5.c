//Program creates two threads by using pthread API
//One thread counts number of capital characters from demo.txt file
//Another thread counts number of small characters from same file

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<pthread.h>

void * ThreadX1(void *ptr)
{
    int ret = 0;
    char Arr[1];
    int iCount1 = 0;

     int fd = open("demo.txt",O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open demo.txt file\n");
        return -1;
    }
  

    while((ret = read(fd,Arr,1)) != 0)
    {
    
        if((Arr[0] >= 'A') && (Arr[0] <= 'Z'))
        {
            iCount1++;
        }
    } 

    pthread_exit((int *)iCount1); 

    close(fd);
}

void * ThreadX2(void *ptr)
{
    int ret1 = 0;
    char Brr[1];
    int iCount = 0;

    int fd = open("demo.txt",O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open demo.txt file\n");
        return -1;
    }
   

    while((ret1 = read(fd,Brr,1)) != 0)
    {
     
        if((Brr[0] >= 'a') && (Brr[0] <= 'z'))
        {
            iCount++;
        }
    } 

    pthread_exit((int *)iCount); 

    close(fd);

}

int main()
{
    static int fd = 0;
    int ret1 = 0, ret2 = 0;
    pthread_t TID1 = 0;
    pthread_t TID2 = 0;

    int ivalue1, ivalue2;
  
    ret1 = pthread_create(&TID1, NULL, ThreadX1, NULL);
    ret2 = pthread_create(&TID2, NULL, ThreadX2, NULL);

    if((ret1 != 0) || (ret2 != 0))
    {
        printf("Unable to create Thread.\n");
        return -1;
    }

    pthread_join(TID1, &ivalue1);

    printf("Capital Count is : %d\n",ivalue1);

    pthread_join(TID2, &ivalue2);

    printf("Small Count is : %d\n",ivalue2);

    return 0;
}