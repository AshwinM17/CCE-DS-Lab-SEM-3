#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

typedef struct TNode *Tptr;
typedef struct TNode
{
    int data;
    Tptr leftchild;
    Tptr rightchild;
}TNode;

Tptr root;

int top = -1;
Tptr stack[MAX];

//Create nodes in the tree
Tptr createNode(int val)
{
    Tptr temp =(Tptr)malloc(sizeof(TNode));
    temp->data = val;
    temp->leftchild = temp->rightchild = NULL;
    return temp;
}

//create the binary tree
void createTree(int N)
{
    int cData,dIndex;
    char dir[50];
    Tptr previous = NULL,current;

    for(int i=0;i<N;i++)
    {
        printf("Enter data for node %d ",i);
        scanf("%d",&cData);
        Tptr temp = createNode(cData);
        //assign root node
        if(!root)
        {
            root = temp;
        }

        else
        {
            printf("Enter direction ");
            scanf("%s",dir);
            current = root;
            previous = NULL;
            for(dIndex=0;dir[dIndex]!='\0' && current!=NULL;dIndex++)
            {
                previous = current;
                if(dir[dIndex]=='L'||dir[dIndex]=='l')
                {
                    current = current->leftchild;
                }
                else
                {
                    current = current->rightchild;
                }
            }
            if(current!=NULL || dir[dIndex]!='\0')
            {
                printf("Invalid");
                free(temp);
                return;
            }
            if(dir[dIndex-1]=='L'||dir[dIndex-1]=='l')
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

bool isFull()
{
    return top==MAX;
}

bool isEmpty()
{
    return top==-1;
}

//Push nodes onto the stack
void Push(Tptr node)
{
    if(!isFull())
    {
        stack[++top] = node;
    }
}

//Pop node from the  stack
Tptr Pop()
{
    Tptr ret = NULL;
    if(!isEmpty())
    {
        ret = stack[top--];
    }
    return ret;
}

Tptr peek()
{
    return stack[top];
}
//print node elements in inorder
void IterativeInorder(Tptr node)
{
    while(true)
    {
        for(; node;node = node->leftchild) //push all left child
        {
            Push(node);
        }
        node = Pop();
        if(node == NULL)//i.e stack is empty
        {
            break;
        }
        printf("%d ",node->data);
        node = node->rightchild;
    }

}

//print node elements in preorder
void IterativePreorder(Tptr node)
{
    for(;;)
    {
        for(; node;node = node->leftchild)
        {
            Push(node);
            printf("%d ",node->data);
        }
        node = Pop();
        if(node == NULL)
        {
            break;
        }
        node = node->rightchild;
    }
}

//print node elements in postorder
void IterativePostorder(Tptr node) //printing after pooping when right child doesnt exist
{
    while (true)
    {
        if(node)// push all leftchild
        {
            Push(node);
            node = node->leftchild;
        }
        else
        {
            if(!peek()) //stack is empty
            {
                break;
            }

            Tptr temp = peek()->rightchild;


            if(temp==NULL)//i.e doesn't exist
            {
                temp = Pop();
                printf("%d",temp->data);
                while(!isEmpty() && temp==peek()->rightchild)//only when temp is the right child of the top
                {
                    temp = Pop();//extra pop if it is the right child,otherwise(in next iteration node==NULL and temp!=NULL)
                    printf("%d ",temp->data);
                }
            }
            else //i.e if right child of the top of stack exists push it and it's left children to stack
            {
                node = temp;
            }
        }
    }
}

//Return the parent of a given node
Tptr ParentNode(Tptr node, int target) {
    if (!node) {
        return NULL;
    }

    if ((node->leftchild && node->leftchild->data == target) || (node->rightchild && node->rightchild->data == target)) {
        return node;
    }

    Tptr left = ParentNode(node->leftchild, target);
    if (left != NULL) {
        return left;
    }

    return ParentNode(node->rightchild, target);
}

void countnodes(TNode* root,int *count)
{
    if(root)
    {
        (*count)++;
        countnodes(root->leftchild,count);
        countnodes(root->rightchild,count);
    }
}
//Find the depth of a given tree
int maxDepth(Tptr root) {
    if (root == NULL) {
        return 0;
    } else {
        // Compute the depth of each subtree
        int leftDepth = maxDepth(root->leftchild);
        int rightDepth = maxDepth(root->rightchild);

        // Return the greater depth of the two subtrees plus 1 for the current node
        return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
    }
}


//print all the ancestors of a node
int printAncestors(Tptr root, int target) {
    // Base case: If the root is NULL, there are no ancestors to print.
    if (root == NULL) {
        return 0;
    }

    // If the target value is found, return 1 to indicate the presence of the target.
    if (root->data == target) {
        return 1;
    }

    // If the target value is found in either the left or right subtree,
    // print the current node and return 1 to indicate the presence of the target.
    if (printAncestors(root->leftchild, target) || printAncestors(root->rightchild, target)) {
        printf("%d ", root->data);
        return 1;
    }

    // If the target value is not found in this subtree, return 0.
    return 0;
}
//count the number of leaf nodes in a tree
int countLeafNodes(Tptr root) {
    if (root == NULL) {
        return 0;
    }

    if (root->leftchild == NULL && root->rightchild == NULL) {
        // If both left and right children are NULL, the node is a leaf node.
        return 1;
    } else {
        // Recursively count leaf nodes in the left and right subtrees.
        int leftLeafCount = countLeafNodes(root->leftchild);
        int rightLeafCount = countLeafNodes(root->rightchild);
        return leftLeafCount + rightLeafCount;
    }
}
void cntleaf(Tptr root,int *count)
{
    if(root && (root->leftchild)==NULL && (root->rightchild)==NULL)
    {
        (*count)++;
    }
    if(root)
    {
        cntleaf(root->leftchild,count);
        cntleaf(root->rightchild,count);
    }
    if(!root)
    {
        return;
    }
}
int main()
{
    int N;
    root = NULL;
    int choice, target;

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
                int count=0;
                countnodes(root,&count);
                printf("Number of nodes %d\n",count);

                break;

            case 2:
                // Inorder Traversal
                printf("Inorder Traversal: ");
                IterativeInorder(root);

                break;

            case 3:
                // Preorder Traversal
                printf("Preorder Traversal: ");
                IterativePreorder(root);
                break;

            case 4:
                // Postorder Traversal
                printf("Postorder Traversal: ");
                IterativePostorder(root);
                break;

            case 5:
                // Find Parent of a Node
                printf("Enter the value of the target node: ");
                scanf("%d", &target);
                Tptr parent=ParentNode(root,target);
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
                printf("Enter the value of the target node: ");
                scanf("%d", &target);
                printf("Ancestors of %d: ", target);
                printAncestors(root,target);
                break;

            case 8 :
                printf("");
                // Count Leaf Node
                int lcount=0 ;
                cntleaf(root,&lcount);
                printf("aternate %d \n",lcount);
                printf("Number of leaf nodes: %d\n", countLeafNodes(root));
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
