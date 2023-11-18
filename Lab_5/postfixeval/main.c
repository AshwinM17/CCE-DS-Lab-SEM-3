#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>
#include <ctype.h>
#include <math.h>

void evalpostfix(char *postfix)  //can also be char postfix[]
{
    int plen=strlen(postfix);
    char cc;
    element ce;
    int pindex;
    float oprndval[125];
    int i;
    for(i=0;i<125;i++)
    {
        oprndval[i]=0; //ie we can't use use 0 as a value for any variable
    }
    for(pindex=0;pindex<plen;pindex++)
    {
        cc=postfix[pindex];
        if(isalpha(cc)&&oprndval[cc]==0)
        {
            printf("Enter value of %c\n",cc);
            scanf("%f",&oprndval[cc]);
        }
    }
    for(pindex=0;pindex<plen;pindex++)
    {
        cc=postfix[pindex];
    if(isalpha(cc)){
            ce.key=oprndval[cc];
            push(ce);
        }
    else if(isdigit(cc))
    {
        ce.key=(float)cc-'0';
        push(ce);
    }
    else if(isoperator(cc))
    {
        float op2=pop().key;

        float op1=pop().key;

        switch(cc)
        {
        case '+':
            {
                ce.key=op1+op2;

                break;
            }
        case '-':
            {
                ce.key=op1-op2;
                break;
            }
        case '*':
            {
                ce.key=op1*op2;
                break;
            }
        case '/':
            {
                ce.key=op1/op2;
                break;
            }
        case '^':
            {
                ce.key=pow(op1,op2);
                break;
            }

        }
        push(ce);
    }
    else
        printf("invalid\n");

    }

    printf("Answer=%.2f\n",pop().key);

}
void main()
{
    char postfix[50];
    printf("Enter the post fix equation:\n");
    gets(postfix);
    evalpostfix(postfix);
}
