#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
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

    printf("Node added Successfully\n");

    return newNode;
}

tree* insertChild(tree *root,int data)
{
    if(root == NULL)
    {
        return createNode(data);
    }

    char choice;
    printf("Insert left(l) or right (r) : ");
    scanf(" %c",&choice);

    if(choice == 'l' || choice == 'L')
    {
        root->left = insertChild(root->left,data);
    }
    else if(choice == 'r' || choice == 'R')
    {
        root->right = insertChild(root->right,data);
    }
    else{
        printf("Invalid choice.\n");
    }

    return root;
}

void preOrder(tree *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d ",root->data);
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
    printf("%d ",root->data);
}

void InOrder(tree *root)
{
    if(root == NULL)
    {
        return;
    }
    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->right);
}

int height(tree *root)
{
    if(root == NULL)
    {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight) ? leftHeight+1 : rightHeight+1;

}

void PrintCurrentLevel(tree *root,int level)
{
    if(root == NULL)
    {
        return;
    }

    if(level == 1)
    {
        printf("%d ",root->data);
        return;
    }
    else 
    {
        PrintCurrentLevel(root->left,level-1);
        PrintCurrentLevel(root->right,level-1);
    }
}

void levelOrderTraversal(tree *root)
{
    int h = height(root);

    for(int i = 1;i<=h;i++)
    {
       PrintCurrentLevel(root,i); 
    }
} 

void freeTree(tree *root, int height)
{
    if(root == NULL)
    {
        return;
    }
    freeTree(root->left,height-1);
    freeTree(root->right,height-1);
    if(root != NULL)
    {
        free(root);
    }
}