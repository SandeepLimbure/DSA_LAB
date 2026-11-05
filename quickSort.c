#include "quickSort.h"

int* createArray(int size)
{
    int *arr = (int *)malloc(size*sizeof(int));

    if(arr == NULL)
    {
        printf("Memory not Alloted.\n");
        return NULL;
    }

    printf("Enter array elements : \n");
    for(int i = 0;i<size;i++)
    {
        printf("Enter arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }
    printf("\n");


    return arr;
}

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr,int low,int high)
{
    int pivot = arr[low];
    int i = low+1;
    int j = high;

    while(i <= j)
    {
        while(arr[i] < pivot && i < high)
        {
            i++;
        }
        while(arr[j] > pivot )
        {
            j--;
        }
        if(i<j)
        {
            swap(&arr[i],&arr[j]);
            i++;
            j--;
        }
        else{
            i++;
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
}

void quickSort(int *arr,int low,int high)
{
    if(low >= high)
    {
        return;
    }
    int pivloc = partition(arr,low,high);
    quickSort(arr,low,pivloc-1);
    quickSort(arr,pivloc+1,high);

}

void display(int *arr,int n)
{
    if(n == 0)
    {
        printf("Array is Empty.\n");
        return;
    }

    printf("Array Elements : \n");
    for(int i = 0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void freeArray(int *arr)
{
    if(arr != NULL)
    {
        free(arr);
        arr = NULL;
    }
    printf("Memory freed Successfully.\n");
}
