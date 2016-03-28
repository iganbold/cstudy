#include <stdio.h>
#include "union.h"

typedef union {
    short count;
    float weight;
    float volume;
} quantity;

typedef struct {
  const char *name;
  const char *country;
  quantity amount;
} fruit_order;

void test_union() {
    fruit_order orange = {"orange","Mongolia",.amount.count=100};
    puts("Union Test:");
    printf("{Name: %s, Country: %s, Count: %hu}\n",orange.name,orange.country,orange.amount.count);
}