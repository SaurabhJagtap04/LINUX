#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
    int mode = 0;
    int ret = 0;

    if(argc != 3)
    {
        printf("Insufficient number of arguments\n");
        return -1;
    }

    if(strcmp(argv[1],"read") == 0)
    {
        mode = R_OK;
    }
    else if(strcmp(argv[1],"write") == 0)
    {
        mode = W_OK;
    }
    else if(strcmp(argv[1],"execute") == 0)
    {
        mode = X_OK;
    }

    ret = access(argv[1],mode);

    if(ret < 0)
    {
        printf("Cannot open %s in %s mode\n",argv[1],argv[2]);
    }
    else
    {
        printf("%s can be opened in %s mode\n",argv[1],argv[2]);
    }

    return 0;
}