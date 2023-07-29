//Program that creates two processes
//Process 1 counts number of capital letters in demo.txt file
//Process 2 counts number of capital letters in hello.txt file
//Both the processes writes its count in count.txt file

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int ret = 0, ret2  = 0, ret3 = 0;
    int fd = 0, fd2 = 0;
    char Arr[1];
    int iCount = 0, iCount2 = 0;

    
    fd2 = creat("count.txt",0777);

    FILE * file;

    file = fopen("count.txt","w");

    ret = fork();

    if(ret == 0)
    {
        fd = open("demo.txt",O_RDONLY);

        if(fd == -1)
        {
            printf("Unable to open demo.txt\n");
        }

        while((ret2 = read(fd,Arr,1)) != 0)
        {
            if((Arr[0] >= 'A') && (Arr[0] <= 'Z'))
            {
                iCount++;
            }

        }
        printf("iCount : %d\n",iCount);    

        close(fd);   

        fprintf(file, "Capital letters in demo.txt : %d\n",iCount);

    }

    ret3 = fork();

    if(ret3 == 0)
    {
        fd = open("hello.txt",O_RDONLY);

        if(fd == -1)
        {
            printf("Unable to open demo.txt\n");
        }

        while((ret2 = read(fd,Arr,1)) != 0)
        {
            if((Arr[0] >= 'A') && (Arr[0] <= 'Z'))
            {
                iCount2++;
            }

        }
        printf("iCount2 : %d\n",iCount2);    

        close(fd);   

        fprintf(file, "Capital letters in hello.txt : %d\n",iCount2);
    }

    fclose(file);

    return 0;
}
