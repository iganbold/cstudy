#include <stdio.h>

void go_south_east(int*,int*);
void go(int*, int*);
void fortune_cookie(char[]);

int main() {
    int lon = -64, lat = 32,*ptrLon;
    ptrLon = &lon;
    char cook[] = "Hello Cookie";
    go_south_east(&lon,&lat);
    
    printf("lon: %i , lat: %i, ptrLon: %p\n", lon, lat,ptrLon);
    printf("lon&: %p\n",&lon);
    
    fortune_cookie(cook);
    printf("@: %p\n",cook);
    return 0;
}

void go_south_east(int *log, int *lat) {
    *log = *log -1;
    *lat = *lat +1;
    
    printf("lon: %p\n",log);
    printf("local lon&: %p\n",&log);
    puts("calling go function()");
    go(log,lat);
}

void go(int *lon, int *lat) {
    printf("goLon: %i, goLat: %i\n",*lon, *lat);
}

void fortune_cookie(char msg[]) {
    printf("%s\n",msg);
    printf("@: %p\n",msg);
}