//Program used to access fucntions checking if a number is prime and perfect.
//Both fuctiions are in separate libraries as "7.3a.so" & "7.3b.so"

#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<stdbool.h>
#include<string.h>

int main(int argc, char* argv[])
{
    void *ptr = NULL;
    bool (*fptr)();
    bool bret = false;

    ptr = dlopen("/home/saurabh/Desktop/self/7.3a.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }

    fptr = dlsym(ptr,"ChkPrime");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    bret = fptr(atoi(argv[1]));

    if(bret == false)
    {
        printf("%s is a Prime Number.\n",argv[1]);
    }
    else
    {
        printf("%s is not a Prime number.\n",argv[1]);
    }

    ////////////////////////////////////////////////////
    bret = false;
    ////////////////////////////////////////////////////

    ptr = dlopen("/home/saurabh/Desktop/self/7.3b.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }

    fptr = dlsym(ptr,"ChkPerfect");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    bret = fptr(atoi(argv[1]));

    if(bret == true)
    {
        printf("%s is a Perfect Number.\n",argv[1]);
    }
    else
    {
        printf("%s is not a Perfect number.\n",argv[1]);
    }

    return 0;
}
