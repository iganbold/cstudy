#include <stdio.h>
#include "union.h"
#include "enum.h"

struct fish {
    const char *name;
    const char *species;
    int teeth;
    int age;
};

#include "main.h"

int main() {
  struct fish snappy = {"Snappy","Piranha",69,4};
  catalog(snappy);
  label(&snappy);
  
  test_union();
  test_enum();
  return 0;
}

void catalog(struct fish f) {
    printf("%s is a %s with %i teeth. He is %i\n",f.name,f.species,f.teeth,f.age);
}


void label(struct fish *f) {
    printf("name: %s\n",(*f).name);
}