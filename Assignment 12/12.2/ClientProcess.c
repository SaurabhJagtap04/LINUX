// Client process which accepts message from shared memory

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/shm.h>

#define SHMSZ 30

int main()
{
    int shmid;
    char *shm, *s;
    key_t key = 1234;

    printf("Inside Client Process.\n");

    shmid = shmget(key, SHMSZ, 0666);

    shm = shmat(shmid, NULL, 0);   

    if(shm != NULL)
    {
        printf("Data received from server\n");
    }
  
    printf("Data from server process : %s\n",shm);

    printf("Terminating client.\n");

    exit(0);
}