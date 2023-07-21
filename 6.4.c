//Program that accept directory name from user
//Delete all such files whose size is greater than 100 bytes

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<stdbool.h>

int main(int argc, char* argv[])
{
    int fd = 0;
    char fpath[20];
    DIR* dp = NULL;
    struct dirent* entry;
    struct stat sobj;
    int ret = 0;
    bool bflag = false;

    if(argc != 2)
    {
        printf("Invalid number of arguments.\n");
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open %s.\n",argv[1]);
    }

    while((entry = readdir(dp)) != 0)
    {
        sprintf(fpath,"%s/%s",argv[1],entry->d_name);

        stat(fpath,&sobj);

        if((S_ISREG(sobj.st_mode)) && ((sobj.st_size)>100))
        {
            bflag = true;
            printf("%s | size : %d bytes\n",entry->d_name,sobj.st_size);

            ret = unlink(fpath);

            if(ret == -1)
            {
                printf("Unable to delete %s.\n",entry->d_name);
            }
            else
            {
                printf("%s deleted successfully.\n",entry->d_name);
            }
        }       
    }

    if(bflag == false)
    {
        printf("There is no file in directory with size greater than 100 bytes.\n");
    }


    return 0;
}