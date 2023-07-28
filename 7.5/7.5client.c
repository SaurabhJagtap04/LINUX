//Program used to access function that accepts file name
//and displays its information from shared library "7.5.so"

#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main(int argc, char* argv[])
{
    void *ptr = NULL;
    void (*fptr)();

    ptr = dlopen("/home/saurabh/Desktop/self/7.5.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }

    fptr = dlsym(ptr,"ReadFile");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    fptr(argv[1]);

    return 0;
}
