#include <stdio.h>
#include <stdlib.h>

typedef struct pnode* pptr;
typedef struct pnode
{
    int coeff;
    int expo;
    pptr next;
} pnode;

// create node in the linked list
pptr createNode(int coeff,int expo)
{
    pptr temp = (pptr)malloc(sizeof(pnode));
    if (temp == NULL)
    {
        printf("Heap is full");
        free(temp);
        exit(0);
    }
    temp->coeff = coeff;
    temp->expo = expo;
    temp->next = NULL;
    return temp;
}

//insert element at the end of the linked list
void insertEnd(int coeff,int expo,pptr* head)
{
    pptr temp = createNode(coeff,expo);
    if(*head == NULL)
    {
        *head = temp;
    }
    else
    {
        pptr current = *head;
        while(current->next)
        {
            current = current->next;
        }
        current->next = temp;
    }
}


void attach(int coeff,int expo,pptr* rear)//we do *rear as we pdate the rear and ,=move it forword otherwise we didi not need to change it if only rear ke aage add karna hota
{
    pptr temp;
    temp = (pptr)malloc(sizeof(pnode));
    temp->coeff = coeff;
    temp->expo = expo;
    temp->next = NULL;

    (*rear)->next = temp;
    *rear = temp;
}

pptr polyAdd(pptr A,pptr B)
{
    pptr C,rear,temp;
    rear = (pptr)malloc(sizeof(pnode));
    C = rear;
    while(A && B)
    {
        int diff = A->expo - B->expo;

        //A->expo < B->expo
        if(diff<0)
        {
            attach(B->coeff,B->expo,&rear);
            B = B->next;
            break;
        }

        //A->expo > B->expo
        else if(diff>0)
        {
            attach(A->coeff,A->expo,&rear);
            A = A->next;
            break;
        }

        //A->expo = B->expo
        else
        {
            int sum = A->coeff + B->coeff;
            if(sum)
            {
                attach(sum,A->expo,&rear);
            }
            A = A->next;
            B = B->next;
        }
    }

    //attach remaining nodes for A and B
    for(;A;A = A->next)
    {
        attach(A->coeff,A->expo,&rear);
    }
    for(;B;B=B->next)
    {
        attach(B->coeff,B->expo,&rear);
    }

    temp = C;
    C = C->next;
    free(temp);
    return C;
}

int main()
{
    pptr A,B;
    A = B = NULL;
    insertEnd(3,3,&A);
    insertEnd(4,2,&A);
    insertEnd(1,0,&A);
    pptr current = A;
    printf("1st Polynomial separated by commas is:\n");
    while(current)
    {
        printf("%dx^%d,",current->coeff,current->expo);
        current = current->next;
    }
    printf("\n");

    insertEnd(6,4,&B);
    insertEnd(5,2,&B);
    insertEnd(4,1,&B);
    current = B;
    printf("2nd Polynomial separated by commas is:\n");
    while(current)
    {
        printf("%dx^%d,",current->coeff,current->expo);
        current = current->next;
    }
    printf("\n");


    pptr C = polyAdd(A,B);
    current = C;
    printf("Added Polynomial separated by commas is:\n");
    while(current)
    {
        printf("%dx^%d,",current->coeff,current->expo);
        current = current->next;
    }
    return 0;
}
