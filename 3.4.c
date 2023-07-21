//Accept Directory name form user
//Delete all empty files from that directory

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char* argv[])
{
    DIR* dp = NULL;
    struct dirent* entry = NULL;
    struct stat sobj;
    char path[300];

    if(argc != 2)
    {
        printf("Invalid number of arguments\n");
    }

    dp = opendir(argv[1]);

    while((entry = readdir(dp)) != 0)
    {
        sprintf(path,"%s/%s",argv[1],entry->d_name);

        stat(path, &sobj);
        
        
        //printf("%s | %ld\n",entry->d_name,sobj.st_size);

        if(sobj.st_size == 0)
        {
            sprintf(path, "%s/%s", argv[1], entry->d_name);
            remove(path);
            printf("%s deleted\n", entry->d_name);
        }
        


        
    }


}