#include <stdio.h>
#include <stdlib.h>

void read_int() {
    int age;
    puts("Enter the age: ");
    scanf("%i",&age);
    printf("age: %i",age);
}

void read_fullname() {
    char fname[40];
    char lname[40];
    puts("Enter the first and last name : ");
    scanf("%s %s",fname,lname);
    printf("Full name : %s %s\n",fname,lname);
    
}

void read_food_fgets(){
    char food[5];
    printf("Enter favorite food: ");
    fgets(food, sizeof(food), stdin);
    printf("Favorite food: %s", food);
}

int main()
{
    read_fullname();
    read_int();
    read_food_fgets();
    return 0;
}