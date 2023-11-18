#include <stdio.h>
#include <stdlib.h>

typedef struct node* nptr;//struct node is a strcture and struct node* is a ptr to the structure
typedef struct node
{
    int data;
    nptr next;  //nptr-is a pointer datatype (which points to the structure(node))

}node;
nptr createnode(int val)
{
    nptr temp;
    temp= (nptr)malloc(sizeof(node));
    temp->data=val;
    temp->next=NULL;

    return temp;
}
int main()
{
    nptr temp=createnode(5);
    printf("%d",temp->data);
    printf(" %d ",printf("a,b"));
}
