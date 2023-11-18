#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
typedef struct node *nptr;

// create node in the linked list
nptr createNode(int value)
{
    nptr temp = (nptr)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("Heap is full");
        free(temp);
        exit(0);
    }
    temp->data = value;
    temp->next = NULL;
    return temp;
}

// insert a node at the end of the list
void insertEnd(nptr *head,int val)
{
    nptr temp = createNode(val);

    // if the list is empty
    if (*head == NULL)
    {

        *head = temp;
        return;
    }

    nptr current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = temp;
}

nptr merge(nptr xHead, nptr yHead)
{
    nptr mHead = NULL;
    nptr mCurrent = NULL;

    nptr xCurrent = xHead;
    nptr yCurrent = yHead;

    // Determine the head of the merged list
    if (xCurrent->data < yCurrent->data) {
        mHead = xCurrent;
        xCurrent = xCurrent->next;
    } else {
        mHead = yCurrent;
        yCurrent = yCurrent->next;
    }
    mCurrent = mHead;
    // Merge the two lists
    while (xCurrent != NULL && yCurrent != NULL) {
        if (xCurrent->data < yCurrent->data) {
            mCurrent->next = xCurrent;
            xCurrent = xCurrent->next;
        } else {
            mCurrent->next = yCurrent;
            yCurrent = yCurrent->next;
        }
        mCurrent = mCurrent->next;
    }
    // Append any remaining elements
    if (xCurrent != NULL) {
        mCurrent->next = xCurrent;
    } else {
        mCurrent->next = yCurrent;
    }

    return mHead;
}
void main() {
    nptr xHead = createNode(10);
    xHead->next = createNode(200);
    xHead->next->next = createNode(300);

    nptr yHead = createNode(100);
    yHead->next = createNode(400);
    yHead->next->next = createNode(600);
    // Merge the two sorted linked lists
    nptr mergedHead = merge(xHead, yHead);

    // Print the merged linked list
    nptr current = mergedHead;
    printf("Merged List: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}





