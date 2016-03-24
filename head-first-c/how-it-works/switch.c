#include <stdio.h>

int main()
{
    int input;
    
    puts("Hello World");
    scanf("%i",&input);
    
    switch(input) {
        case 1:
            puts("hi");
            break;
        case 2:
            puts("kk");
            break;
        case 3:
            puts("hh");
            break;
        default:
            puts("default");
    }
}