//Accept file name and position from user
//read 20 bytes from thet position

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
    int fd = 0;
    int iRet = 0;
    char Arr[20];

    if(argc != 3)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);

    lseek(fd,atoi(argv[2]),0);

    iRet = read(fd, Arr, 20);

    printf("Data from file is :\n");
    write(1, Arr, iRet);
    printf("\n");

    return 0;

}