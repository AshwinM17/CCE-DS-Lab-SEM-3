#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main()
{
    char str[50];
    printf("Enter the String:\n");
    gets(str);
    element e;
    int i,n;
    n=strlen(str);
    for(i=0;str[i]!='\0';i++)
    {
        e.key=str[i];
        push(e);
    }
    int flag=1;
    for(i=0;i<n;i++)
    for(i=0;i<n;i++)
    {

        e=pop();
        if(str[i]!=e.key)
        {
            //printf("%c",e.key);
            flag=0;
            break;
        }
    }
    if (flag)
    {
        printf("It is a palindrome");
    }
    else
        printf("It is not a palindrome");
}
