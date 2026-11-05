#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *next; 
    struct node *prev;
} node;

node *addAtStart(int data, node *head)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;

    if(head == NULL)
    {
        head = temp;
        return head;
    }
    else{
        temp->next = head;
        head->prev = temp;
        head = temp;
        return head;
    }
}


node *createLinkedList(int limit,node *head)
{
    if(limit == 0)
    {
        printf("Enter limit greater than 0.\n");
        return NULL;
    }
    for(int i = limit;i>0;i--)
    {  
        head = addAtStart(i,head);
    }
    printf("Doubly Linked List created Successfully.\n");
    return head;
}

node *addAtEnd(int data, node *head)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return head;
    } else {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        return head;
    }
}

node *addAtMiddle(int data, int value, node *head)
{
    if (head == NULL) {
        printf("The Linked List is empty.\n");
        return NULL;
    }

    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;

    node *temp = head;
    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with given data %d is not found.\n", value);
        free(newNode);
        return NULL;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    if (newNode->next != NULL)
    {
        newNode->next->prev = newNode;
    }

    printf("Node is added Successfully.\n");
    return head;
}   

void display(node *head)
{
    while(head != NULL)
    {
        printf("%d<-->", head->data);
        head = head->next;
    }
    printf("\n");
}


void Destroy(node *head) 
{
    if (head == NULL) 
    {
        return;
    }
    
    Destroy(head->next); 
    free(head); 
}

node *DeleteAtBegin(node *head)
{
    if(head == NULL)
    {
        printf("List is Empty.\n");
        return NULL;
    }
    if(head->next == NULL)
    {
        free(head);
        printf("Node is deleted successfully.\n");  
        return NULL; 
    }

    node *temp = head;
    head = temp->next;
    head->prev = NULL;
    free(temp);
    printf("Node is deleted successfully.\n");  

    return head;
}

node *DeleteAtEnd(node *head)
{
    if(head == NULL)
    {
        printf("List is Empty.\n");
        return NULL;
    }
    if(head->next == NULL)
    {
        free(head);
        printf("Node is deleted successfully.\n");  
        return NULL; 
    }
    node *temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL; 
    printf("Node is deleted successfully.\n");  
    return head;
}


node *DeleteAtMiddle(node *head,int data)
{
    if(head == NULL)
    {
        printf("List is Empty.\n");
        return NULL;
    }
    if(head->data == data)
    {
        free(head);
        printf("Node deleted Successfully.\n");
        return NULL;
    }

    node *temp = head;

    while(temp->next != NULL && temp->next->data != data)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Node with given data %d is not found.\n", data);
        return NULL;
    }
    
    node *newnode = temp->next;      
    temp->next = newnode->next;       
    free(newnode);
    printf("Node is deleted successfully.\n");  


    return head;
}