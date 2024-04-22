#include <stdio.h>

void insertionSort(int *arr,int n){
    int i,j;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        int insert = arr[i];
        while (j >= 0 && arr[j] > insert)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = insert;
    }
}

// Quick Sort
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// int partition(int *arr,int l,int h){
//     int pivot = arr[l];
//     int i = l,j = l+1;

//     while (j <= h)
//     {
//         if(arr[j] < pivot){
//             i++;
//             swap(&arr[i],&arr[j]);
//         }
//         j++;
//     }
//     swap(&arr[l],&arr[i]);
    
//     return i;
// }

int partition(int *arr,int l,int h){
    int pi = (l+h)/2;
    int pivot = arr[pi];
    int i = l-1,j = l;

    while (j<=h)
    {
        if(j == pi)
            j++;
        
        if(arr[j] < pivot){
            i++;
            if(i == pi) i++;
            swap(&arr[i],&arr[j]);
        }
        j++;
    }
    
    if(i < pi){
        swap(&arr[i+1],&arr[pi]);
        return i+1;
    }else{
        swap(&arr[i],&arr[pi]);
        return i;
    }
    
}

void quickSort(int *arr, int l, int h){
    if (l < h)
    {
        int pi = partition(arr,l,h);

        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,h);
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

    // Insertion Sort
    insertionSort(arr,n);
    printf("Insertion Sort : ");
    printArray(arr,n);

    // Quick Sort
    quickSort(arrCopy,0,n-1);
    printf("Quick Sort : ");
    printArray(arrCopy,n);

    return 0;
}