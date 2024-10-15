#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

typedef struct TNode *Tptr;
typedef struct TNode {
    int data;
    Tptr leftchild;
    Tptr rightchild;
} TNode;

Tptr root;

int top = -1;
Tptr stack[MAX];

// Create nodes in the tree
Tptr createNode(int val) {
    Tptr temp = (Tptr)malloc(sizeof(TNode));
    temp->data = val;
    temp->leftchild = temp->rightchild = NULL;
    return temp;
}

// Create the binary tree
void createTree(int N) {
    int cData, dIndex;
    char dir[50];
    Tptr previous = NULL, current;

    for (int i = 0; i < N; i++) {
        printf("Enter data for node %d (integer value): ", i + 1);
        scanf("%d", &cData);
        Tptr temp = createNode(cData);

        // Assign root node
        if (!root) {
            root = temp;
        } else {
            printf("Enter the direction to insert (L for left, R for right): ");
            scanf("%s", dir);
            current = root;
            previous = NULL;

            for (dIndex = 0; dir[dIndex] != '\0' && current != NULL; dIndex++) {
                previous = current;
                if (dir[dIndex] == 'L' || dir[dIndex] == 'l') {
                    current = current->leftchild;
                } else if (dir[dIndex] == 'R' || dir[dIndex] == 'r') {
                    current = current->rightchild;
                } else {
                    printf("Invalid direction. Use 'L' for left and 'R' for right.\n");
                    free(temp);
                    return;
                }
            }

            if (current != NULL || dir[dIndex] != '\0') {
                printf("Invalid position for insertion.\n");
                free(temp);
                return;
            }
            if (dir[dIndex - 1] == 'L' || dir[dIndex - 1] == 'l') {
                previous->leftchild = temp;
            } else {
                previous->rightchild = temp;
            }
        }
    }
}

bool isFull() {
    return top == MAX;
}

bool isEmpty() {
    return top == -1;
}

// Push nodes onto the stack
void Push(Tptr node) {
    if (!isFull()) {
        stack[++top] = node;
    }
}

// Pop node from the stack
Tptr Pop() {
    Tptr ret = NULL;
    if (!isEmpty()) {
        ret = stack[top--];
    }
    return ret;
}

Tptr peek() {
    return stack[top];
}

// Print node elements in inorder
void IterativeInorder(Tptr node) {
    while (true) {
        while (node) { // Push all left children
            Push(node);
            node = node->leftchild;
        }
        node = Pop();
        if (node == NULL) { // Stack is empty
            break;
        }
        printf("%d ", node->data);
        node = node->rightchild;
    }
}

// Print node elements in preorder
void IterativePreorder(Tptr node) {
    for (;;) {
        for (; node; node = node->leftchild) {
            Push(node);
            printf("%d ", node->data);
        }
        node = Pop();
        if (node == NULL) {
            break;
        }
        node = node->rightchild;
    }
}

// Print node elements in postorder
void IterativePostorder(Tptr node) {
    while (true) {
        if (node) { // Push all left children
            Push(node);
            node = node->leftchild;
        } else {
            if (!peek()) { // Stack is empty
                break;
            }

            Tptr temp = peek()->rightchild;

            if (temp == NULL) { // Right child doesn't exist
                temp = Pop();
                printf("%d ", temp->data);
                while (!isEmpty() && temp == peek()->rightchild) { // Only when temp is the right child of the top
                    temp = Pop(); // Extra pop if it is the right child
                    printf("%d ", temp->data);
                }
            } else { // If right child of the top of stack exists, push it and its left children
                node = temp;
            }
        }
    }
}

// Return the parent of a given node
Tptr ParentNode(Tptr node, int target) {
    if (!node) {
        return NULL;
    }

    if ((node->leftchild && node->leftchild->data == target) || (node->rightchild && node->rightchild->data == target)) {
        return node;
    }

    // Return left if not null, else return right
    Tptr left = ParentNode(node->leftchild, target);
    if (left != NULL) {
        return left;
    }

    return ParentNode(node->rightchild, target);
}

// Count nodes
void countnodes(TNode* root, int *count) {
    if (root) {
        (*count)++;
        countnodes(root->leftchild, count);
        countnodes(root->rightchild, count);
    }
}

int cntnodes(TNode* node) {
    if (!node) {
        return 0;
    } else {
        int right = cntnodes(node->rightchild);
        int left = cntnodes(node->leftchild);
        return left + right + 1;
    }
}

// Find the depth of a given tree
int maxDepth(Tptr root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftDepth = maxDepth(root->leftchild);
        int rightDepth = maxDepth(root->rightchild);
        return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
    }
}

// Print all the ancestors of a node
int printAncestors(Tptr root, int target) {
    if (root == NULL) {
        return 0;
    }

    if (root->data == target) {
        return 1;
    }

    if (printAncestors(root->leftchild, target) || printAncestors(root->rightchild, target)) {
        printf("%d ", root->data);
        return 1;
    }

    return 0;
}

// Count the number of leaf nodes in a tree
int countLeafNodes(Tptr root) {
    if (root == NULL) {
        return 0;
    }

    if (root->leftchild == NULL && root->rightchild == NULL) {
        return 1;
    } else {
        int leftLeafCount = countLeafNodes(root->leftchild);
        int rightLeafCount = countLeafNodes(root->rightchild);
        return leftLeafCount + rightLeafCount;
    }
}

void cntleaf(Tptr root, int *count) {
    if (root && (root->leftchild) == NULL && (root->rightchild) == NULL) {
        (*count)++;
    }
    if (root) {
        cntleaf(root->leftchild, count);
        cntleaf(root->rightchild, count);
    }
    if (!root) {
        return;
    }
}

int main() {
    int N;
    root = NULL;
    int choice, target;
    int lcount = 0; // Move this declaration here

    do {
        printf("\nBinary Tree Operations\n");
        printf("1. Create Tree\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Find Parent of a Node\n");
        printf("6. Find Depth of the Tree\n");
        printf("7. Print Ancestors of a Node\n");
        printf("8. Count Leaf Nodes\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Create the binary tree
                printf("Enter the number of nodes: ");
                scanf("%d", &N);
                createTree(N);
                int count = cntnodes(root);
                printf("Number of nodes: %d\n", count);
                break;

            case 2:
                // Inorder Traversal
                printf("Inorder Traversal: ");
                IterativeInorder(root);
                printf("\n"); // New line for clarity
                break;

            case 3:
                // Preorder Traversal
                printf("Preorder Traversal: ");
                IterativePreorder(root);
                printf("\n");
                break;

            case 4:
                // Postorder Traversal
                printf("Postorder Traversal: ");
                IterativePostorder(root);
                printf("\n");
                break;

            case 5:
                // Find Parent of a Node
                printf("Enter the value of the target node (integer): ");
                scanf("%d", &target);
                Tptr parent = ParentNode(root, target);
                if (parent) {
                    printf("Parent of %d is %d\n", target, parent->data);
                } else {
                    printf("Node not found\n");
                }
                break;

            case 6:
                // Find Depth of the Tree
                printf("Depth of the tree is: %d\n", maxDepth(root));
                break;

            case 7:
                // Print Ancestors of a Node
                printf("Enter the value of the target node (integer): ");
                scanf("%d", &target);
                printf("Ancestors of %d: ", target);
                if (!printAncestors(root, target)) {
                    printf("No ancestors found or node does not exist.\n");
                }
                printf("\n");
                break;

            case 8:
                // Count Leaf Nodes
                lcount = 0; // Reset count for each call
                cntleaf(root, &lcount);
                printf("Number of leaf nodes: %d\n", lcount);
                break;

            case 9:
                // Exit
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);

    return 0;
}
