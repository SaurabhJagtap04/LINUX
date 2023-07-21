//Program that creates hole of size 1kb at the end of file.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
    int fd = 0;
    int ret = 0, ret2 = 0;
    char Ax = '\0';

    if(argc != 2)
    {
        printf("Invalid number of arguments.\n");
    }

    fd = open(argv[1], O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open %s.\n",argv[1]);
    }

    ret = lseek(fd, 0 ,SEEK_END);

    printf("ret : %d\n",ret);

    ret2 = write(fd,&Ax, sizeof(Ax));

    printf("ret2 : %d\n",ret2);

    return 0;

}