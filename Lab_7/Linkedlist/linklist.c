#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct node *nptr;
typedef struct node
{
    int data;
    nptr next;
}node;

nptr head=NULL;

nptr createnode(int val)
{
    nptr temp;
    temp=(nptr)malloc(sizeof(node));
    temp->data=val;
    temp->next=NULL;
    return temp;
}

void insertbefore(int val,int nval)
{
    nptr temp=createnode(val);
    if(head==NULL)
    {
        head=temp;
        return;
    }
    else
    {
        nptr current=head,prev=NULL;
        bool found=false;
        while(current!=NULL)
        {
            if(nval==current->data)
            {
                found=true;
                break;
            }
            prev=current;
            current=current->next;
        }
        if(found)
        {
            if(prev==NULL)
            {
                temp->next=head;
                head=temp;
            }
            else{
                temp->next=current;
                prev->next=temp;
            }
        }
        else
        {
            printf("element not found\n");
            free(temp);
        }


    }
}
void insertafter(int val,int nval)
{
    nptr temp=createnode(val);
    nptr current=head;
    bool found=false;
    if(head==NULL)
    {
        head=temp;
        return;
    }
    while(current!=NULL)
    {
        if (current->data==nval)
        {
            found=true;
            break;
        }
        current=current->next;
    }
    if(found)
    {
        temp->next=current->next;
        current->next=temp;
    }
    else
    {
        printf("Not found\n");
        free(temp);
    }
}

void delelem(int nval)
{
    nptr current=head;
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    bool found=false;
    nptr prev=NULL;
    while(current!=NULL)
    {

        if(current->data==nval)
        {
            found=true;
            break;
        }

        prev=current;
        current=current->next;
    }
    if (found && current==head)
    {
        printf("Removed %d\n",nval);
        head=head->next;
        free(current);
    }
    else if (found)
    {
        printf("Removed %d\n",nval);
        prev->next=current->next;
        free(current);
    }
    else
    {
        printf("Element is not present\n");
    }
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
void reverse()
{
    nptr current=head;
    nptr prev=NULL;
    while(current!=NULL)
    {
        nptr cnext=current->next;
        current->next=prev;
        prev=current;
        current=cnext;
    }
    head=prev;
}
void deletealt()
{
    nptr current=head;
    while(current->next!=NULL)
    {
        nptr cnext=current->next;
        current->next=cnext->next;
        free(cnext);
        current=current->next;
    }
}
void insertsort(int val)
{
    nptr temp=createnode(val);
    nptr current =head;
    if(head->data >val)
    {
        temp->next=current;
        head=temp;

        return;
    }

    while(current->next!=NULL && current->next->data < val )
    {
        current=current->next;
    }

    if(current->next==NULL)
    {
        current->next=temp;

        return;
    }
    temp->next=current->next;
    current->next=temp;

}
void sort()
{
    nptr current=head;
    int buffer;
    while(current->next!=NULL)
    {

        nptr key=head;
        while(key->next!=NULL)
        {
            if(key->data > key->next->data)
            {

                buffer=key->data;
                key->data=key->next->data;
                key->next->data=buffer;

            }
            key=key->next;
        }
        current=current->next;
    }

}
void main()
{
    int choice;
    int val1, val2;
    printf("Enter\n 1)Insert an element before another element in the existing list\n 2) Insert an element after another element in the existing list\n 3) Delete a given element from the list\n 4) Traverse the list\n 5) Reverse the list\n 6) Sort the list\n 7) Delete every alternate node in the list\n 8) Insert an element in a sorted list such that the order is maintained.\n");
    scanf("%d",&choice);
    do
    {
        switch (choice)
        {
        case 1:
            printf("Enter element to be entered and before element:");
            scanf("%d%d", &val1,&val2);
            insertbefore(val1,val2);
            break;
        case 2:
            printf("Enter element to be entered and after element:");
            scanf("%d%d", &val1, &val2);
            insertafter(val1, val2);
            break;
        case 3:
            printf("Enter element to be deleted:");
            scanf("%d", &val1);
            delelem(val1);
            break;
        case 4:
            traverse();
            break;
        case 5:
            reverse();
            printf("After reversing the List\n");
            traverse();
            break;
        case 6:
            sort();
            printf("After sorting the List\n");
            traverse();
            break;
        case 7:
            deletealt();
            traverse();
            break;
        case 8:
            printf("Enter element to be entered:");
            scanf("%d", &val1);
            insertsort(val1);
            traverse();
            break;
        }
        printf("\nEnter 0 to terminate or another function's number to continue:\n");
        scanf("%d", &choice);
    } while (choice != 0);
}
