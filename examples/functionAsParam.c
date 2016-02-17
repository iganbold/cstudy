#include <stdlib.h>
#include <stdio.h>

int compare(int,int);
void useCompare(int,int,int (*)(int, int));

main() {
    useCompare(5,6,compare);    
    return 0;
}

void useCompare(int a, int b, int (*comp)(int,int)) {
    
    if((*comp)(a,b)) {
        printf("a is bigger: a-%d b-%d",a,b);
    } else {
        printf("b is bigger: a-%d b-%d",a,b);
    }
}

int compare(int a, int b) {
    return a > b ;
}

