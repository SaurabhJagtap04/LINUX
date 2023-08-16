// Server process which shares message into shared memory

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
    char buf[] = "Hello World!";
    char *shm, *s;
    key_t key = 1234;

    printf("Inside Server Process.\n");

    shmid = shmget(key, SHMSZ, IPC_CREAT | 0666);

    shm = shmat(shmid, NULL, 0);

    *shm = 'H';

    printf("Data is written in shared memory.\n");

    // while(*shm != '*')
    // {
    //     sleep(1);
    // }

    printf("Terminating server.\n");

    exit(0);
}