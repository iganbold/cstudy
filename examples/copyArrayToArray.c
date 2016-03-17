#include <stdio.h>
#include <stdlib.h>
void printArray(int *);

main( )
{
    // int a[2][3] = {{11,2,3},{22,2,3}};
    // printArray(&a[0][0]);
    int x = 1, y = 2, k=5,j=10;
    
    if(x>y)
        if(x>y)
            k++;
    else
        j++;
        
    int arr[] = {12,13,14,15,16};    
        
    printf("%zd", sizeof(arr));
}

void printArray(int *a) {
    printf("%d", *(a+2));
}