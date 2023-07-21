//Accept two file names from user
//Check if contents of those two files are equal or not

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>

#define BLOCKSIZE 1

int main(int argc, char* argv[])
{
    int fd1 = 0;
    int fd2 = 0;
    int ret = 0;
    char Buffer1[BLOCKSIZE];
    char Buffer2[BLOCKSIZE];
    struct stat sobj1,sobj2;

    if(argc != 3)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    fd1 = open(argv[1],O_RDONLY);
    fd2 = open(argv[2],O_RDONLY);

    stat(argv[1],&sobj1);
    stat(argv[2],&sobj2);

    if(sobj1.st_size != sobj2.st_size)
    {
        printf("Files are unequal\n");
        return -1;
    }

    

    while((ret = read(fd1,Buffer1, BLOCKSIZE)) != 0)
    {
        ret = read(fd2,Buffer2,BLOCKSIZE);
        if(memcmp(Buffer1, Buffer2, ret) != 0)
        {
            break;
        }             
    }

    if(ret == 0)
    {
        printf("Both files are identical\n");
    }
    else
    {
        printf("Both files are different");
    }

    close(fd1);
    close(fd2);


    return 0;

}