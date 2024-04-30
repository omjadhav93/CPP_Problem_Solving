#include <stdio.h>

int linearSearch(int *arr, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i + 1;
    }
    return -1;
}

int main()
{

    int arr[20];
    int n, key;

    printf("Enter No. of Elements(<20) : ");
    scanf("%d", &n);

    printf("Enter %d Elements : ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter a number to search : ");
    scanf("%d",&key);

    int ans = linearSearch(arr,n,key);
    if(ans > 0)
        printf("%d is present at %dth position \n",key,ans);
    else 
        printf("%d is not present in given list. \n",key);

    return 0;
}

/*
    Enter No. of Elements(<20) : 7
    Enter 7 Elements : 41 12 25 36 45 15 35
    Enter a number to search : 15
    15 is present at 6th position 
*/