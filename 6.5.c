//Program that accept filename & offset from user
//Remove all data from that offset

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
    int fd = 0;
    int ret = 0;

    if(argc != 3)
    {
        printf("Invalid number of arguments.\n");
    }

    fd = open(argv[1], O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open file\n");
    }

    ret = truncate(argv[1], atoi(argv[2]));

    if(ret == -1)
    {
        printf("Unable to delete data.\n");
    }
    else
    {
        printf("Data deleted successfully\n");
    }

    return 0;

}