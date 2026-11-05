#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct node{
    int data;
    struct node *next;
}node;

node* hashInit()
{
    node* hashTable = (node *)malloc(SIZE*sizeof(node));
    if(hashTable == NULL)
    {
        printf("Memory not allocated.\n");
        return NULL;
    }

    for(int i = 0;i<SIZE;i++)
    {
        hashTable[i].data = -1;
        hashTable[i].next = NULL;
    }
    printf("Hash table initialized successfully.\n");
    return hashTable;
}

int hashCode(int key)
{
    return (key%SIZE);
}

void insert(node *hashTable,int value)
{
    int key = hashCode(value);
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;

    if(hashTable[key].next == NULL)
    {
        hashTable[key].next = newNode;
    }
    else
    {
        node *temp = hashTable[key].next;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Data added successfully to hash table.\n");

}

int search(node *hashTable,int value)
{
    int key = hashCode(value);
    node *temp = hashTable[key].next;

    while(temp != NULL)
    {
        if(temp->data == value)
        {
            return 1;
        }
        temp = temp->next;
    }
    return -1;
}

void display(node *hashTable)
{
    for(int i = 0; i < SIZE; i++)
    {
        printf("[%d] -> ", i);
        node *temp = hashTable[i].next;
        while(temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void freeArray(node* hashTable)
{
    for(int i = 0; i < SIZE; i++)
    {
        node *temp = hashTable[i].next;
        while(temp != NULL)
        {
            node *next = temp->next;
            free(temp);
            temp = next;
        }
        hashTable[i].next = NULL;
    }
    free(hashTable);
    printf("Memory freed successfully.\n");
}