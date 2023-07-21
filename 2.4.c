#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char* argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    struct stat sobj;
    char path[300];

    if(argc != 2)
    {
        printf("Invalid number of arguments\n");
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    printf("Files from directory are : \n");
    printf("  File Name \t File Type\n");

    int iCnt = 1;

    
    while((entry = readdir(dp)) != NULL)
    {
        printf("%d. %s\t:",iCnt, entry->d_name);
        iCnt++;

        sprintf(path,"%s/%s",argv[1],entry->d_name);

        stat(path, &sobj);
     

        if(S_ISREG(sobj.st_mode))
        {
            printf("Regular File\n");
        }
        else if(S_ISDIR(sobj.st_mode))
        {
            printf("Directory File\n");
        }
        else if(S_ISLNK(sobj.st_mode))
        {
            printf("Symbolic Link\n");
        }

     
    }

    closedir(dp);
}