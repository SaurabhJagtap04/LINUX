//Program that creates new process
//This process is responsible to write all names which are present on desktop
//in demo file which should be created newly

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>


int main()
{
    int fd = 0;
    int ret = 0, ret1 = 0;
    struct stat sobj;
    DIR* dp = NULL;
    struct dirent *entry;
    char fpath[500];
    char buff[10];

    ret = fork();

    if(ret == 0)
    {
        fd = creat("demo.txt",0777);

        if(fd == -1)
        {
            printf("Failed to create demo.txt.\n");
        }

        FILE *file = fopen("demo.txt","w");

        dp = opendir("/home/saurabh/Desktop");

        if(dp == NULL)
        {
            printf("Unable to open directory.\n");
        }

        while((entry = readdir(dp)) != NULL)
        {
            sprintf(fpath,"/home/saurabh/Desktop/%s",entry->d_name);
            
            stat(fpath,&sobj);           

            if(S_ISREG(sobj.st_mode)) 
            {
                fprintf(file,"%s\n", entry->d_name); 
            }        
        }

        closedir(dp);   
    }
    return 0;
}