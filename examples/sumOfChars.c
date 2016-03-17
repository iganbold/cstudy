#include <stdio.h>
#include <stdlib.h>

main() {
    char list[] = "1234"; 
    int i, total=0;
    for(i=0; list[i] != '\0' ; i++) {
        printf("%c\n",list[i]);
        total += list[i] - '0';
    }
    printf("total : %d",total);
}