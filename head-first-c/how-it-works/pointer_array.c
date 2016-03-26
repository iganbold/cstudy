#include <stdio.h>

void skip(char *msg);
void get_names_print(char[],char[]);

//these 2 are equivalent
void change_array1(char*);
void change_array2(char[]);

int main() {
    int contestants[] = {1,2,3};
    int *choice = contestants; // contestants's values is the address of the first value in array
    
    char first_name[20];
    char last_name[20];
    
    contestants[0] = 2;
    contestants[1] = contestants[2];
    contestants[2] = *choice;
    
    printf("%i\n", contestants[2]);
    printf("%i\n", choice[1]);
    
    (&contestants == contestants)? puts("equal") : puts("not equal");
    (&choice == choice)? puts("equal") : puts("not equal");
    
    char *msg1 = "Don't call me.";
    skip(msg1);
    
    get_names_print(first_name,last_name);
    
    char msg2[] = "Hello";
    change_array1(msg2);
    change_array2(msg2);
    puts(msg2);
    return 0;
}

void skip(char *msg) {
    puts(msg + 6);
}

void get_names_print(char first_name[],char last_name[]) {
    puts("Enter First name and Last name:");
    scanf("%s %s",first_name,last_name);
    printf("FN: %s\nLN: %s\n",first_name,last_name);
}

// equivalent to change_array2
void change_array1(char *msg) {
    msg[2]= '1';
}

// equivalent to change_array1
void change_array2(char msg[]) {
    msg[3] = '2';
}