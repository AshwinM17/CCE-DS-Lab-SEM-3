#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stringStack.h"

//check if character is operator
bool isOperator(char ch)
{
    bool ret=false;
             if(ch=='*' || ch=='/' || ch=='+' || ch=='-' || ch=='^' )
    {
        ret = true;
    }
    return ret;
}

//convert from prefix to infix
void convert(char prefix[])
{
    element ce;
    int pIndex;
    int plen = strlen(prefix);
    char cs[2];
    char opr1[30],opr2[30];
    strrev(prefix);
    for(pIndex=0;pIndex<plen;pIndex++)
    {
        cs[0]=prefix[pIndex];
        cs[1]='\0';
        if(isalnum(cs[0]))
        {
            strcpy(ce.key,cs);
            Push(ce);
        }
        else if(isOperator(cs[0]))
        {
            strcpy(opr1,Pop().key);
            strcpy(opr2,Pop().key);
            strcpy(ce.key,"(");
            strcat(ce.key,opr1);
            strcat(ce.key,cs);
            strcat(ce.key,opr2);
            strcat(ce.key,")");
            Push(ce);
        }
        else
        {
            printf("invalid");
            return;
        }
    }
    printf("%s",Pop().key);
}

int main()
{
    char prefix[60];
    printf("Enter prefix expression\n");
    scanf("%s",prefix);
    printf("Infix expression:\n");
    convert(prefix);
    return 0;
}
