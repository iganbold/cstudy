#include <stdio.h>
#include <stdlib.h>

//*lat and *lon pointer variable which get memory address then get and set the content at memory 
void go_south_east(int *lat, int *lon) {
    *lat = *lat - 1;
    *lon = *lon + 1;
}

//msg is similar to pointer variable
void fortune_cookies(char msg[]){
    printf("The msg is: %s\n",msg);
    printf("the msg occupies %i bytes\n ", sizeof(msg));
    msg[0] = 'A';
}

int main() {
    int latitude = 32;
    int longitude = -64;
    
    go_south_east(&latitude, &longitude);
    
    printf("Avast! now at: [%i,%i]\n",latitude,longitude);
    
    char msg[]= "HEllo World";
    fortune_cookies(msg);
    
    puts(msg);
    
    //drinks is array variable and array variable can be pointer to first value of array
    int drinks[] = {4,2,3};
    
    printf("1st order drink %i\n",drinks[0]);
    printf("1st order drink %i\n",*drinks);
    
    //same
    printf("%i\n",&drinks);
    printf("%i\n",drinks);
    
    
    //all same
    printf("last value %i\n",drinks[2]);
    printf("last value %i\n",*(drinks + 2));    //getting next 2 memory address then making pointer variable to set or get   
    printf("last value %i\n",2[drinks]);
    
    return 0;
} 