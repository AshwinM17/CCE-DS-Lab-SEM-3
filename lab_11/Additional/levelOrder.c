#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct TNode *Tptr;
typedef struct TNode {
    int data;
    Tptr leftchild;
    Tptr rightchild;
} TNode;

typedef struct {
    Tptr key;
} element;

element Q[MAX];
int r = -1;
int f = -1;

element dequeue() {
    element ret = {NULL};
    if (f != r) {
        f++;
        ret = Q[f];
    }
    return ret;
}

void enqueue(element e) {
    if (r < MAX - 1) {  // Check if the queue is not full
        r++;
        Q[r] = e;
    } else {
        printf("Queue is full\n");
    }
}

// Create nodes in the tree
Tptr createNode(int val) {
    Tptr temp = (Tptr)malloc(sizeof(TNode));
    if (temp) {
        temp->data = val;
        temp->leftchild = temp->rightchild = NULL;
    }
    return temp;
}

// Create the binary search tree
void createBST(Tptr *root) {
    int N, i, val;
    Tptr current, previous;

    printf("Enter the number of nodes: ");
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        printf("Enter a unique value: ");
        scanf("%d", &val);

        Tptr temp = createNode(val);
        if (!temp) {
            printf("Memory allocation failed\n");
            return;
        }

        if (!*root) {
            *root = temp;
        } else {
            current = *root;
            previous = NULL;
            int isDuplicate = 0; // Flag for duplicate

            while (current) {
                previous = current;
                if (val < current->data) {
                    current = current->leftchild;
                } else if (val > current->data) {
                    current = current->rightchild;
                } else {
                    printf("Duplicate. Will only be printed for first occurence.\n");
                    isDuplicate = 1; // Set flag if duplicate found
                    break; // Exit loop
                }
            }

            if (!isDuplicate) {
                if (val < previous->data) {
                    previous->leftchild = temp;
                } else {
                    previous->rightchild = temp;
                }
            } else {
                free(temp); // Free memory for duplicate node
            }
        }
    }
}

// Print in level order
void levelOrderTraversal(Tptr current) {
    if (current == NULL) {
        return;
    }

    element b;
    b.key = current;
    enqueue(b);

    while (f != r) { // While the queue is not empty
        Tptr currentNode = dequeue().key;
        printf("%d ", currentNode->data);

        if (currentNode->leftchild != NULL) {
            b.key = currentNode->leftchild;
            enqueue(b);
        }

        if (currentNode->rightchild != NULL) {
            b.key = currentNode->rightchild;
            enqueue(b);
        }
    }
}

int main() {
    Tptr root = NULL;

    createBST(&root);

    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}
