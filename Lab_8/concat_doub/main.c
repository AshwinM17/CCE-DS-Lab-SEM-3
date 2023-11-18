#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dNode
{
    int data;
    struct dNode* previous;
    struct dNode* next;
}dNode;
typedef struct dNode* nptr;

//create a node
nptr createNode(int value)
{
    nptr temp = (nptr)malloc(sizeof(dNode));
    if(temp == NULL)
    {
        printf("Heap is full\n");
    }
    temp->data = value;
    temp->next = NULL;
    temp->previous = NULL;
    return temp;
}

//Insert an element at the rear end of the list
void insertRear(int value,nptr* head)
{
    nptr temp = createNode(value);
    //if first element
    if(*head==NULL)
    {
        *head = temp;
    }
    else
    {
        nptr current = *head;
        while(current->next!=NULL)
        {
            current = current->next;
        }
        temp->previous = current;
        current->next = temp;
    }
}

//concatenate two linked list
void concat(nptr* x1, nptr x2) //*x1 as x1 has to change and not x2
{
    if(*x1 == NULL)
    {
        *x1 = x2;
        return;
    }
    nptr current = *x1;
    while(current->next!=NULL)
    {
        current = current->next;
    }
    current->next = x2;
    if(x2!=NULL)
    {
        x2->previous = current;
    }
}
void main()
{
    nptr x1,x2;
    x1 = x2 = NULL;
    insertRear(1,&x1);
    insertRear(2,&x1);
    insertRear(4,&x2);
    insertRear(5,&x2);
    concat(&x1,x2);
    nptr current = x1;
    printf("Concatenated list is:\n");
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current = current->next;
    }
}
