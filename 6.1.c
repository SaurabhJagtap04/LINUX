//Program that accept file name which contains data of all file.
//Create all files again.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[])
{
    int fd = 0;
    int fd2 = 0;
    int ret = 0, ret2 = 0;
    char Arr[50];
    struct fileinfo 
    {
        char fname[15];
        int filesize;
        char filedata[50];
    };

    struct fileinfo fobj;

    fd = open("demoall.txt",O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open demoall.txt\n");
    }

    while(ret =(read(fd, &fobj,sizeof(fobj)))!= 0)
    {

        if(fobj.filesize > 10)
        {
            printf("Filename : %s | Filesize : %d bytes.\n",fobj.fname,fobj.filesize);
        }

    }


    return 0;

}

