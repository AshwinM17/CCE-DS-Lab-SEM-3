#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct cnode *cnptr;
typedef struct cnode
{
    int data;
    char name[100];
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
void insertBegin(int val,char nam[])
{
    cnptr temp=createCnode(val);
    strcpy(temp->name,nam);
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
        printf("Queue is empty");
    }
    else
    {
        printf("Next person is %s for %d mins\n",last->name,last->data);
        cnptr previous=last->prev;
        previous->next=last->next;
        last->next->prev=previous;
        free(last);
        last=previous;
    }
}
void traverse()
{
    cnptr current=last;
    current=current->next;
    while(current!=last)
    {
        printf("%s ",current->name);
        current=current->next;
    }
    printf("%s\n",current->name);
}
int main()
{
    char contin='y';
    int choice;
    while(contin=='y')
    {
        printf("What do you want to do?1 adding person to queue,2)give the chance to next person,3) to view the Queue\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                int val;
                printf("Enter the name:\n");
                fflush(stdin);
                char name[100];
                gets(name);
                printf("Enter the time in mins\n");
                scanf("%d",&val);
                insertBegin(val,name);
                break;
            }
        case 2:
            {
                deleteend();
                break;
            }
        case 3:
            {
                printf("people in the Queue are\n");
                traverse();
                break;
            }
        }
        printf("continue?(y/n)\n");
        fflush(stdin);
        scanf("%c",&contin);
    }

}


