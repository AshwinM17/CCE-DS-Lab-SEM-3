#include <stdio.h>
#include <stdlib.h>

// Define a TreeNode structure and use a typedef for convenience
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insertNode(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

TreeNode* findMinNode(TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL)
    {
        return NULL;
    }
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else // root is found
    {
        if (root->left == NULL)
        {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        TreeNode* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Modify the Search function to include position tracking
int SearchBST(TreeNode *root, int key, int *position) {
    if (root == NULL) {
        return 0; // Not found
    }

    int leftCount = SearchBST(root->left, key, position);
    if (leftCount) {
        return leftCount; // If found in left subtree
    }

    (*position)++; // Increment position for the current node
    if (root->data == key) {
        return *position; // Key found, return position
    }

    return SearchBST(root->right, key, position); // Search in right subtree
}

int main() {
    TreeNode* root = NULL;
    int choice, value;

    printf("Elements are added to the tree in an inorder sequence.");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a value\n");
        printf("2. Delete a value\n");
        printf("3. Search a value\n");
        printf("4. Display the Tree (inorder traversal)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;

            case 2:
                printf("Enter a value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 3: {
                printf("Enter the element to search: ");
                scanf("%d", &value);
                int position = 0;
                int foundPosition = SearchBST(root, value, &position);
                if (foundPosition) {
                    printf("Key found at position: %d\n", foundPosition);
                } else {
                    printf("Key not found\n");
                }
                break;
            }

            case 4:
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 5:
                free(root); // Release memory
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
