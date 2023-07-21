//Program that accept file name from user that contains information of employee
//Read all contents of that file

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

#define BLOCKSIZE 1 

int main(int argc, char* argv[])
{
    int fd = 0;
    int iret = 0;
    char Arr[BLOCKSIZE];

    fd = open(argv[1],O_RDONLY);


    while((iret = read(fd, Arr, BLOCKSIZE)) != 0)
    {
        write(1,Arr,BLOCKSIZE);
    }

    return 0;  


}