#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *next; 
} node;

node *insertAtBegin(int data, node *head)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;

    if (head == NULL)
    {
        head = new;
        head->next = head;
        return head;
    }
    else
    {
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = head;
        head = new;
        return head;
    }
}

node *createLinkedList(int limit, node *head)
{
    if (limit == 0)
    {
        printf("Enter limit greater than 0.\n");
        return NULL;
    }
    for (int i = limit; i > 0; i--)
    {
        head = insertAtBegin(i, head);
    }
    printf("Circular Linked List created Successfully.\n");
    return head;
}

node *insertAtEnd(int data, node *head)
{
    node *new = (node *)malloc(sizeof(node));

    new->data = data;
    new->next = NULL;

    if (head == NULL)
    {
        head = new;
        head->next = head;
        return head;
    }
    else
    {
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = head;
        return head;
    }
}

void display(node *head)
{
    node *temp = head;
    while (temp->next != head)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    if (temp->next == head)
    {
        printf("%d->pointing to head(%d)\n", temp->data, head->data);
    }
    printf("\n");
}

void Destroy(node *head)
{
    if (!head)
    {
        return;
    }
    node *current = head;
    do
    {
        node *next = current->next;
        free(current);
        current = next;
    } while (current != head);

    printf("Memory freed Successfully.\n");
}

node *DeleteAtBegin(node *head)
{
    if (head == NULL)
    {
        printf("List is Empty.\n");
        return NULL;
    }
    if (head->next == head)
    {
        free(head);
        printf("Node is deleted successfully.\n");
        return NULL;
    }

    node *last = head;
    while (last->next != head)
    {
        last = last->next;
    }
    node *temp = head;
    head = temp->next;
    last->next = head;
    free(temp);
    printf("Node is deleted successfully.\n");

    return head;
}

node *DeleteAtEnd(node *head)
{
    if (head == NULL)
    {
        printf("List is Empty.\n");
        return NULL;
    }
    if (head->next == head)
    {
        free(head);
        printf("Node is deleted successfully.\n");
        return NULL;
    }
    node *temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = head;
    printf("Node is deleted successfully.\n");
    return head;
}