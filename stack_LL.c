#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}stack;


int isEmpty(stack *top)
{
    if(top == NULL)
    {
        return 1;
    }
    return 0;
}

void* createNode(int data)
{
    stack *temp = (stack *)malloc(sizeof(stack));
    if(temp == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;

    return temp;
}

void push(stack** top,int data)
{
    stack *temp = createNode(data);
    if(*top == NULL)
    {
        *top = temp;
        printf("Node added successfully.\n");
        return;
    }
    else{
        temp->next = *top;
        *top = temp;
        printf("Node added successfully.\n");
        return;
    }
}

int pop(stack** top)
{
    int data = 0;
    if(isEmpty(*top))
    {
        return -1;
    }

    if((*top)->next == NULL)
    {
        data = (*top)->data;
        free(*top);
        *top = NULL; 
        return data;
    }

    stack *temp = *top;
    data = temp->data;
    *top = temp->next;
    free(temp); 

    return data;

}

void peek(stack *top)
{
    if(isEmpty(top))
    {
        printf("List is Empty.\n");
        return;
    }

    printf("Top Element of the stack is %d\n",top->data);

}

void display(stack *top)
{
    if(isEmpty(top))
    {
        printf("List is Empty.\n");
        return;
    }

    printf("Stack Elements are : ");
    while(top != NULL)
    {
        printf("%d ",top->data);
        top = top->next;
    }
    printf("\n");
}

void Destroy(stack *top) 
{
    if (top == NULL) 
    {
        return;
    }
    
    Destroy(top->next); 
    free(top); 
}

