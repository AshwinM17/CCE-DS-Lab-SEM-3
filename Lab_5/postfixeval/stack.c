#include "stack.h"
int top=-1;

bool isempty()
{
    return(top==-1);
}
bool isfull()
{
    return (top==Max_size-1);
}
void push(element e)
{
    if (isfull())
    {
        printf("Stack is full,can't be pushed into\n");
    }
    else
        stack[++top]=e;
}
element pop()
{
    if (isempty())
    {
        printf("Stack is empty,can't be popped\n");

    }
    else
    {
        return(stack[top--]);
    }
}

// changes to be made here for datatype
void display()
{
    char i;
    for(i=top;i>=0;i--)
    {
        printf("%c",stack[i].key);
    }
}
element peek()
{
    if (isempty())
    {
        printf("Stack is empty\n");

    }
    else
    {
        return(stack[top]);
    }
}

bool isoperator(char cc)
{
    if(cc=='+'||cc=='-'||cc=='*'||cc=='/'||cc=='^')
        return true;
    else
        return false;
}
