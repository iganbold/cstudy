#include <stdlib.h>
#include <stdio.h>

void copy1(char *,const char *);
void copy2(char *,const char *);

main() {
    char string1[10], string3[10];
    char  *string2 = "Hello", string4[10]="Good Bye";
    
    copy1(string1,string2);
    printf("String1 : %s\n",string1);
    
    copy2(string3,string4);
    printf("String3 : %s\n",string3);
    
    *string3 = 'Z';
    printf("String3 : %s\n",string3);
}

void copy1(char *cp1, const char *cp2) {
    int i;
    for (i=0; cp1[i] = cp2[i]; i++);
}

void copy2(char *cp1, const char *cp2) {
    int i;
    for(; *cp1 = *cp2; cp1++,cp2++);
}