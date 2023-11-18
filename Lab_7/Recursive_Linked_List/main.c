#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
typedef struct node *nptr;
nptr head = NULL;
nptr createNode(int value)
{
    nptr temp = (nptr)malloc(sizeof(node));
    if (temp == NULL)
    {
        free(temp);
        exit(0);
    }
    temp->data = value;
    temp->next = NULL;
    return temp;
}
nptr insertAfter(nptr current,int data)
{
    if(current == NULL)
    {
        printf("Added %d\n",data);
        return createNode(data);
    }
    else
    {
        current->next=insertAfter(current->next,data);
    }
    return current;
}
void traverse(nptr current)
{
    if(current == NULL)
    {
        return;
    }
    else
    printf("%d ",current->data);
    traverse(current->next);
}
void main()
{

    head=insertAfter(head,3);
    head=insertAfter(head,4);
    head=insertAfter(head,5);
    head=insertAfter(head,6);
    traverse(head);
}
