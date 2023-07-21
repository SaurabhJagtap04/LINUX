//I/O redirection

#include<stdio.h>

int main()
{
    int iNo1 = 0; 
    int iNo2 = 0;
    int iRet = 0;

    scanf("%d",&iNo1);

    scanf("%d",&iNo2);

    iRet = iNo1 + iNo2;

    printf("Addition is : %d",iRet);

    return 0;
}

//./Myexe <input.txt >output.txt