#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
    int fd = 0;
    char str[] = "Hello India";
    char Buffer[20] = {'\0'};

    fd = open(argv[1],O_RDWR | O_APPEND);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    write(fd, str, (sizeof(str) - 1));

    close(fd);

    return 0;

}