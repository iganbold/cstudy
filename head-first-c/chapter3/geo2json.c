#include <stdio.h>


int main() {
    float lon;
    float lat;
    char info[80];
    int started = 0;
    
    puts("data=[");
    
    while(scanf("%f,%f,%79[^\n]",&lat,&lon,info) == 3) {
        if(started)
            printf(",\n");
        else
            started = 1;
            
        if((lat < -90) || (lat > 90)) {
            fprintf(stderr,"{error: 'invalid latitude'}");
            return 2;
        }
        
        if((lon < -180) || (lon > 180)) {
            fprintf(stderr,"{error: 'invalid longtitude'}");
            return 2;
        }
        
            
        printf("{latitude: %f, longtitude: %f, info: '%s'}",lat,lon,info);
    }
    
    puts("\n]");
    return 0;
}