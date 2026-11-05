#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

typedef struct Node {
    int data;
    int color;
    struct Node *left, *right;
} Node;

static int isRed(Node *node)
{
    if (node == NULL)
        return BLACK;
    return node->color == RED;
}

static Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED;
    newNode->left = newNode->right = NULL;
    return newNode;
}

static Node *minNode(Node *h)
{
    while (h->left != NULL)
        h = h->left;
    return h;
}

static Node *rotateLeft(Node *h)
{
    Node *x = h->right;
    h->right = x->left;
    x->left = h;
    x->color = h->color;
    h->color = RED;
    return x;
}

static Node *rotateRight(Node *h)
{
    Node *x = h->left;
    h->left = x->right;
    x->right = h;
    x->color = h->color;
    h->color = RED;
    return x;
}

static void flipColors(Node *h)
{
    h->color = !h->color;
    if (h->left)
        h->left->color = !h->left->color;
    if (h->right)
        h->right->color = !h->right->color;
}

static Node *fixUp(Node *h)
{
    if (isRed(h->right) && !isRed(h->left))
        h = rotateLeft(h);
    if (isRed(h->left) && isRed(h->left->left))
        h = rotateRight(h);
    if (isRed(h->left) && isRed(h->right))
        flipColors(h);
    return h;
}

Node *search(Node *root, int data)
{
    while (root != NULL)
    {
        if (data < root->data)
            root = root->left;
        else if (data > root->data)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

static Node *insert(Node *h, int data)
{
    if (h == NULL)
        return createNode(data);

    if (data < h->data)
        h->left = insert(h->left, data);
    else if (data > h->data)
        h->right = insert(h->right, data);
    else
        return h;

    return fixUp(h);
}

Node *insertRoot(Node *root, int data)
{
    root = insert(root, data);
    root->color = BLACK;
    return root;
}

static Node *moveRedLeft(Node *h)
{
    flipColors(h);
    if (h->right != NULL && isRed(h->right->left))
    {
        h->right = rotateRight(h->right);
        h = rotateLeft(h);
        flipColors(h);
    }
    return h;
}

static Node *moveRedRight(Node *h)
{
    flipColors(h);
    if (h->left != NULL && isRed(h->left->left))
    {
        h = rotateRight(h);
        flipColors(h);
    }
    return h;
}

static Node *deleteMin(Node *h)
{
    if (h->left == NULL)
    {
        free(h);
        return NULL;
    }
    if (!isRed(h->left) && !isRed(h->left->left))
        h = moveRedLeft(h);

    h->left = deleteMin(h->left);
    return fixUp(h);
}

static Node *deleteNode(Node *h, int data)
{
    if (data < h->data)
    {
        if (h->left != NULL && !isRed(h->left) && !isRed(h->left->left))
            h = moveRedLeft(h);
        h->left = deleteNode(h->left, data);
    }
    else
    {
        if (isRed(h->left))
            h = rotateRight(h);

        if (data == h->data && h->right == NULL)
        {
            free(h);
            return NULL;
        }

        if (h->right != NULL && !isRed(h->right) && !isRed(h->right->left))
            h = moveRedRight(h);

        if (data == h->data)
        {
            Node *successor = minNode(h->right);
            h->data = successor->data;
            h->right = deleteMin(h->right);
        }
        else
        {
            h->right = deleteNode(h->right, data);
        }
    }
    return fixUp(h);
}

Node *deleteRoot(Node *root, int data)
{
    if (root == NULL)
        return NULL;

    if (!isRed(root->left) && !isRed(root->right))
        root->color = RED;

    root = deleteNode(root, data);

    if (root != NULL)
        root->color = BLACK;

    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d(%c) ", root->data, root->color == RED ? 'R' : 'B');
    inorder(root->right);
}

void preorder(Node *root)
{
    if(root == NULL)
    {
        return;
    }

    printf("%d(%c) ", root->data, root->color == RED ? 'R' : 'B');
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d(%c) ", root->data, root->color == RED ? 'R' : 'B');
}

int height(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return (left > right) ? (left+1) : (right+1);
}

void printLevelOrder(Node *root,int level)
{
    if(root == NULL)
    {
        return;
    }
    if(level == 1)
    {
        printf("%d(%c) ", root->data, root->color == RED ? 'R' : 'B');
        return;
    }
    else{
        printLevelOrder(root->left,level-1);
        printLevelOrder(root->right,level-1);
    }

}

void LevelOrder(Node *root)
{
    int h = height(root);

    for(int i = 1;i<=h;i++)
    {
        printLevelOrder(root,i);
    }

}

void freeTree(Node *root)
{
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}