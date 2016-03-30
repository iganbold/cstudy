#include <stdio.h>

void file_write();
void file_write_fprintf();
void file_read();
void file_read_line();
void file_read_fscanf();

int main() {
    file_write();
    file_read();
    file_write_fprintf();
    file_read_line();
    file_read_fscanf();
    return 0;
}

void file_write() {
    char txt[] = "Hello World 2016\n";
    FILE *output = fopen("fwrite_out.txt","a");
    fwrite(txt, 1,sizeof(txt),output);
    fclose(output);
}

void file_read() {
    puts("Read char by char");
    FILE *input = fopen("fwrite_out.txt","r");
    char c;
    
    while(1) {
        c = fgetc(input);
        if(feof(input))
            break;
        
        printf("%c",c);
    }
    fclose(input);
}

void file_read_line() {
    puts("Read line by line");
    FILE *input = fopen("fwrite_out.txt","r");
    char str[80];
    
    while(fgets(str,80,input) != NULL) {
        printf("%s",str);
    }
    
    fclose(input);
}

void file_read_fscanf() {
    puts("Read fscanf");
    FILE *input = fopen("fwrite_out.txt","r");
    
    char hello[80];
    char world[80];
    int year;
    
    while(fscanf(input,"%s %s %i",hello,world,&year) != EOF) {
        printf("txt1: %s txt2: %s txt3: %i\n",hello,world,year);   
    }
    
    fclose(input);
}

void file_write_fprintf() {
    puts("Write printf");
    FILE *output_stream = fopen("fwrite_out.txt","a");
    
    fprintf(output_stream,"%s %s %d\n","we","are",10);
    fclose(output_stream);
}