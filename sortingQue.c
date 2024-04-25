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

void printArray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
	int arr[20];
    int n,i;
    
    printf("Enter No. of Elements(<20) : ");
    scanf("%d",&n);

    printf("Enter %d Elements : ",n);
    for (i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    insertionSort(arr,n);
    
    printf("Required Output: ");
    for(i = 3; i < n; i+=2){
    	printf("%d ",arr[i-1]*arr[i-3]);
	}
	for(i = 2; i < n; i+=2){
    	printf("%d ",arr[i-1]+arr[i-3]);
	}
	
	return 0;
}
