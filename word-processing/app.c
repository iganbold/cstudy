#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "list.h"
#define WORD_SIZE 50
#define LIST_SIZE 500
#define EXTRA_SPACE 1;

void printSpace(int);

main() {
    
    LISTNODEPTR startPtr = NULL;        //used for storing the data
    LISTNODEPTR queueBufferPtr = NULL;        //used for buffing the data from the list
    int limit = 40;
    FILE *fp;                           
    
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
        
        //----------------------------------------------------------------------
        
        int buffSize = 0;
        int wordSize = 0;
        int wordCount = 0;
        int wordSpace = 0;
        int wordLastSpace = 0;
    
        while( startPtr != NULL)
        {
            
            if((buffSize + (int)strlen(startPtr->data)) == limit) {
                insert(&queueBufferPtr, (startPtr)->data);
                delete(&startPtr,(startPtr->data));
                
                wordSpace = ((limit - wordSize) / wordCount);
                wordLastSpace = wordSpace + ((limit - wordSize) % wordCount);
                
                while(wordCount != 0) {
                    
                    if(wordCount > 1)
                    {
                        printf("%s",(queueBufferPtr->data));
                        printSpace(wordSpace);
                    }
                    else if(wordCount == 1)
                    {
                        printSpace(wordLastSpace);
                        printf("%s",(queueBufferPtr->data));
                    }
                    delete(&queueBufferPtr, (queueBufferPtr->data));
                    wordCount--;
                }
                printf(":%d %d %d %d\n",wordSize, wordCount,wordSpace,wordLastSpace);
                buffSize = wordSize = wordCount = wordSpace = wordLastSpace = 0;
            } else if((buffSize + (int)strlen(startPtr->data)) < limit) {
                wordSize += (int)strlen(startPtr->data);
                wordCount++;
                buffSize = buffSize + ((int)strlen(startPtr->data)) + EXTRA_SPACE;
                insert(&queueBufferPtr,(startPtr)->data);
                delete(&startPtr,(startPtr->data));
            } else {
                
                wordSpace = ((limit - wordSize) / wordCount);
                wordLastSpace = wordSpace + ((limit - wordSize) % wordCount);
                
                while(queueBufferPtr != NULL) {
                    printf("%s",(queueBufferPtr->data));
                    printSpace(1);
                    delete(&queueBufferPtr, (queueBufferPtr->data));
                    
                    // printf("%s",(queueBufferPtr->data));
                    // delete(&queueBufferPtr, (queueBufferPtr->data));
                    // if(wordCount > 2)
                    //     printSpace(wordSpace);
                    // else if(wordCount == 2)
                    //     printSpace(wordLastSpace);
                    
                    // wordCount--;
                }
                printf("\n");
                // printf(":%d %d %d %d\n",wordSize, wordCount,wordSpace,wordLastSpace);
                buffSize = wordSize = wordCount = wordSpace = wordLastSpace = 0;
            }
            
            if(startPtr == NULL)
            {
                while(queueBufferPtr != NULL) {
                    printf("%s",(queueBufferPtr->data));
                    printSpace(1);
                    delete(&queueBufferPtr, (queueBufferPtr->data));
                }
            }
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        //---------------------------------------------------------------------
        //Buffer
        // int count=0,len = 0, spaces, word_space, last_word_space;
        // limit = 40;
        // char buff[50];
        // while(startPtr != NULL) {
            
        //     strcpy(buff,startPtr->data);
        //     delete(&startPtr,buff);
            
        //     if(strcmp(buff, "\n") == 0)
        //         continue;
                
        //     len += (strlen(buff) + 1);
            
        //     if(len > (limit+1)) {
        //         len -= strlen(buff);
        //         spaces = limit - len;
        //         //remove the added spaces +1
        //         word_space=spaces/(count-1);
                
        //         if(spaces%(count-1) == 0)
        //         {
        //             while(1)
        //             {
        //                 strcpy(buff,queuePtr->data);
        //                 printf("%s",buff);
                        
        //                 if(count >= 2)
        //                     printSpace(word_space);
                            
        //                 delete(&queuePtr,buff);
        //                 count--;
                        
        //                 if(count == 0)
        //                 {
        //                     printf("\n");
        //                     break;
        //                 }
        //             }
                    
        //         } else {
                    
        //             last_word_space = (word_space + (spaces%(count-1)));
                    
        //             while(1)
        //             {
        //                 strcpy(buff,queuePtr->data);
        //                 printf("%s",buff);
                        
        //                 if(count == 2)
        //                     printSpace(last_word_space);
        //                 else if(count >= 3)
        //                     printSpace(word_space);
                            
        //                 delete(&queuePtr,buff);
        //                 count--;
                        
        //                 if(count == 0)
        //                 {
        //                     printf("\n");
        //                     break;
        //                 }
        //             }
        //         }
                
        //         word_space = 0;
        //         last_word_space = 0;
        //         len = 0;
        //         spaces = 0;

        //     } // end of if limit
            
        //     insert(&queuePtr,buff);
        //     count++;
        // }// end of while
    }
}

void printSpace(int spaceSize) {
    int count;
    for(count=0; count <= spaceSize; count++) {
        printf(" ");
    }
}

