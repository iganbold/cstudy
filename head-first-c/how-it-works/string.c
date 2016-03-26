#include <stdio.h>
#include <string.h>
#define LINE_SIZE 80

void find_track(char[]);

char tracks[][LINE_SIZE] = {
     "I left my heart in Harvard Med School",
     "Newark, Newark - a wonderful town",
     "Dancing with a Dork",
     "From here to maternity",
     "The girl from Iwo Jima",
};

int main() {
    char search_for[LINE_SIZE];
    
    printf("Search: ");
    fgets(search_for,LINE_SIZE,stdin);
    find_track(search_for);
    return 0;    
}

void find_track(char search_for[]) {
    int i;
    for(i=0; i<5 ; i++) {
        if(strstr(tracks[i],search_for))
            printf("%i %s\n",i,tracks[i]);
    }
}
