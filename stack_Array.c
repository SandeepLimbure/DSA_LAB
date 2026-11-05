#include "stack.h"

stack* stackInitialization(stack *stk) 
{
    stk = (stack *)malloc(sizeof(stack));
    printf("Enter the size of stack: ");
    scanf("%d", &stk->size);


    stk->stack = (char *)malloc(stk->size * sizeof(char));

    if (stk->stack == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    stk->top = -1;

    printf("Stack initialized successfully.\n");
    return stk;
}

int isFull(stack *stk)
{
    if(stk->top == stk->size-1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(stack *stk)
{
    if(stk->top == -1)
    {
        return 1;
    }
    return 0;
}

void push(stack *stk,int data)
{
    if(isFull(stk))
    {
        printf("Stack is Full.\n");
        return;
    }
    stk->stack[++(stk->top)] = data;
    printf("Data successfully pushed into the stack.\n");
}

void pop(stack *stk)
{
    if(isEmpty(stk))
    {
        printf("Stack is Empty.\n");
        return;
    }
    char data = stk->stack[(stk->top)--];
    printf("Top Element successfully popped out.\n");
}

void peek(stack *stk)
{
    if(isEmpty(stk))
    {
        printf("Stack is Empty.\n");
        return;
    }

    char data = stk->stack[stk->top];
    printf("Top element of stack is : %c\n",data); 
}

void display(stack *stk)
{
    if(isEmpty(stk))
    {
        printf("Stack is Empty.\n");
        return;
    }

    printf("Stack elements are : \n");
    for(int i = stk->top;i>=0;i--)
    {
        printf("%c->",stk->stack[i]);
    }
    printf("\n");
}

void freeArray(stack *stk)
{
    if(stk->stack != NULL)
    {
        free(stk->stack);
        stk->stack = NULL;
    }
    printf("Memory freed successfully.\n");
}