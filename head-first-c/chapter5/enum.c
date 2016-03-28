#include <stdio.h>
#include "enum.h"

// enum use , to seprate its fields
typedef enum {
  COUNT, POUNDS, PINTS  
} unit_of_measure;

// struct/union use ; to seprate its fields
typedef union {
  short count;
  float weight;
  float volume;
} quant;

typedef struct{
  const char *name;
  const char *country;
  quant amount;
  unit_of_measure units;
} fruit;

void _display(fruit order) {
    switch(order.units) {
        case COUNT:
            printf("{Name: %s, Unit: COUNT, Amount: %uh}\n",order.name,order.amount.count);
            break;
        case POUNDS:
            printf("{Name: %s, Unit: POUNDS, Amount: %f}\n",order.name,order.amount.weight);
            break;
        case PINTS:
            printf("{Name: %s, Unit: PINTS, Amount: %f}\n",order.name,order.amount.volume);
            break;
        default:
            puts("Default enum");
    }
}

void test_enum() {
    fruit apples = {"apples","England", .amount.count = 144, .units=COUNT};
    fruit strawberries = {"strawberries", "Spain", .amount.weight = 17.6, .units=POUNDS};
    fruit oj= {"orange juice", "U.S.A.", .amount.volume = 10.5, .units=PINTS};
    
    puts("Enum Test:");
    _display(apples);
    _display(strawberries);
    _display(oj);
}
