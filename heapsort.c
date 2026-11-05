#include "heapsort.h"


int* createArray(int size)
{
    int *arr = (int *)malloc(size*sizeof(int));

    if(arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    printf("Array Elements : \n");
    for(int i = 0;i<size;i++)
    {
        printf("Enter arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }

    return arr;
}

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[],int n,int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    while(left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    while(right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(&arr[largest],&arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n)
{
    for(int i = n/2 - 1;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    for(int i = n-1;i>0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}

void display(int arr[],int size)
{
    printf("array elements : \n");
    for(int i = 0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
