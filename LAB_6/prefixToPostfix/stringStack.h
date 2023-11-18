#ifndef STRINGSTCK_H_INCLUDED
#define STRINGSTCK_H_INCLUDED

#define MAX_SIZE 60
#include<stdbool.h>
#include<string.h>

typedef struct
{
    char key[100];
} element;

element stack[MAX_SIZE];
int top=-1;
int i;

//check if stack is empty
bool isEmpty()
{
    return top==-1;
}

//check if stack is full
bool isFull()
{
    return top==MAX_SIZE -1;
}

//push element onto stack
void Push(element e)
{
    if(isFull())
    {
        printf("Stack is full");
        return;
    }
    stack[++top]=e;
}

//pop element from stack
element Pop()
{
    element popped;
    strcpy(popped.key,"\0");
    if(isEmpty())
    {
        printf("Stack is empty");
    }
    else
    {
        popped=stack[top--];
    }
    return popped;
}

//return element at the top
element Peek()
{
    return stack[top];
}

//display the elements
void display()
{
    for(i=top;i>=0;i--)
    {
        printf("%s",stack[i].key);
    }
}

#endif // STRINGSTCK_H_INCLUDED
