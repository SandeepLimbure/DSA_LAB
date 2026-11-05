#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int size;
    int front;
    int rear;
    int *array;
}c_queue;



c_queue *createQueue(c_queue *q)
{
    q = (c_queue *)malloc(sizeof(c_queue));
    printf("Enter the size of queue : ");
    scanf("%d",&q->size);

    q->array = (int *)malloc(q->size*sizeof(int));

    if(q->array == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    q->front = -1;
    q->rear = -1;

    printf("Queue created successfully.\n");
    return q;
}

int isFull(c_queue *q)
{
    if(q->front == 0 && q->rear == q->size-1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(c_queue *q)
{
    if(q->front == -1)
    {
        return 1;
    }
    return 0;
}

void enqueue(int data,c_queue *q)
{
    if(isFull(q))
    {
        printf("Queue is Full.\n");
        return;
    }
    if(q->front == -1)
    {
        q->front = 0;
    }
    if(q->rear == q->size-1)
    {
        q->rear = 0;
    }
    else{
        q->rear = q->rear+1;
    }
    q->array[q->rear] = data;
    printf("Data added to queue successfully.\n");
}

void dequeue(c_queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty.\n");
        return;
    }
    int data = q->array[q->front];
    if(q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else if(q->front == q->size-1)
    {
        q->front = 0;
    }
    else{
        q->front = q->front+1;
    }
    printf("Data deleted from queue successfully.\n");
}

void peek(c_queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty.\n");
        return;
    } 
    printf("peek element of queue is %d.\n",q->array[q->front]);
}

void display(c_queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty.\n");
        return;
    }

    printf("Queue elements : \n");
    int i = q->front;
    

    
}

void getFront(c_queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty.\n");
        return;
    }

    printf("Front value is %d.\n",q->front);
}

void getRear(c_queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty.\n");
        return;
    }

    printf("Rear value is %d.\n",q->rear);
}

void freeArray(c_queue *q)
{
    if(q->array != NULL)
    {
        free(q->array);
        q->array = NULL;
    }
    printf("Memory freed Successfully.\n");
}

