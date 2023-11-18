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
    element e;
    e.key[0]='\0';
    if (isempty())
    {
        return e;

    }
    else
    {
        return(stack[top--]);
    }
}
element peek()
{
    element e;
    e.key[0]='\0';
    if (isempty())
    {
        return e;

    }
    else
    {
        return(stack[top]);
    }
}
bool isoperator(char cc)
{
    if(cc=='+'||cc=='-'||cc=='*'||cc=='/'||cc=='^'){
        return true;

    }
    else
        return false;

}
