#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>

int main(int argc, char* argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;

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

    int iCnt = 1;

    while((entry = readdir(dp)) != NULL)
    {
        printf("%d. %s\n",iCnt, entry->d_name);
    }

    closedir(dp);
}