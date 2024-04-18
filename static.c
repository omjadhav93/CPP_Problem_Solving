#include <stdio.h>

int func(){
    static int a = 10;
    a++;
    return a;
}

int main(){
    
    printf("%d\n",func());
    printf("%d\n",func());

    return 0;
}