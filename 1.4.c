#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char* argv[])
{
    struct stat sobj;

    if(argc != 2)
    {
        printf("Insufficient number of arguments\n");
        return -1;
    }

    stat(argv[1],&sobj);

    printf("File name\t: %s\n",argv[1]);
    printf("File size\t: %ld\n",sobj.st_size);
    printf("Number of Links\t: %ld\n",sobj.st_nlink);
    printf("Inode number\t: %ld\n",sobj.st_ino);
    printf("File System number\t: %ld\n",sobj.st_dev);
    printf("Number of blocks\t: %ld\n",sobj.st_blocks);    

    return 0;
}