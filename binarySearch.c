#include <stdio.h>

int binarySearch(int *arr,int n,int key){
    int s = 0, e = n-1;
    while (s<=e)
    {
        int mid = (s+e)/2;
        if(arr[mid] == key){
            return mid;
        }else if(arr[mid] > key){
            e = mid - 1;
        }else {
            s = mid + 1;
        }
    }
    return -1;
}

int main(){

    int arr[20];
    int n, key;

    printf("Enter No. of Elements(<20) : ");
    scanf("%d", &n);

    printf("Enter %d Sorted Elements : ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter a number to search : ");
    scanf("%d",&key);

    int ans = binarySearch(arr,n,key);
    if(ans > 0)
        printf("%d is present at %dth position \n",key,ans);
    else 
        printf("%d is not present in given list. \n",key);

    return 0;
}

/*
    Enter No. of Elements(<20) : 7
    Enter 7 Sorted Elements : 12 14 16 25 28 29 32
    Enter a number to search : 28
    28 is present at 5th position 
*/