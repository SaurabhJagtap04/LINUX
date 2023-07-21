//Program that accept file name from user and open that file

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
    int fd = 0;

    if(argc != 2)
    {
        printf("Invalid number of arguments.\n");
        return -1;
    }

    fd = open(argv[1], O_RDWR);

    if(fd == -1)
    {
        printf("Cannot open %s.\n",argv[1]);
    }
    else
    {
        printf("%s opened successfully.\n",argv[1]);
    }

    close(fd);

    return 0;
}