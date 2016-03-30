#include <stdio.h>
#include <stdarg.h>

double avg(int count, ...);

int main() {
    printf("%f\n",avg(3,4.0,6.0,2.0));
}

double avg(int count, ...) {
    
    va_list list;
    va_start(list,count);

    int j;
    double sum = 0;
    
    for(j=0; j < count; j++) {
        sum += va_arg(list,double);
    }
    
    va_end(list);
    
    return sum/count;
}