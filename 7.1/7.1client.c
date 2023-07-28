//Program used to access fucntions of addition, substraction, multiplication and division from shared library "7.1.so"

#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    int (*fptr)();
    int a = 15, b = 20;
    int iret = 0;

    ptr = dlopen("/home/saurabh/Desktop/self/7.1.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }

    fptr = dlsym(ptr,"Addition");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    iret = fptr(a, b);

    printf("Addition is : %d\n",iret);

    return 0;
}
