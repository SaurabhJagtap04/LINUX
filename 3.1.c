//Accept two file names from user 
//Copy the contents of an existing file into newly creates file.

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

#define BLOCKSIZE 1

int main(int argc, char* argv[])
{
    int fd1 = 0;
    int fd2 = 0;
    int ret = 0;
    char Buffer[BLOCKSIZE];

    if(argc != 3)
    {
        printf("Invalid number of arguments\n");
    }

    fd1= open(argv[1],O_RDONLY);

    fd2 = creat(argv[2],0777);

    while(1)
    {
        ret = read(fd1,Buffer,sizeof(Buffer));

        if(ret == 0)
        {
            break;
        }
        
        write(fd2,Buffer,sizeof(Buffer));

        memset(Buffer,0,sizeof(Buffer));      

    }

    close(fd1);
    close(fd2);

}