#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max_sz 5
int stack1[max_sz], stack2[max_sz];
int top1=-1, top2=-1;
int count=0;
// inserting the elements in stack1.
void push1(int data)
{
    if(top1==max_sz-1)
    {
        printf("\n Stack is Full");
    }
    else
    {
        stack1[++top1]=data;
    }
}
int pop1()
{
    if(top1==-1)
    {
        printf("\nStack is empty");
    }
    else
    {
        int a=stack1[top1--];
        return a;
    }
}
void push2(int data)
{
    if(top2==max_sz-1)
    {
        printf("\nStack is Full");
    }
    else
    {
        stack2[++top2]=data;
    }
}
int pop2()
{
   int element = stack2[top2--];
   return element;
}
void insert(int x)
{
    push1(x);
    count++;
}
void del()
{
   if((top1==-1) && (top2==-1))
{
   printf("\nQueue is empty");
}
else
{
  for(int i=0;i<count;i++)
  {
     int element = pop1();
     push2(element);
  }
    int b= pop2();
    printf("The deleted element is %d\n", b);
    count--;
    for(int i=0;i<count;i++)
    {
        int a = pop2();
        push1(a);
    }
    }
}
void display()
{
    printf("Elements in Queue are:\n");
   for(int i=0;i<=top1;i++)
  {
     printf("%d ", stack1[i]);
  }
  printf("\n");
}
void main()
{
   insert(10);
   insert(20);
   insert(30);
   display();
   del();
   del();
   display();
}
