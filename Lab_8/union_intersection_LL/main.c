#include <stdio.h>
#include <stdlib.h>

typedef struct dNode {
    int data;
    struct dNode* previous;
    struct dNode* next;
} dNode;

typedef struct dNode* nptr;

// Function to create a new node
nptr createNode(int value) {
    nptr newNode = (nptr)malloc(sizeof(dNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->previous = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the rear of the list
void insertRear(nptr* head, int value) {
    nptr newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        nptr current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->previous = current;
    }
}

// Function to check if a value is present in the list
int isPresent(nptr head, int value) {
    nptr current = head;
    while (current != NULL) {
        if (current->data == value) {
            return 1; // Value is present
        }
        current = current->next;
    }
    return 0; // Value is not present
}

// Function to find the union of two lists
nptr findUnion(nptr head1, nptr head2) {
    nptr result = NULL;
    nptr current1 = head1;
    nptr current2 = head2;

    // Add all elements from the first list to the result
    while (current1 != NULL) {
        insertRear(&result, current1->data);
        current1 = current1->next;
    }

    // Traverse the second list, add elements to the result if not already present
    while (current2 != NULL) {
        if (!isPresent(result, current2->data)) {
            insertRear(&result, current2->data);
        }
        current2 = current2->next;
    }

    return result;
}

// Function to find the intersection of two lists
nptr findIntersection(nptr head1, nptr head2) {
    nptr result = NULL;
    nptr current1 = head1;

    // Traverse the first list
    while (current1 != NULL) {
        if (isPresent(head2, current1->data)) {
            insertRear(&result, current1->data);
        }
        current1 = current1->next;
    }

    return result;
}

// Function to print the elements of a list
void traverse(nptr head) {
    nptr current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    nptr head1 = NULL; // First doubly linked list
    nptr head2 = NULL; // Second doubly linked list

    // Populate the first list
    insertRear(&head1, 5);
    insertRear(&head1, 4);
    insertRear(&head1, 3);

    // Populate the second list
    insertRear(&head2, 4);
    insertRear(&head2, 2);
    insertRear(&head2, 1);
    insertRear(&head2, 5);

    printf("First List: ");
    traverse(head1);

    printf("Second List: ");
    traverse(head2);

    // Find and print the union of the lists
    nptr unionResult = findUnion(head1, head2);
    printf("Union List: ");
    traverse(unionResult);

    // Find and print the intersection of the lists
    nptr intersectionResult = findIntersection(head1, head2);
    printf("Intersection List: ");
    traverse(intersectionResult);

    return 0;
}
