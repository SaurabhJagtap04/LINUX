//Program that accepts directory and file name from user 
//And create the file in that directory

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char* argv[])
{
    int fd = 0;
    DIR* dp = NULL;
    char fpath[20];

    if(argc != 3)
    {
        printf("Invalid number of arguments\n");
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open directory.\n");
    }

    sprintf(fpath,"%s/%s",argv[1],argv[2]);

    fd = creat(fpath, 0777);

    if(fd == -1)
    {
        printf("Unable to create %s in %s.\n",argv[2],argv[1]);
    }
    else
    {
        printf("%s created successfully in %s.\n",argv[2],argv[1]);
    }

    return 0;

    
}