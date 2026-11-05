#include "sorting.h"

void display(int *arr,int n)
{
    if(n == 0)
    {
        printf("Array is not created.\n");
        return;
    }

    printf("Array Elements : \n");
    for(int i = 0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void bubbleSort(int *arr,int n)
{
    if(n == 0)
    {
        printf("Array is not created.\n");
        return;
    }

    for(int i = 0;i<n-1;i++)
    {
        int counter = 0;
        for(int j =0 ;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                counter++;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(counter == 0) break;
    }
    printf("Bubble Sort : \n");
    display(arr,n);
}

void SelectionSort(int *arr,int n)
{
    if(n == 0)
    {
        printf("Array is not created.\n");
        return;
    }

    int minIndex = 0;

    for(int i = 0;i<n-1;i++)
    {
        minIndex = i;
        for(int j = i+1;j<n;j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if(minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    printf("Selection Sort : \n");
    display(arr,n);
}

void InsertionSort(int arr[],int n)
{
    if(n == 0)
    {
        printf("Array is not created.\n");
        return;
    }

    int i,j,k;
    for(i = 0;i<n;i++)
    {
        k = arr[i];
        for(j = i-1;j >= 0 && k < arr[j];j--)
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = k;
    }

    printf("Insertion Sort : \n");
    display(arr,n);

}

int InputArray(int **arr)
{
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);

    *arr = (int *)malloc((n)*sizeof(int));

    if(*arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return -1;
    }

    memset(*arr,0,n);

    printf("Enter Array Elements : \n");
    for(int i = 0;i<n;i++)
    {
       printf("Enter arr[%d] : ",i);
       scanf("%d",&(*arr)[i]); 
    }
    return n;
}

void freeArray(int *arr)
{
    if(arr != NULL)
    {
        free(arr);
        arr = NULL;
    }
    printf("Memory freed successfully.\n");
}