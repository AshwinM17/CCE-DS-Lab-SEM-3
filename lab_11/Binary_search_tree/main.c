#include <stdio.h>
#include <stdlib.h>
typedef struct tnode * tptr;
typedef struct tnode
{
    int data;
    tptr rchild;
    tptr lchild;
}tnode;
tptr root=NULL;
createBST()
{
    int n,i,val;
    tptr current,previous;
    printf("enter no of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the unique no:\n");
        scanf("%d",&val);
        tptr temp=(tptr)malloc(sizeof(tnode));
        temp->data=val;
        temp->lchild=temp->rchild=NULL;
        if(root==NULL)
        {
            root=temp;
        }
        while
    }

}
int main()
{
    printf("Hello world!\n");
    return 0;
}
