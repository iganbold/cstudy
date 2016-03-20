/* Operating and maintaining a list */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 0

struct listNode {  /* self-referential structure */
   char data[50];
   struct listNode *nextPtr;
};

typedef struct listNode LISTNODE;
typedef LISTNODE *LISTNODEPTR;

void insert(LISTNODEPTR *, char[]);
char* delete(LISTNODEPTR *, char[]);
int isEmpty(LISTNODEPTR);
void printList(LISTNODEPTR);
void instructions(void);

#if DEBUG
main()
{
   LISTNODEPTR startPtr = NULL;
   int choice;
   char item[45];

   instructions();  /* display the menu */
   printf("? ");
   scanf("%d", &choice);

   while (choice != 3) {

      switch (choice) {
         case 1:
            printf("Enter a character: ");
            scanf("\n%s", item);
            insert(&startPtr, item);
            printList(startPtr);
            break;
         case 2:
            if (!isEmpty(startPtr)) {
               printf("Enter character to be deleted: ");
               scanf("\n%s", item);

               if (delete(&startPtr, item)) {
                  printf("%s deleted.\n", item);
                  printList(startPtr);
               }
               else
                  printf("%s not found.\n\n", item);
            }
            else
               printf("List is empty.\n\n");

            break;
         default:
            printf("Invalid choice.\n\n");
            instructions();
            break;
      }

      printf("? ");
      scanf("%d", &choice);
   }

   printf("End of run.\n");
   return 0;
}
#endif

/* Print the instructions */
void instructions(void)
{
   printf("Enter your choice:\n"
          "   1 to insert an element into the list.\n"
          "   2 to delete an element from the list.\n"
          "   3 to end.\n");
}

/* Insert a new value into the list in sorted order */
void insert(LISTNODEPTR *sPtr, char value[])
{
   LISTNODEPTR newPtr, previousPtr, currentPtr;

   newPtr = malloc(sizeof(LISTNODE));

   if (newPtr != NULL) {    /* is space available */
      strcpy((newPtr->data),value);
      newPtr->nextPtr = NULL;

      previousPtr = NULL;
      currentPtr = *sPtr;

      while (currentPtr != NULL && value > currentPtr->data) {
         previousPtr = currentPtr;          /* walk to ...   */
         currentPtr = currentPtr->nextPtr;  /* ... next node */
      }

      if (previousPtr == NULL) {
         newPtr->nextPtr = *sPtr;
         *sPtr = newPtr;
      }
      else {
         previousPtr->nextPtr = newPtr;
         newPtr->nextPtr = currentPtr;
      }
   }
   else
      printf("%s not inserted. No memory available.\n", value);
}

/* Delete a list element */
char* delete(LISTNODEPTR *sPtr, char value[])
{
   LISTNODEPTR previousPtr, currentPtr, tempPtr;
    
   if (strcmp((*sPtr)->data, value) == 0) {
      tempPtr = *sPtr;
      *sPtr = (*sPtr)->nextPtr;  /* de-thread the node */
      free(tempPtr);             /* free the de-threaded node */
      return value;
   }
   else {
      previousPtr = *sPtr;
      currentPtr = (*sPtr)->nextPtr;
        
      while (currentPtr != NULL && strcmp(currentPtr->data, value) != 0) {
         previousPtr = currentPtr;          /* walk to ...   */
         currentPtr = currentPtr->nextPtr;  /* ... next node */
      }

      if (currentPtr != NULL) {
         tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         free(tempPtr);
         return value;
      }                                                        
   }
    //fix
   return value;
}

/* Return 1 if the list is empty, 0 otherwise */
int isEmpty(LISTNODEPTR sPtr)
{
   return sPtr == NULL;
}

/* Print the list */
void printList(LISTNODEPTR currentPtr)
{
   if (currentPtr == NULL)
      printf("List is empty.\n\n");
   else {
      printf("The list is:\n");

      while (currentPtr != NULL) {
         printf("%s --> ", currentPtr->data);
         currentPtr = currentPtr->nextPtr;
      }

      printf("NULL\n\n");
   }
}
