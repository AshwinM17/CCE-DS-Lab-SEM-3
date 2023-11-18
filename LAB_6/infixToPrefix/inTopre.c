#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
#include"charStack.h"

//check precedence of operators
int precedence(char ch)
{
    int retVal = -1;
    switch(ch)
    {
    case '^':
        retVal = 3;
        break;
    case '*':
    case '/':
        retVal = 2;
        break;
    case '+':
    case '-':
        retVal = 1;
        break;
    }
    return retVal;
}

char* convert(char infix[],char *prefix)
{
    strrev(infix);
    int ilen = strlen(infix);
    //char *prefix = (char*)malloc(ilen);
    element ce;
    char cc;
    int iIndex,pIndex=0;

    //iterate through the infix expression
    for(iIndex=0; iIndex<ilen ; iIndex++)
    {
        cc = infix[iIndex];
        if(isalpha(cc))
        {
            prefix[pIndex++] = cc;
        }
        else if(cc == ')')
        {
            ce.key = cc;
            Push(ce);
        }
        else if(cc == '(')
        {
            while(!isEmpty() && Peek().key!=')')
            {
                prefix[pIndex++] = Pop().key;
            }
            if(isEmpty())
            {
                printf("Invalid");
                free(prefix);
                return;
            }
            else if(Peek().key == ')')
            {
                Pop();
            }
        }
        else
        {
            while(!isEmpty() && precedence(Peek().key) > precedence(cc))
            {
                prefix[pIndex++] = Pop().key;
            }
            ce.key = cc;
            Push(ce);
        }
    }
    while(!isEmpty())
    {
        prefix[pIndex++] = Pop().key;
    }
    prefix[pIndex] = '\0';
    strcpy(prefix,strrev(prefix));
    return prefix;
    //printf("%s",prefix);
}

int main()
{
    char infix[50],prefix[50];
    printf("Enter infix expression\n");
    scanf("%s",infix);
    printf("Prefix expression:\n");
    printf("%s",convert(infix,prefix));
}
