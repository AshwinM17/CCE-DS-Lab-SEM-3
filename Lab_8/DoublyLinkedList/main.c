#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <math.h>
typedef struct node *nptr;
typedef struct node
{
    int data;
    nptr next;
    nptr prev;
}node;
nptr head=NULL;
nptr tail=NULL;

nptr createnode(int val)
{
    nptr temp;
    temp=(nptr)malloc(sizeof(node));
    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
void traverse()
{
    nptr current=head;
    printf("The elements of the list are:-\n");
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
}
void insertend(int val)
{
    nptr temp=createnode(val);

    if(tail==NULL && head==NULL) //case when it is empty
    {
        head=temp;
        tail=temp;
    }
    else
    {
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }

}

void delend()
{
    if(tail==NULL)
    {
        printf("List is empty");
    }
    else
    {

        tail->prev->next=NULL;
        tail=tail->prev;
    }
}
void insertpos(int val,int pos)
{
    int k;
    nptr current=head;
    nptr temp=createnode(val);
    for(k=1;current!=NULL && k<pos;k++)
    {
        current=current->next;
    }
    if(current==NULL)
    {
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
    else if(pos==1 || pos==0)
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    else
    {
        current->prev->next=temp;
        temp->prev=current->prev;
        current->prev=temp;
        temp->next=current;
    }
}
void deletePosition(int position)
{
    //list is empty
    if(head==NULL && tail==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        int i;
        nptr current = head;
        //iterate till we reach position
        for(i=0;i<position-1 && current!=NULL;i++)
        {
            current = current->next;
        }
        //if last element or position outside boundary delete to end
        if(current==NULL || current->next==NULL)
        {
            delend();
        }
        //if first element
        else if(current==head)
        {
            head = current->next;
            head->prev = NULL;
            free(current);
        }
        //if not head or rear
        else
        {
            nptr currentPrevious = current->prev;
            nptr currentNext = current->next;
            currentPrevious->next = currentNext;
            currentNext->prev = currentPrevious;
            free(current);
        }
    }
}
void insertBefore(int value, int beforeValue)
{
    // in case list is empty
    if (head == NULL)
    {
        nptr temp = createnode(value);
        head = temp;
        return;
    }
    bool found = false;
    nptr current = head;
    //iterate to find the node
    while (current != NULL)
    {
        if (current->data == beforeValue)
        {
            found = true;
            break;
        }
        current = current->next;
    }
    //if element is found
    if (found)
    {
        nptr temp = createnode(value);
        // in case to be inserted before first element
        if (current->prev == NULL)
        {
            temp->next = current;
            head=temp;
        }
        else
        {
            temp->next = current;
            temp->prev = current->prev;
            current->prev->next = temp;
            current->prev = temp;
        }
    }

    //if node is not found
    else
    {
        printf("Node not found in list");
    }
}
void insertAfter(int value, int afterValue)
{
    // in case list is empty
    if (head == NULL)
    {
        nptr temp = createnode(value);
        head = temp;
        return;
    }

    bool found = false;
    nptr current = head;
    //iterate to find node
    while (current != NULL)
    {
        if (current->data == afterValue)
        {
            found = true;

            break;
        }
        current = current->next;
    }
    //if node is found we insert
    if (found)
    {

        nptr temp = createnode(value);
        temp->next = current->next;

        temp->prev = current;
        if(current->next)//to check if end
            current->next->prev = temp;
        current->next = temp;
    }
    //if node is not found
    else
    {
        printf("Node not found in list");
    }
}
void reverse()
{
    // in case list is empty
    if (head == NULL || head->next==NULL)
    {
        printf("List is empty or only one element");
        return;
    }

    nptr temp = NULL;
    nptr current = head;

    while (current!=NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)//ie not1 element

        tail=head;
        head = temp->prev;
}

void main()
{
    printf("%f",(pow(3.0,2.0)));
    insertend(1);
    insertend(2);
    insertend(3);
    insertend(4);
    insertend(44);
    traverse();
    delend();
    traverse();
    insertpos(44,5);// case of end not working,now working
    traverse();
    deletePosition(3);
    traverse();
    insertBefore(77,3);
    traverse();
    insertAfter(88,3);
    traverse();
    reverse();
    traverse();
}
