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

    if(root->data == data)
    {
        printf("Duplicates not allowed.\n");
        return root;
    }

    if(data < root->data)
    {
        root->left = insertChild(root->left,data);
    }
    else if (data > root->data){
        root->right = insertChild(root->right,data);
    }

    return root;
}

int search(tree *root,int value,int level)
{
    if(root == NULL)
    {
        return 0;
    }

    if(root->data == value)
    {
        return level;
    }
    if(value < root->data)
    {
        return search(root->left,value,level+1);
    }
    
    return search(root->right,value,level+1);
    
}

tree* minValueNode(tree *root)
{
    tree *current = root;

    while(current != NULL && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

tree* deleteNode(tree *root,int data)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(data < root->data)
    {
        root->left = deleteNode(root->left,data);
    }
    else if(data > root->data)
    {
        root->right = deleteNode(root->right,data);
    }
    else{
        if(root->left == NULL)
        {
            tree *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            tree *temp = root->left;
            free(root);
            return temp;
        }

        tree *temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right,temp->data);

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