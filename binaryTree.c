/*
1. create a binary tree.
2. traversal
- preorder (stack)
- post order (recursion)
- inorder (recursion)
3. find an element in the binary tree
4. print leaf nodes
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *lc, *rc;
} *root = NULL;

struct Node *BTcreation()
{
    int element;
    printf("Enter element (or -1 for no node): ");
    scanf("%d", &element);

    if (element == -1)
    {
        return NULL;
    }

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = element;

    printf("Enter left child of %d:\n", element);
    temp->lc = BTcreation();

    printf("Enter right child of %d:\n", element);
    temp->rc = BTcreation();

    return temp;
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->lc);
        preorder(root->rc);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->lc);
        postorder(root->rc);
        printf("%d ", root->data);
    }
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->lc);
        printf("%d ", root->data);
        inorder(root->rc);
    }
}

int findElement(struct Node *root, int key)
{
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    return findElement(root->lc, key) || findElement(root->rc, key);
}

void printLeafNodes(struct Node *root)
{
    if (root == NULL)
        return;
    if (root->lc == NULL && root->rc == NULL)
    {
        printf("%d ", root->data);
        return;
    }
    printLeafNodes(root->lc);
    printLeafNodes(root->rc);
}

int main()
{
    int choice, key;

    do
    {
        printf("Menu: \n");
        printf("1. Create a Binary Tree \n");
        printf("2. Preorder Traversal \n");
        printf("3. Postorder Traversal \n");
        printf("4. Inorder Traversal \n");
        printf("5. Find an element \n");
        printf("6. Print Leaf Nodes \n");
        printf("7. Exit \n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            root = BTcreation();
            break;
        case 2:
            preorder(root);
            printf("\n");
            break;
        case 3:
            postorder(root);
            printf("\n");
            break;
        case 4:
            inorder(root);
            printf("\n");
            break;
        case 5:
            printf("Enter the element to find: ");
            scanf("%d", &key);
            if (findElement(root, key))
                printf("Element %d found in the tree.\n", key);
            else
                printf("Element %d not found in the tree.\n", key);
            break;
        case 6:
            printLeafNodes(root);
            printf("\n");
            break;
        case 7:
            printf("Exiting...\n");
            break;
        }
    } while (choice != 7);
}
