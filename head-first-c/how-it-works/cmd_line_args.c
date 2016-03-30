#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i = 1;
    double total = 0.0;
    for(;i < argc; i++) {
        printf("%f %s\n",total += atof(argv[i]),(""+i));
    }
    
   double num=123412341234.123456789; 
   char output[50];
   snprintf(output,50,"%f",num);
   printf("%s",output);
    
    puts("end");
    return 0;
}