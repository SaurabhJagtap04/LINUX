#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
    int fd = 0; 
    int mode = 0;

    if(argc != 3)
    {
        printf("Insufficient number of arguments\n");
    }

    if(strcmp(argv[2],"read") == 0)
    {
        fd = open(argv[1],O_RDONLY);
    }
    else if(strcmp(argv[2],"write") == 0)
    {
        fd = open(argv[1],O_WRONLY);
    }
    else if(strcmp(argv[2],"readandwrite") == 0) 
    {
        fd = open(argv[1],O_RDWR);
    }
    else
    {
        printf("Enter valid arguments\n");
    }

    if(fd == -1)
    {
        printf("Unable to open file\n");
    }
    else
    {
        printf("File opened successfully\n");
    }





    return 0;
}