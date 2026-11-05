#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct Queue{
    node *front;
    node *rear;
}queue;


int isEmpty(queue *q)
{
    if(q->front == NULL || q->front >= q->rear)
    {
        return 1;
    }
    return 0;
}

void* createQueue()
{
    queue *temp = (queue *)malloc(sizeof(queue));
    if(temp == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    temp->rear = NULL;
    temp->front = NULL;

    printf("Queue initialized successfully.\n");

    return temp;
}

void* createNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    if(temp == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;

    return temp;
}

void enqueue(queue* q,int data)
{
    if(q == NULL)
    {
       printf("Queue is not initialized.\n");
       return; 
    }
    node *newNode = createNode(data);

    if(q->rear == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
        printf("Node added Successfully.\n");
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
    printf("Node added Successfully.\n");
    return;
}

int dequeue(queue* q)
{
    int data = 0;
    if(isEmpty(q))
    {
        return -1;
    }

    node *temp = q->front;

    data = q->front->data;
    
    q->front = q->front->next;

    if(q->front == NULL)
    {
        q->rear = NULL;
    }

    free(temp);
    return data;
}

int getFront(queue *q)
{
    if(q->front == NULL)
    {
        return -1;
    }

    return (q->front->data);
}

int getRear(queue *q)
{
    if(q->rear == NULL)
    {
        return -1;
    }

    return (q->rear->data);
}

void display(queue *q)
{
    if(isEmpty(q))
    {
        printf("List is Empty.\n");
        return;
    }

    printf("queue Elements are : ");
    node *temp = q->front;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Destroy(queue *q) 
{
    while(!isEmpty(q))
    {
        dequeue(q);
    }
}

