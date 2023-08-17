// Program that creates two processes 
// That processes should communicate with each other using FIFO

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUF 1024

int main()
{
    int fd;
    char* myfifo = "/tmp/myfifo";
    int ret, ret1;
    char buf[MAX_BUF];

    ret = fork();
    
    if(ret == 0)
    {
        mkfifo(myfifo, 0666);

        fd = open(myfifo, O_WRONLY);

        write(fd, "Hello World!", strlen("Hello World!")+1);

        close(fd);

        printf("Data is successfully written into named pipe.\n");

        exit(0);
    }
    else
    {
        
        ret1 = fork();

        if(ret1 == 0)
        {    
            printf("Child process is running.\n");

            fd = open(myfifo, O_RDONLY);

            read(fd, buf, MAX_BUF);

            printf("Data received is : %s\n", buf);

            close(fd);

            exit(0);
        }
        else
        {
            wait(NULL);
            wait(NULL);
        }

    }
     
    return 0;
}
