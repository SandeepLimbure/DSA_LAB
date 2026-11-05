#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void LinearSearch(int arr[],int target,int n,int found)
{
    if(n == 0)
    {
        printf("Array is Empty.\n");
        return;
    }
    for(int i = 0;i<n;i++)
    {
        if(arr[i] == target)
        {
            found = 1;
            printf("The element %d is found at index %d in the array.\n",target,i);
        }
    }
    if(!found)
    {
        printf("The element %d is not found in the array.\n",target);
    }
}

void LinearSearchRe(int arr[],int target,int currentState,int n,int *found)
{
    if(currentState == n )
    {
        if(*found == 0)
        {
            printf("The element %d is not found in the array.\n",target);
        }
        return;
    }
    if(arr[currentState] == target)
    {
        *found = 1;
        printf("The element %d is found at index %d in the array.\n",target,currentState);
    }
    LinearSearchRe(arr,target,currentState+1,n,found);
}

void display(int arr[],int n)
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

void DisplayRe(int arr[],int i,int n)
{
    if(i == n)
    {
        return;
    }
    printf("%d ",arr[i]);
    DisplayRe(arr,i+1,n);
}

void ReverseDisplay(int arr[],int n)
{
    if(n == 0)
    {
        printf("Array is Empty.\n");
        return;
    }
    printf("Array Elements : \n");
    for(int i = n-1;i>=0;i--)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void ReverseDisplayRe(int arr[],int n)
{
    if(n <= 0)
    {
        return;
    }
    printf("%d ",arr[n-1]);
    ReverseDisplayRe(arr,n-1);
}

int main(void)
{
    int n,choice,target,res,found = 0;
    printf("Enter the size of array : ");
    scanf("%d",&n);

    int *arr = (int *)malloc(n*sizeof(int));

    if(arr == NULL)
    {
        printf("No Memory Allocated.\n");
        return 0;
    }

    memset(arr, 0,n);

    for(int i = 0;i<n;i++)
    {
        printf("Enter arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }

    do{
        printf("\n-------------------MENU----------------\n");
        printf("1.Linear Search Iterative.\n");
        printf("2.Linear Search Recursive.\n");
        printf("3.Display Itravtive.\n");
        printf("4.Display Recursive.\n");
        printf("5.Reverse Display Iterative.\n");
        printf("6.Reverse Display Recursive.\n");
        printf("7.Destroy Array.\n");
        printf("------------------------------------------\n");

        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
                printf("Enter the target : ");
                scanf("%d",&target);
                LinearSearch(arr,target,n,found);
                break;
            case 2:
                printf("Enter the target : ");
                scanf("%d",&target);
                LinearSearchRe(arr,target,0,n,&found);
                break;
            case 3 :
                display(arr, n);
            case 4 :
                printf("Array Elements : \n");
                DisplayRe(arr,0,n);
                break;
            case 5 :
                ReverseDisplay(arr,n);
                break;
            case 6 :
                printf("Array Elements : \n");
                ReverseDisplayRe(arr,n);
                break;
            case 7 :
                free(arr);
                return 0;
        }

    }while(choice != 0);

}