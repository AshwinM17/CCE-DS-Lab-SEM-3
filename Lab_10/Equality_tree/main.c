#include <stdio.h>
#include <stdlib.h>
typedef struct Node * tptr;
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

tptr createNode(int data) {
    tptr newNode = (tptr)malloc(sizeof(Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int areEqual(tptr tree1, tptr tree2) {
    // if both trees are empty, they equal
    if (tree1 == NULL && tree2 == NULL) {
        return 1;
    }

    // if only one tree empty, they not equal
    if (tree1 == NULL || tree2 == NULL) {
        return 0;
    }

    //dies of cringe, i mean recursive checking left and right
    return (tree1->data == tree2->data) &&
           areEqual(tree1->left, tree2->left) &&
           areEqual(tree1->right, tree2->right);
}

int main() {
    tptr root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);

    tptr root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3); //7
    root2->left->left = createNode(4);

    if (areEqual(root1, root2)) {
        printf("The trees are equal.\n");
    } else {
        printf("The trees are not equal.\n");
    }

    return 0;
}
