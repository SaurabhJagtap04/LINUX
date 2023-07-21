//Program that accept directory name from user
//Write information of of all regular files in one file
//Read the contents from that file

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
    DIR* dp = NULL;
    struct dirent* entry;
    struct stat sobj;
    char Brr[37];
    int iCnt = 1;

    if(argc != 2)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    fd = creat("FiledData.txt", 0777);
    fd2 = open("FiledData.txt", O_RDWR);

    char Arr[] = "\tFile Name  Inode Number  File Size    Link no.\n";

    write(fd2, Arr, sizeof(Arr) - 1);

    if(fd == -1)
    {
        printf("Unable to create file\n");
    }

    dp = opendir(argv[1]);

    while((entry = readdir(dp)) != 0)
    {
        if(stat(entry->d_name,&sobj) == -1)
        {
            sprintf(Brr, "%d.\t%s\t\t%ld\t\t %d Bytes   \t\t%d\n",iCnt,entry->d_name, entry->d_ino, sobj.st_size, sobj.st_nlink);
            iCnt++;
            write(fd2, Brr, sizeof(Brr) - 1);
        }

       
    }



    return 0;
}