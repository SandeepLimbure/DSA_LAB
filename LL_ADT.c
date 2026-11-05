#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *next; 
} node;

node *insertAtBegin(int data, node *head)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
        return head;
    }
    else{
        temp->next = head;
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
        head = insertAtBegin(i,head);
    }
    printf("Singly Linked List created Successfully.\n");
    return head;
}

node *insertAtEnd(int data, node *head)
{
    node *new = (node *)malloc(sizeof(node));

    new->data = data;
    new->next = NULL;

    if(head == NULL)
    {
        head = new;
        return head;
    }else{
        node *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        return head;
    }
}

node *insertAfterData(int data, int value, node *head)
{
    if(head == NULL)
    {
        printf("The Linked List is empty.\n");
        return NULL;
    }
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    
    if(head->data == value)
    {
        new->next  = head->next;
        head->next = new; 
        printf("Node is added Successfully.\n");
        return head;
    }
    
    node *temp = head;
    while(temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }
    
    if(temp == NULL)
    {
        printf("Node with given data %d is not found.\n", value);
        free(new);
        return NULL;
    }
    
    new->next = temp->next;
    temp->next = new;
    printf("Node is added Successfully.\n");
    return head;
}

node *insertAtPos(int data, int pos, node *head)
{
    if(head == NULL)
    {
        printf("The List is Empty.\n");
        return NULL;
    }

    int count = 1;
    node *new = (node *)malloc(sizeof(node));
    new->data = data;

    if(count == pos)
    {
        new->next = head;
        head = new;
        return head;
    }

    node *temp = head;

    while(temp != NULL)
    {
        if(count == pos-1)
        {
            new->next = temp->next;
            temp->next = new;
            printf("Node added at pos %d successfully.\n", pos);
            return head;
        }
        count++;
        temp = temp->next;
    }
    
    printf("Position is out of bound.\n");
    return head;
}

void count(node *head)
{
    int count = 0;

    if(head == NULL)
    {
        printf("The Linked List is Empty.\n");
        return;
    }

    node *temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    
    printf("The number of nodes in Linked List are %d\n", count);
}

void search(int data, node *head)
{
    if(head == NULL)
    {
        printf("Linked List is Empty.\n");
        return;
    }
    
    int count = 0, found = 0;
    node *temp = head;
    
    while(temp != NULL)
    {
        count++;
        if(temp->data == data)
        {
            found = 1;
            printf("The node with data %d is found at %d in the Linked List.\n", data, count);
            return;
        }
        temp = temp->next;
    }
    
    if(!found)
    {
        printf("The node with data %d is not found in the Linked List.\n", data);
    }
}

void display(node *head)
{
    while(head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("\n");
}

void reverseDisplay(node *head)
{
    if(head == NULL)
    {  
        return;
    }
    
    reverseDisplay(head->next);
    printf("%d->", head->data);
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

node *DeleteAtPos(node *head, int pos)
{
    if(head == NULL)
    {
        printf("Linked List is Empty.\n");
        return NULL;
    }

    if(pos == 1)
    {
        node *temp = head;
        head = head->next;
        free(temp);
        printf("Node at pos %d is deleted successfully.\n",pos);  
        return head;
    }

    node *temp = head;

    for(int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL)
    {
        printf("Position is out of bounds.\n");
        return head;
    }

    node *newnode = temp->next;      
    temp->next = newnode->next;       
    free(newnode);   
    printf("Node at pos %d is deleted successfully.\n",pos);                 

    return head;
}

node *DeleteAfterData(node *head,int data)
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

    while(temp != NULL && temp->data != data)
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