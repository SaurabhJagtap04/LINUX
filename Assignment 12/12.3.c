// Program creates one child process
// Child process writes something in unnamed pipe and
// Parent process read the data from that pipe

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define ReadEnd 0
#define WriteEnd 1

int main()
{
    int pipeFDs[2];
    char buf;
    const char* msg = "Hello World!\n";
    
    if(pipe(pipeFDs) < 0)
    {
        perror("Pipe Creation Failed.\n");
        exit(-1);
    }

    pid_t cpid = fork();

    if(cpid < 0)
    {
        perror("Fork Failed.\n");
        exit(-1);
    }

    if(cpid == 0)
    {
        printf("Child process is running.\n");

        close(pipeFDs[ReadEnd]);

        write(pipeFDs[WriteEnd], msg, strlen(msg));

        close(pipeFDs[WriteEnd]);

        wait(NULL);

        exit(0);
    }
    else
    {
        printf("Parent process is running.\n");

        close(pipeFDs[WriteEnd]);


        while(read(pipeFDs[ReadEnd], &buf, 1) > 0)
        {
            write(STDOUT_FILENO, &buf, sizeof(buf));
        }

        close(pipeFDs[ReadEnd]);

        _exit(0);
    }

    return 0;
}


