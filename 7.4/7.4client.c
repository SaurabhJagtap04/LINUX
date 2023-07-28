//Program used to access fucntion from shared library which internally loads another shared library
//The inner shared library contains function to calculate factorial of a number

#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<string.h>

int main(int argc, char* argv[])
{
    void *ptr = NULL;
    int (*fptr)();

    int iret1 = 0;

    ptr = dlopen("/home/saurabh/Desktop/self/7.4o.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load outside liabrary\n");
        return -1;
    }

    fptr = dlsym(ptr,"getfunc");
    if(fptr == NULL)
    {
        printf("Unable to load the address of outside function\n");
        return -1;
    }

    iret1 = fptr(atoi(argv[1]));

    printf("Factorial is : %d\n",iret1);

    return 0;
}

