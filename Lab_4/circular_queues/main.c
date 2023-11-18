#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max_sz 5
typedef struct
{
    int key;
}element;
element cq[max_sz];
int r=0,f=0;
bool isfull()
{
    return(((r+1)%max_sz)==f);

}
bool isempty()
{
    return(r==f);
}
void insert(element e)
{
    if (!isfull())
    {
        cq[(r=(++r)%max_sz)]=e;
    }
    else
        printf("Stack is Full\n");
}
element delete()
{
    element ret;
    ret.key=-1;
    if(!isempty())
    {
        ret=cq[f=(++f)%max_sz];
    }
    else
        printf("Queue is empty\n");
    return ret;
}
void display()
{
    int i;
    element e;
    if(!isempty())
    {
    printf("Elements of the array are:-\n");
    for(i=((f+1)%max_sz);i!=r;i=((i+1)%max_sz))
        printf("%d ",cq[i]);
    printf("%d ",cq[i]);
    }
    else
        printf("Queue is Empty");
}
int main()
{
    char contin='y',contin2='y';
    int i,j;
    element e;
    int choice;
    while(contin2=='y'){
    printf("What do you want to do?\nPress 1 for pushing,2 for popping,3 for display:-\n");
    scanf("%d",&choice);
    switch (choice){
    case 1:
        {
            contin='y';
            while(contin=='y'){
            printf("Enter the element to be pushed:\n");
            scanf("%d",&e.key);
            insert(e);
            fflush(stdin);
            printf("Continue pushing?(y/n)\n");
            scanf("%c",&contin);
            }
            break;
        }
    case 2:
        {
            contin='y';
            while(contin=='y')
            {
                element e;
                e.key=-1;
                e=delete();
                if(e.key!=-1)
                    printf("Deleted element is:%d\n",e.key);
                fflush(stdin);
                printf("Continue popping?(y/n)\n");
                scanf("%c",&contin);
            }
            break;
        }
    case 3:
        {

           display();
           printf("\n");
           break;
        }
    }
    fflush(stdin);
    printf("Continue program?(y/n)\n");
    scanf("%c",&contin2);
    }
}
