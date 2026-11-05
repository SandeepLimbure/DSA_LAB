#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int* hashInit()
{
    if(SIZE < 0)
    {
        printf("SIZE cannot be less than zero.\n");
        return NULL;
    }

    int *arr = (int *)malloc(SIZE*sizeof(int));
    if(arr == NULL)
    {
        printf("Memory initialization failed.\n");
        return NULL;
    }

    for(int i = 0;i<SIZE;i++)
    {
        arr[i] = -1;
    }
    printf("Hash table initialized successfully.\n");

    return arr;
}

int hashCode(int key) {
        return key % SIZE;
}

void insert(int *hashTable,int value)
{
    int key = hashCode(value);
    int index = key;

    while(hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;
        if(index == key)
        {
            printf("Hash Table is full.\n");
            return;
        }
    }
    hashTable[index] = value;
    printf("Data added successfully.\n");

}

int search(int *hashTable,int value)
{
    int index = hashCode(value);
    int counter = 0;

    while(hashTable[index] != -1)
    {
        if(++counter == SIZE)
        {
            return -1;
        }
        if(hashTable[index] == value)
        {
           return 1; 
        }

        index = (index + 1)%SIZE;
    }
    return -1;
}

void display(int *hashTable)
{
    printf("Hash Table Elements : \n");
    for(int i = 0;i<SIZE;i++)
    {
        printf("Index %d : %d\n",i,hashTable[i]);
    }
}

void freeArray(int *hashTable)
{
    if(hashTable != NULL)
    {
        free(hashTable);
        hashTable = NULL;
    }
    printf("Memory freeded successfully.\n");
}