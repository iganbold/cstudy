#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "list.h"
#define WORD_SIZE 50
#define LIST_SIZE 500

main() {
    
    LISTNODEPTR startPtr = NULL;
    
    FILE *fp;
    char buff[WORD_SIZE];
    
    if((fp = fopen("./test-files/file4-1.txt","r")) == NULL) {
        exit(EXIT_FAILURE);
    } else {
        
        char line[LIST_SIZE];
        char splitter[]="+"; // prag splitter
        while (fgets(line, LIST_SIZE , fp) != NULL)  {
            if((strlen(line)) == 2)
            {
                insert(&startPtr,splitter);
            } else {
                int i=0,j=0;
                char tempWord[WORD_SIZE]="\0";
                int *test = (int *)malloc(sizeof(int));
                for (; i <= strlen(line) ;i++,j++) {
                    if(!isspace(line[i]))
                    {
                        if(*test == 1 || ispunct(line[i]) || ispunct(line[i-1]))
                        {
                            if(tempWord[0] != '\0')
                            {
                                insert(&startPtr,tempWord);
                                *test = 0;
                                j=0;
                                memset(tempWord,0,WORD_SIZE);
                            }
                        }
                        
                        tempWord[j]=line[i];
                    }
                    else {
                        *test = 1;
                    }
                }
                
                free(test);
            }
        }
        
        fclose(fp);
        
        printList(startPtr);
    }
}