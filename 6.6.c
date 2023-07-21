//Program that accept directory name from user
//Create a hole in file if file size if less than 1kb
//& if it is greater than 1kb truncate the remaining data

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>


int main(int argc, char* argv[])
{
    int fd = 0;
    char fpath[20];
    DIR* dp = NULL;
    struct dirent* entry;
    struct stat sobj;
    int ret = 0, ret2 = 0;
    char Ax = '\0';
  

    if(argc != 2)
    {
        printf("Invalid number of arguments.\n");
        return -1;
    }

    fd = open(argv[1],O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open %s.\n",argv[1]);
        return -1;
    }


    stat(argv[1],&sobj);

    if((S_ISREG(sobj.st_mode)) && (sobj.st_size < 1))
    {
        printf("Less than 1 kb : \n");        
        printf("%s | size : %d bytes\n",argv[1],sobj.st_size);

        ret = write(fd, &Ax, 1);        

        if(ret == -1)
        {
            printf("Unable to create hole in  %s.\n",argv[1]);
        }
        else
        {
            printf("Hole created successfully in %s.\n",argv[1]);
        }

    }    
    else if((S_ISREG(sobj.st_mode)))
    {
        printf("Greater than 1 kb : \n");
        printf("%s | size : %d bytes\n",argv[1],sobj.st_size);

        ret2 = lseek(fd, 1 ,SEEK_SET);

        ret = truncate(argv[1], 1);

        if(ret == -1)
        {
            printf("%s truncate failed.\n",argv[1]);
        }
        else
        {
            printf("%s truncate successfull.\n",argv[1]);
        }      
    }       


 


    return 0;
}