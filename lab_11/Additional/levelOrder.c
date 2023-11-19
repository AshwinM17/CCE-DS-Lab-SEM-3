#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct TNode *Tptr;
typedef struct TNode
{
    int data;
    Tptr leftchild;
    Tptr rightchild;
}TNode;

typedef struct{
    Tptr key;
}element;

element Q[MAX];
int r=-1;
int f=-1;

element dequeue(){
    element ret;
    ret.key =NULL;
    if(f!=r){
        f++;
        ret = Q[f];
    }
    return ret;
}

void enqueue(element e){
    if(r<MAX){
        r++;
        Q[r]= e;
    }
}

/*
//Create nodes in the tree
Tptr createNode(int val)
{
    Tptr temp =(Tptr)malloc(sizeof(TNode));
    temp->data = val;
    temp->leftchild = temp->rightchild = NULL;
    return temp;
}
*/
//create the binary search tree
void createBST(Tptr *root)
{
    int N, i, val;
    Tptr current, previous;
    printf("Enter the number of nodes: ");
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        printf("Enter a unique value: ");
        scanf("%d", &val);
        Tptr temp = createNode(val);
        if (!*root)
        {
            *root = temp;
        }
        else
        {
            current = *root;
            previous = NULL;
            while (current)
            {
                previous = current;
                if (val < current->data)
                {
                    current = current->leftchild;
                }
                else if (val > current->data)
                {
                    current = current->rightchild;
                }
                if (val == previous->data)
                {
                    printf("Duplicate\n");
                    free(temp);
                    return;
                }
            }
            if (val < previous->data)
            {
                previous->leftchild = temp;
            }
            else
            {
                previous->rightchild = temp;
            }
        }
    }
}

//print in level order
void levelOrderTraversal(Tptr current) {
    if (current == NULL) {
        return;
    }
    element b;
    b.key = current;
    enqueue(b);

    while (f != r) { // i.e is not empty
        Tptr current = dequeue().key;
        printf("%d ", current->data);

        if (current->leftchild != NULL) {
            b.key = current->leftchild;
            enqueue(b);
        }

        if (current->rightchild != NULL) {
            b.key = current->rightchild;
            enqueue(b);
        }
    }
}

int mainc() {
    Tptr root = NULL;

    createBST(&root);

    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}
