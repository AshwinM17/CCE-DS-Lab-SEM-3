#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>
#include <ctype.h>

void post_infix(char *postfix)
{
    int plen=strlen(postfix);
    char cs[2];
    char oprnd1[100],oprnd2[100];
    int pindex;
    element ce;

    for(pindex=0;pindex<plen;pindex++)
    {

        cs[0]=postfix[pindex];
        cs[1]='\0';  //converting char to string
        if (isalnum(cs[0]))
        {
            strcpy(ce.key,cs);
            push(ce);

        }
        if(isoperator(cs[0]))
        {

            strcpy(oprnd2,pop().key);
            strcpy(oprnd1,pop().key);
            strcpy(ce.key,"(");
            strcat(ce.key,oprnd1);
            strcat(ce.key,cs);
            strcat(ce.key,oprnd2);
            strcat(ce.key,")");
            push(ce);
        }
    }
    printf("Required infix expression is:");
    puts(pop().key);
}

void main()
{
    char postfix[100];
    printf("Enter the postfix expression:\n");
    gets(postfix);
    post_infix(postfix);


}
