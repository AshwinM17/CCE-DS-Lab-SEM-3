#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dNode
{
    int data;
    struct dNode* previous;
    struct dNode* next;
}dNode;
typedef struct dNode* nptr;

//create a node
nptr createNode(int value)
{
    nptr temp = (nptr)malloc(sizeof(dNode));
    if(temp == NULL)
    {
        printf("Heap is full\n");
    }
    temp->data = value;
    temp->next = NULL;
    temp->previous = NULL;
    return temp;
}

//Insert an element at the rear end of the list
void insertRear(int value,nptr* head)
{
    nptr temp = createNode(value);
    //if first element
    if(*head==NULL)
    {
        *head = temp;
    }
    else
    {
        nptr current = *head;
        while(current->next!=NULL)
        {
            current = current->next;
        }
        temp->previous = current;
        current->next = temp;
    }
}

nptr add(nptr num1, nptr num2)
{
    nptr result = NULL;
    int carry = 0;

    while(num1 != NULL || num2!= NULL || carry>0)
    {
        int sum = carry;
        if (num1 != NULL) {
            sum += num1->data;
            num1 = num1->previous;
        }
        if (num2 != NULL) {
            sum += num2->data;
            num2 = num2->previous;
        }

        carry = sum / 10;
        sum %= 10;

        insertRear(sum,&result);
    }
    return result;
}

int main()
{
    nptr num1 = NULL;
    nptr num2 = NULL;

    // Read the first long positive integer as a string and insert its digits into num1
    char num1Str[100];
    printf("Enter the first long positive integer: ");
    scanf("%s", num1Str);
    int len1 = strlen(num1Str);
    for (int i = 0; i < len1; i++) {
        int digit = num1Str[i] - '0';
        insertRear(digit,&num1);
    }

    // Read the second long positive integer as a string and insert its digits into num2
    char num2Str[100];
    printf("Enter the second long positive integer: ");
    scanf("%s", num2Str);
    int len2 = strlen(num2Str);
    for (int i = 0; i < len2; i++) {
        int digit = num2Str[i] - '0';
        insertRear(digit,&num2);
    }
    while(num1->next!=NULL)
    {
        num1=num1->next;
    }
    while(num2->next!=NULL)
    {
        num2=num2->next;
    }
    nptr result = add(num1, num2);
    while(result->next!=NULL)
    {
        result=result->next;
    }
    nptr current = result;
    printf("Result: ");
    while (current != NULL) {
        printf("%d", current->data);
        current = current->previous;
    }

    return 0;
}
