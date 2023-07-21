//Program that writes structure in a file.
//Structure should contain information of a student

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

#pragma pack(1)

struct Student
{
    char name[15];
    int rollno;
    int age;
};

int main(int argc, char* argv[])
{
    int fd = 0;
    FILE* dp = NULL;
    int iret = 0;
    char Arr[50];

    struct Student sobj;

    strcpy(sobj.name,"Krushna");
    sobj.rollno = 53;
    sobj.age = 21;

    dp = fopen(argv[1],"r+");

    fwrite(&sobj, sizeof(struct Student), 1, dp);

    fd = open(argv[1],O_RDONLY);

    iret = read(fd,Arr, 50);

    printf("%s\n",Arr);

    return 0;

}