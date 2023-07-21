//Program that accept directory name from user
//Combine all contents of file from that directory into one file named as "AllCombine"

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>

#define BLOCKSIZE 1

int main(int argc, char* argv[])
{
    int fd = 0;
    int fd2 = 0;
    int fd3 = 0;
    DIR* dp = NULL;
    char Arr[BLOCKSIZE];
    char Brr[10];
    struct dirent* entry;
    struct stat sobj;
    char fname[300];
    int ret = 0;
    int ret2 = 0;

    if(argc != 2)
    {
        printf("Insufficient number of arguments\n");
    }

    fd = creat("AllCombine.txt",0777);

    if(fd == -1)
    {
        printf("Unable to create new file\n");
        return -1;
    }

    fd3 = open("AllCombine.txt", O_RDWR);

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != 0)
    {
        if(S_ISREG(sobj.st_mode) == 0)
        {
            sprintf(fname, "%s/%s", argv[1],entry->d_name);
            fd2 = open(fname, O_RDONLY);
            while((ret = read(fd2, Arr, BLOCKSIZE)) > 0)
            {
                write(fd , Arr, BLOCKSIZE);
            }
            close(fd2);
        }        
    }

    closedir(dp);

    while((ret2 = read(fd3, Brr, BLOCKSIZE)) > 0)
    {
        write(1, Brr, BLOCKSIZE);
    }
    printf("\n");

    return 0;
}