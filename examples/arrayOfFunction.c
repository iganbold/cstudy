#include <stdlib.h>
#include <stdio.h>

void f1(int);
void f2(int);
void f3(int);

main () {
    void (*flist[3])(int) = {f1,f2,f3};
    
    int i;
    
    do {
        printf("Enter between 0 and 2, 3 to exit\n");
        printf("Enter #: ");
        scanf("%d",&i);
        if(i >= 3 || i <= -1)
            break;
        (*flist[i])(i);
    } while(1);
    
    printf("End\n");
    return 0;
}

void f1(int i) {
    printf("f1 : %d\n",i);
}

void f2(int i) {
    printf("f2 : %d\n",i);
}

void f3(int i) {
    printf("f3 : %d\n",i);
}