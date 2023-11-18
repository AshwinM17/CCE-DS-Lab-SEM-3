#include <stdio.h>
#include <stdlib.h>
#define max_sz 50
typedef struct
{
    int key;
}element;

element mstack[max_sz];
int *tops;
int *bnds;
void init(int n)
{
    int sz=(max_sz/n);
    tops=(int*)malloc(n*sizeof(int));
    bnds=(int*)malloc((n+1)*sizeof(int));
    tops[0]=-1;
    bnds[0]=-1;
    int i;
    for(i=1;i<n;i++)
    {
        tops[i]=sz*i;
        bnds[i]=sz*i;
    }
    bnds[n]=max_sz;
}

void push(element e,int i)//i is the index of stack to be acted upon
{
    if(tops[i]<bnds[i+1])
    {
        mstack[++tops[i]]=e;
    }
    else
        printf("stack %d is full\n",i);
}

element pop(int i)
{
    element ret;
    if(tops[i]>bnds[i])
    {

        ret=mstack[tops[i]];
        return ret;
    }
    else
    {
        ret.key=-1;
        return ret;
    }
}

void display(int i)
{
    int k;
    printf("elements in the stack %d are:\n",i);
    for(k=tops[i];k>bnds[i];k--)
    {
        element e;
        e=mstack[k];
        printf("%d ",e.key);
    }
}
int main()
{
    int k,n;
    printf("how many stacks do you want\n");
    fflush(stdin);
    scanf("%d",&n);
    init(n);
    printf("The elements of top array at initialization are:\n");
    for(k=0;k<n;k++)
        printf("%d ",tops[k]);
    printf("\nThe elements of bounds array at initialization are:\n");
    for(k=0;k<=n;k++)
        printf("%d ",bnds[k]);
    char contin='y';
    int ind,j;
    element e;
    printf("\nenter the elements in the stacks:\n");
    while(contin=='y')
    {
        printf("index of stack in which element should be added:\n");
        scanf("%d",&ind);
        printf("Enter the element to be added:\n");
        scanf("%d",&e.key);
        push(e,ind);
        fflush(stdin);
        printf("continue?(y/n)\n");
        scanf("%c",&contin);
    }
    contin='y';
    while(contin=='y')
    {
        printf("index of stack to be displayed\n");
        scanf("%d",&ind);
        display(ind);
        printf("\ncontinue?(y/n)\n");
        fflush(stdin);
        scanf("%c",&contin);
    }
    return 0;
}
