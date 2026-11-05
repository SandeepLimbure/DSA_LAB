#include "mergeSort.h"

int* createArray(int size)
{

    int *arr = (int *)malloc(size*sizeof(int));

    printf("Enter array elements : \n");
    for(int i = 0;i<size;i++)
    {
        printf("Enter arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }
    printf("\n");

    return arr;
}

int* mergeTwoArrays(int *arr1,int *arr2,int n1,int n2)
{
    int k = 0;
    int *res = (int *)malloc((n1+n2)*sizeof(int));
    for(int i = 0;i<n1;i++)
    {
        res[k++] = arr1[i];
    }
    for(int j = 0;j<n2;j++)
    {
        res[k++] = arr2[j];
    }
    return res;
}

void mergeSort(int *arr,int low,int high)
{
    if(low >= high)
    {
        return;
    }
    int mid = (low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high); 
}

void merge(int *arr,int low,int mid,int high)
{
    int n1 = mid-low+1;
    int n2 = high - mid;

    int arr1[n1],arr2[n2];

    for(int i = 0;i<n1;i++)
    {
        arr1[i] = arr[low+i];
    }
    for(int i = 0;i<n2;i++)
    {
        arr2[i] = arr[mid+1+i];
    }

    int i = 0,j = 0,k = low;

    while(i < n1 && j < n2)
    {
        if(arr1[i] <= arr2[j])
        {
            arr[k++] = arr1[i++];
        }
        else
        {
            arr[k++] = arr2[j++];
        }
    }
    while(i < n1)
    {
        arr[k++] = arr1[i++];
    }
    while(j < n2)
    {
        arr[k++] = arr2[j++];
    }
}

void display(int *arr,int n)
{
    if(n == 0)
    {
        printf("Array is Element.\n");
        return;
    }
    printf("Array Elements : \n");
    for(int i = 0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void freeArray(int *arr1,int *arr2,int *arr3)
{
    if(arr1 != NULL && arr2 != NULL && arr3 != NULL)
    {
        free(arr1);
        free(arr2);
        free(arr3);
        arr1 = NULL;
        arr2 = NULL;
        arr3 = NULL;
    }
    printf("Memory freed Successfully.\n");
}