#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BinarySearch(int arr[],int n,int target)
{
    int low = 0;
    int high = n-1;

    while(low <= high)
    {
        int mid = (low+high)/2;

        if(arr[mid] == target)
        {
            return mid;
        }
        else if(target > arr[mid])
        {
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int BinarySearchRe(int arr[],int n,int target,int low,int high)
{
    if(low > high)
    {
        return -1;
    }
    int mid = (low+high)/2;
    if(arr[mid] == target)
    {
        return mid;
    }
    else if(arr[mid] < target)
    {
        return BinarySearchRe(arr,n,target,mid+1,high);
    }
    else{
        return BinarySearchRe(arr,n,target,low,mid - 1);
    }
}

int main(void)
{
    int n,choice,target,res;
    printf("Enter the size of array : ");
    scanf("%d",&n);

    int *arr = (int *)malloc(n*sizeof(int));

    if(arr == NULL)
    {
        printf("Memory Allocation Failed.\n");
        return 0;
    }

    memset(arr,0,n);

    printf("Enter the array elements in ascending sorted order : \n");
    for(int i = 0;i<n;i++)
    {
        printf("Enter arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }

    do{
        printf("----------------------MENU--------------------------\n");
        printf("1.Binary Search Iterative.\n");
        printf("2.Binary Search Recursive.\n");
        printf("3.Free Memory\n");
        printf("----------------------------------------------------\n");

        printf("Enter the choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 :
                printf("Enter the target : ");
                scanf("%d",&target);
                res = BinarySearch(arr,n,target);
                if(res == -1)
                {
                    printf("The target element %d is not found in the array\n",target);
                } 
                else{
                    printf("The target element %d is found at index %d. int the array.\n",target,res);
                }
                break;
            case 2 :
                printf("Enter the target : ");
                scanf("%d",&target);
                res = BinarySearch(arr,n,target);
                if(res == -1)
                {
                    printf("The target element %d is not found in the array\n",target);
                } 
                else{
                    printf("The target element %d is found at index %d. int the array.\n",target,res);
                }
                break;
            case 3 :
                free(arr);
                return 0;
        }
    }while(choice != 0);

    return 0;

}