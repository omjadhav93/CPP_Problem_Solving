#include <stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *arr, int n){
    int i,j;
    for (i = 0; i < n; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if(arr[j] < arr[i]) swap(&arr[i],&arr[j]);
        }
    }
    
}

void bubbleSort(int *arr,int n){
    int i,j;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1]) swap(&arr[j],&arr[j+1]);
        }
        
    }
    
}

void printArray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){

    int arr[20],arrCopy[20];
    int n,i;

    printf("Enter No. of Elements(<20) : ");
    scanf("%d",&n);

    printf("Enter %d Elements : ",n);
    for (i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
        arrCopy[i] = arr[i];
    }

    selectionSort(arr,n);
    printf("Selection Sort : ");
    printArray(arr,n);

    bubbleSort(arrCopy,n);
    printf("Bubble Sort : ");
    printArray(arrCopy,n);
    

    return 0;
}