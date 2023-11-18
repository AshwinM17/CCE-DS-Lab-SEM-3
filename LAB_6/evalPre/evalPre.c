#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include"ctype.h"
#include"floatStack.h"

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

//evaluate the prefix expression
void evaluate(char* prefix)
{
    int i;
    int plen = strlen(prefix);
    char cc;
    element ce;
    int pIndex;
    float oprVal[125];
    strrev(prefix);
    for(i=0; i<125; i++)
    {
        oprVal[i] = 0;
    }
    for(pIndex=0; pIndex<plen; pIndex++)
    {
        cc = prefix[pIndex];
        if(isalpha(cc) && oprVal[cc]==0)
        {
            printf("Enter the value of %c:",cc);
            scanf("%f",&oprVal[cc]);
        }
    }
    for(pIndex=0; pIndex<plen; pIndex++)
    {
        cc = prefix[pIndex];
        if(isalpha(cc))
        {
            ce.key = oprVal[cc];
            Push(ce);
        }
        else if(isdigit(cc))
        {
            ce.key = (float)(cc-'0');
            Push(ce);
        }
        else if(isOperator(cc))
        {
            float op1 = Pop().key;
            float op2 = Pop().key;
            switch(cc)
            {
            case '^':
                ce.key = pow(op1,op2);
                break;
            case '*':
                ce.key = op1 * op2;
                break;
            case '/':
                ce.key = op1 / op2;
                break;
            case '+':
                ce.key = op1 + op2;
                break;
            case '-':
                ce.key = op1 - op2;
                break;
            }
            Push(ce);
        }
        else
        {
            printf("invalid");
        }
    }
    printf("Answer is:%.2f",Pop().key);
}

int main()
{
    char prefix[50];
    printf("Enter prefix expression\n");
    scanf("%[^\n]s",prefix);
    evaluate(prefix);
    return 0;
}
