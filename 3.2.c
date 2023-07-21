//Accept directory name & file name from user
//Check if accepted file is present in the directory or not

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char* argv[])
{
    DIR* dp = NULL;
    struct dirent* entry = NULL;
    int ret = 0;

    if(argc != 3)
    {
        printf("invalid number of arguments\n");
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
    }

    while((entry = readdir(dp)) != NULL)
    {

        if((strcmp(argv[2], entry->d_name)) == 0)
        {
            printf("%s is present in the directory\n",argv[2]);
            break;
        }
    }

    if((entry = readdir(dp)) == NULL)
    {
        printf("%s not found int the directory\n",argv[2]);
        return -1;
    }

    closedir(dp);
    return 0;
}