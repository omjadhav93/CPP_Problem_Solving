/* W.A.P to sort the given integers and perform following operations ,
	1. Find the product of every two consecutive odd position elements,
	2. Find the sum of every two consecutive even position elements. 
*/

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
    
    printf("Required Output: \n");
    for(i = 3; i <= n; i+=2){
    	printf("%d ",arr[i-1]*arr[i-3]);
	}
    printf("\n");
	for(i = 4; i <= n; i+=2){
    	printf("%d ",arr[i-1]+arr[i-3]);
	}
    printf("\n");
	
	return 0;
}
