#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char* argv[])
{
    int fd = 0;
    int ret = 0;
    char* Buffer = NULL;

    if(argc != 3)
    {
        printf("Insufficient number of arguments\n");
    }

    Buffer = (char*)malloc(sizeof(atoi(argv[2])));

    fd = open(argv[1],O_RDONLY);

    ret = read(fd, Buffer, atoi(argv[2]));

    if(ret > 0)
    {
        printf("%d bytes read successfully from the file\n",ret);
    }  

    return 0;
}