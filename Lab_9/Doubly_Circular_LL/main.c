#include <stdio.h>
#include <stdlib.h>
typedef struct cnode *cnptr;
typedef struct cnode
{
    int data;
    cnptr next;
    cnptr prev;
}cnode;
cnptr last=NULL;

cnptr createCnode(int val)
{
    cnptr temp=(cnptr)malloc(sizeof(cnode));
    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
void insertBegin(int val)
{
    cnptr temp=createCnode(val);
    if(last==NULL)
    {
        last=temp;
        last->next=last;
        last->prev=last;
    }
    else
    {
        temp->next=last->next;//head
        last->next->prev=temp;
        temp->prev=last;
        last->next=temp;
    }
}
void deleteend()
{
    cnptr current;
    if(last==NULL)
    {
        printf("List is empty");
    }
    else
    {
        cnptr previous=last->prev;
        previous->next=last->next;
        last->next->prev=previous;
        free(last);
        last=previous;
    }
}
void revtraverse()
{
    cnptr current=last;
    printf("%d ",current->data);
    current=current->prev;
    while(current!=last)
    {
        printf("%d ",current->data);
        current=current->prev;
    }
    printf("\n");
}
void traverse()
{
    cnptr current=last;
    current=current->next;
    while(current!=last)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    printf("%d\n",current->data);
}
int main()
{
    char contin='y';
    int choice;
    while(contin=='y')
    {
        printf("What do you want to do? \n 1. For inserting at beginning \n 2. For deleting at the end. \n 3. For traversing the doubly LL\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                int val;
                printf("Enter the value\n");
                scanf("%d",&val);
                insertBegin(val);
                break;
            }
        case 2:
            {
                deleteend();
                printf("Element deleted\n");
                break;
            }
        case 3:
            {
                printf("elements of the list are\n");
                traverse();
                break;
            }
        }
        printf("continue?(y/n)\n");
        fflush(stdin);
        scanf("%c",&contin);
    }

}


