int main() {
    int count=0;
    
    while(count < 10) {
        puts("count");
        count++;
    }
    
    for(;count < 20; count++)
        puts("count2");
        
    do {
        puts("count3");
        count++;
    } while(count<30); 
}