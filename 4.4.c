//Accept directory name from user
//Copy first 10 bytes from all regular files into newly created file named as Demo.txt

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc, char*argv[])
{
    int fd = 0;
    int fd2 = 0;
    DIR* dp = NULL;
    struct dirent * entry;
    int ret = 0;
    int ret2 = 0;
    char name[300];
    struct stat sobj;
    char Buffer[10];

    if(argc != 2)
    {
        printf("invalid number of arguments\n");
        return -1;
    }

    fd = creat("Demo.txt",0777);

    ret2 = open("Demo.txt",O_RDWR | O_APPEND);

    if(fd == -1)
    {
        printf("Unable to create Demo.txt\n");
        return -1;
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open specified directory\n");
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name, "%s/%s", argv[1], entry->d_name);
        stat(name, &sobj);

        if(S_ISREG(sobj.st_mode))
        {
            fd2 = open(name,O_RDONLY);
            ret = read(fd2, Buffer, 10);
            write(fd, Buffer, 10);

            close(fd2);                   

        }
    }




}