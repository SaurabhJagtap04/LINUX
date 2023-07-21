//Accept directory name from user
//Make new directory of that name

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char* argv[])
{
    int dp = 0;

    if(argc != 2)
    {
        printf("Invalid number of arguments\n");
    }

    dp = mkdir(argv[1],0777);

    if(dp == -1)
    {
        printf("Unable to open directory\n");
    }
    else
    {
        printf("%s directory created successfully\n",argv[1]);
    }

    return 0;
}