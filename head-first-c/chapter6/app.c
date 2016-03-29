#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct island {
    char *name;
    char *opens;
    char *closes;
    struct island *next;    //point/refer to next island
} island;   //the island is the name for struct island

void display(island*);
void displayWhile(island*);
island* create(char*);
void release(island*);

int main(int argc, char *argv[]) {
    // island amity = {"Amity","09:00","17:00",NULL};
    // island craggy = {"Craggy","09:00","17:00",NULL};
    // island isla_nublar = {"Isla Nublar","09:00","17:00",NULL};
    // island shutter = {"Shutter","09:00","17:00",NULL};
    
    // // amit->craggy->isla_nublar->shutter->NULL  
    // amity.next = &craggy;
    // craggy.next = &isla_nublar;
    // isla_nublar.next = &shutter;
    
    // // amit->craggy->isla_nublar->skull->shutter->NULL    
    // island skull = {"Skull","09:00","17:00",NULL};
    // isla_nublar.next = &skull;
    // skull.next = &shutter;
    
    // display(&amity);
    
    island *start = NULL;
    island *end   = NULL;
    island *new_island = NULL;
    char name[80];
    
    while(fgets(name,80,stdin) != NULL) {
        
        new_island = create(name);
        
        if(start == NULL) 
            start = new_island;
        else
            end->next = new_island; 
        
        end = new_island;
    }
    
    display(start);
    release(start);
    
    return 0;
}

void display(island *start) {
    //passing the address to i. Now i know that how to reach
    island *i;
    
    for(i = start; i->next != NULL ;i=i->next) {
        printf("Name: %sOpen: %s-%s\n",i->name,(*i).opens,(*i).closes);
    }
}

// Print names using while loop
void displayWhile(island *start) {
    island *j = start;
    while(j->next != NULL) {
        puts(j->name);
        j = j->next;
    }
}

island* create(char *name) {
    island *i = malloc(sizeof(island));
    
    // allocate memory @ heap and copy the strign of name
    i->name = strdup(name); 
    // i->opens = "09:00";
    // i->closes = "17:00";
    i->next = NULL;
    
    return i;  //return island pointer
}

void release(island *start) {
    island *i = start;
    island *next = NULL;
    
    for (; i->next !=NULL; i = next) {
        next = i->next;
        free(i->name);  //free the name string that I created with strdup()
        free(i);        //free the island struct
    }
}