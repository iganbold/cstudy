// Class    : ITCS 3146
// Author   : Itgel Ganbold
// Section : 001    

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "list.h"                                               // import linked list

#define WORD_SIZE 50
#define LIST_SIZE 500
#define FILE_NAME_SIZE 100

void printSpace (int);
void getFileName (char*);
void getNumberOfLine (int*);

main() {
    
    LISTNODEPTR startPtr = NULL;                                //used for storing the data
    LISTNODEPTR queueBufferPtr = NULL;                          //used for buffing the data from the list
    int perLineLimit = 40;                                      //default per line limit is 40
    char fileName[FILE_NAME_SIZE];
    FILE *fp;                                                   
    
    getFileName(fileName);                                      // get filename from terminal
    
    //***Read data and add data to Linked List
    if((fp = fopen(fileName,"r")) == NULL) {
        printf("File does not exist.\n");
        exit(EXIT_FAILURE);
    } else {
        
        char line[LIST_SIZE];
        char splitter[]="\n";                                   // prag splitter
        while (fgets(line, LIST_SIZE , fp) != NULL)  {          // read data from a file line by line     
            if((strlen(line)) == 2)
            {
                insert(&startPtr,splitter);                     // empty line add "\n" to Linked list
            } else {
                int i=0,j=0;                                    // i is counter for loop , j is counter for tempWord
                char tempWord[WORD_SIZE]="\0";                  // store word until next white space character
                int *test = (int *)malloc(sizeof(int));         // used to determine white space characters
                for (; i <= strlen(line) ;i++,j++) {            // read each character to find word and white space characters
                    if(!isspace(line[i]))                       // check spaces
                    {
                        // || ispunct(line[i]) || ispunct(line[i-1])
                        if(*test == 1 || i == strlen(line))
                        {
                            if(tempWord[0] != '\0')
                            {
                                insert(&startPtr,tempWord);     // add to list    
                                *test = 0;
                                j=0;
                                memset(tempWord,0,WORD_SIZE);   // clear tempWord in order store next word
                            }
                        }
                    
                        tempWord[j]=line[i];                    // making a word
                    }
                    else *test = 1;
                }
                
                free(test);
            }
        } // end of while loop
        
        fclose(fp);                                             // close file
        getNumberOfLine(&perLineLimit);                         // get the number of line from terminal
        
        //Uncomment below line to print tokens
        // printList(startPtr);
        
        //***Type justification
        int buffSize = 0;
        int countNewLine = 0;
        
        while(startPtr != NULL) {
            
            buffSize = buffSize + (int)strlen(startPtr->data) +1;                       //keep track of number characsters for per line
            
            if(buffSize <= perLineLimit || (buffSize-1)==perLineLimit) {    
                    
                // if track does reach the limit, then buffer (queueBufferPtr) the data from the list (startPtr) then delete the data from the list     
                insert(&queueBufferPtr, (startPtr)->data);                  
                delete(&startPtr,(startPtr->data));
                
                if(startPtr != NULL) {
                    
                    if(strcmp((queueBufferPtr->data), "\n") == 0 ) {                    //check the data is "\n" if it is then split the prograph
                        buffSize=0;
                        countNewLine++;
                        if(countNewLine < 2)
                            printf("\n\n");
                    }
                    else if((buffSize+(int)strlen(startPtr->data)) > perLineLimit) {    //if data is the last word of the line then print it ( 1. spaces 2. data)
                        printSpace((perLineLimit-buffSize)+1);
                        printf("%s",queueBufferPtr->data);
                    } else {                                                            //otherwise print the data from the buffer (1. data  2. spaces)
                        if( countNewLine !=0 ) countNewLine = 0; 
                        printf("%s",queueBufferPtr->data);
                        printSpace(1);
                    }
                    
                    delete(&queueBufferPtr,(queueBufferPtr->data));                     //clear the buffer   
                    
                } else printf("%s\n",queueBufferPtr->data);
                
            } else {
                
                printf("\n");
                buffSize=0;
                
            }
        } // end of while loop
        
    }
}

//Gets filename from terminal
void getFileName(char *fileName) {
    printf("File name and location : ");
    scanf("%s",fileName);    
}

//Gets number of line for per line from terminal
void getNumberOfLine(int *size) {
    while(1) {
        printf("Number of Characters between 40 and 100 for per line : ");
        scanf("%d",size);    

        if(*size >= 40 && *size <= 100) break;
        else printf("Please enter correct number.\n");
    }
}

//Prints the space between words the during the word processing
void printSpace(int spaceSize) {
    int count;
    for(count=0; count < spaceSize; count++) printf(" ");
}

