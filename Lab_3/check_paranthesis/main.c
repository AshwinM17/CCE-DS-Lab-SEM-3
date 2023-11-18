#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
int main()
{
    enum bracket{flw,par,sqr,ang};
    //enum bracket bkt; what is the need
    char exp[100];
    printf("Enter the expression\n");
    scanf("%s",exp);
    int i;
    bool flag=true;
    while(exp[i]!='\0')
    {
        if(exp[i]=='{')
            {
                element e;
                e.key=-1;
                e.key=flw;
                push(e);
            }
        if(exp[i]=='(')
            {
                element e;
                e.key=-1;
                e.key=par;

                push(e);
            }
        if(exp[i]=='[')
            {
                element e;
                e.key=-1;
                e.key=sqr;
                push(e);
            }
        if(exp[i]=='<')
            {
                element e;
                e.key=-1;
                e.key=ang;
                push(e);
            }
        if(exp[i]=='}')
        {
            element e;
            e=pop();

            if(e.key!=flw)
            {

                flag=false;
            }
        }
        if(exp[i]==')')
        {
            element e;
            e=pop();
            if(e.key!=par)
            {
                flag=false;
            }
        }
        if(exp[i]==']')
        {
            element e;
            e=pop();
            if(e.key!=sqr)
            {
                flag=false;
            }
        }
        if(exp[i]=='>')
        {
            element e;
            e=pop();
            if(e.key!=ang)
            {
                flag=false;
            }
        }



    i++;
    }
    if(!isempty())
    {
        flag=false;
    }
    if(flag)
    {

        printf("Valid Exprression");
    }
    else
        printf("Error:Invalid Expression");
}
