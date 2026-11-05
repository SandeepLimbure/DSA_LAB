#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    int height;
}tree;

tree* createNode(int data)
{
    tree *newNode = (tree *)malloc(sizeof(tree));
    if(newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;  

    printf("Node added Successfully\n");

    return newNode;
}

int height(tree *n)
{
    if(n == NULL)
    {
        return 0;  
    }
    return n->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getBalance(tree *n)
{
    if(n == NULL)
    {
        return 0;
    }
    return height(n->left) - height(n->right);
}

tree *rightRotate(tree *y)
{
    tree *x = y->left;
    tree *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

tree *leftRotate(tree *y)  
{
    tree *x = y->right;
    tree *T2 = x->left;

    x->left = y;
    y->right = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

tree* insertNode(tree *root, int data)
{
    if(root == NULL)
    {
        return createNode(data);
    }

    if(root->data == data)
    {
        printf("Duplicates not allowed.\n");
        return root;
    }

    if(data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && data < root->left->data)
    {
        return rightRotate(root);
    }

    if (balance < -1 && data > root->right->data)
    {
        return leftRotate(root);
    }

    if (balance > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

tree *minValueNode(tree *node)
{
    tree *current = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

tree* deleteNode(tree *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            tree *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            free(temp);
        }
        else
        {
            tree *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(tree *root)
{
    if(root == NULL) 
    {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(tree *root)
{
    if(root == NULL) 
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

void InOrder(tree *root)
{
    if(root == NULL) 
    {
        return;
    }
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

int GetHeight(tree *root)
{
    if(root == NULL) 
    {
        return 0;
    }

    int leftHeight = GetHeight(root->left);
    int rightHeight = GetHeight(root->right);

    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

void PrintCurrentLevel(tree *root, int level)
{
    if(root == NULL) return;
    if(level == 1)
    {
        printf("%d ", root->data);
        return;
    }
    PrintCurrentLevel(root->left, level - 1);
    PrintCurrentLevel(root->right, level - 1);
}

void levelOrderTraversal(tree *root)
{
    int h = GetHeight(root);
    for(int i = 1; i <= h; i++)
    {
        PrintCurrentLevel(root, i);
    }
}

void freeTree(tree *root)  
{
    if(root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}   