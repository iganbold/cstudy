#include <stdio.h>

int main() {
    
    char word[10];
    int count = 0;
    
    while(scanf("%9s",word) == 1) {
        count++;
        if((count%2) == 0)
            fprintf(stdout, "%s\n",word);
        else
            fprintf(stderr, "%s\n",word);
    }
    
    return 0;
}