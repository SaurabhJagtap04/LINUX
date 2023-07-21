#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char* argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    struct stat sobj;
    char path[300];
    char fname[30] = {'\0'};
    int iMax = 0;

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

       
    while((entry = readdir(dp)) != NULL)
    {
        sprintf(path,"%s/%s",argv[1],entry->d_name);

        stat(path, &sobj);

        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size > iMax)
            {
                
                strncpy(fname, entry->d_name, 30);
                iMax = sobj.st_size;
               
            } 
            
        }

        
    }

    printf("Largest file : %s \nSize : %d\n",fname,iMax);

    closedir(dp);
}