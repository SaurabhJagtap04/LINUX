//Accept two directory names from user
//Move all files from source directory to destination directory

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
    DIR* dp = NULL;
    char Dsource[300];
    char Ddest[300];
    struct dirent *entry = NULL;
    int iCnt = 1;
    
    if(argc != 3)
    {
        printf("Invalid number of arguments\n");
    }

    dp = opendir(argv[1]);
    

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(Dsource, "%s/%s", argv[1], entry->d_name);
        sprintf(Ddest, "%s/demo%d", argv[2], iCnt);

        rename(Dsource,Ddest);
        iCnt++;
    }

   
    return 0;
}