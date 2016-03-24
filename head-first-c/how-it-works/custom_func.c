#include <stdio.h>

int larger(int,int);
void happy();

int main() {
    
    printf("larger: %i\n",larger(5,6));
    happy();
    return 0;
}

int larger(int a, int b) {
    return (a > b) ? a : b;
}

 void happy() {
     puts("I am really happy.");
 }