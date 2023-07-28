//Program used to access fucntion that accepts two file names and
//compares its data from shared library "7.2.so"

#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main(int argc, char* argv[])
{
    void *ptr = NULL;
    int (*fptr)();
    int iret = 0;
    
    if(argc != 3)
    {
        printf("Invalid number of arguments.\n");
        return -1;
    }

    ptr = dlopen("/home/saurabh/Desktop/self/7.2.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }

    fptr = dlsym(ptr,"FileCompare");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    iret = fptr(argv[1],argv[2]);

    if(iret == -2)
    {
        printf("Files are not identical.\n");
    }
    else
    {
        printf("Files are identical.\n");
    }

    return 0;
}
