#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int n,i;
    printf("Enter size of array : ");
    scanf("%d",&n);

    int *arr = (int*)malloc(n*sizeof(int));
    printf("Enter %d elements of array : \n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    int N;
    printf("Enter new size of array : ");
    scanf("%d",&N);

    arr = (int*)realloc(arr,N*sizeof(int));

    if(N>n){
        printf("Enter %d more elements : \n",N-n);
        for (int i = n; i < N; i++)
        {
            scanf("%d",&arr[i]);
        }
    }

    printf("Array after resizing : \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}