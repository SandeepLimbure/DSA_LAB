#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int size;
    int front;
    int rear;
    int *array;
}queue;



queue *createQueue(queue *q)
{
    q = (queue *)malloc(sizeof(queue));
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

int isFull(queue *q)
{
    if(q->rear == q->size-1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(queue *q)
{
    if(q->front == -1 || q->front >= q->rear)
    {
        return 1;
    }
    return 0;
}

void enqueue(int data,queue *q)
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
    q->array[++q->rear] = data;
    printf("Data added to queue successfully.\n");
}

void dequeue(queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty.\n");
        return;
    }
    int data = q->array[q->front++];
    printf("Data deleted from queue successfully.\n");
}

void peek(queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty.\n");
        return;
    } 
    printf("peek element of queue is %d.\n",q->array[q->front]);
}

void display(queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty.\n");
        return;
    }

    printf("Queue elements : \n");
    for(int i = q->front;i<=q->rear;i++)
    {
        printf("%d ",q->array[i]);
    }
    printf("\n");

}

void getFront(queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty.\n");
        return;
    }

    printf("Front value is %d.\n",q->front);
}

void getRear(queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty.\n");
        return;
    }

    printf("Rear value is %d.\n",q->rear);
}

void freeArray(queue *q)
{
    if(q->array != NULL)
    {
        free(q->array);
        q->array = NULL;
    }
    printf("Memory freed Successfully.\n");
}

