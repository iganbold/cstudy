#include <stdio.h>
#include <stdlib.h>
#define  M 100
#define N 100
#define KNRM  "\x1B[0m"
#define KGRN  "\x1B[32m"
#define KBLU  "\x1B[34m"
#define KWHT  "\x1B[37m"
#define KYLW  "\x1b[33m"
#define KRED  "\x1b[31m"
#define RIGHT 'r'
#define LEFT  'l'
#define UP    'u'
#define DOWN  'd'
#define ZERO  '0'
#define ONE   '1'
#define XMARK 'X'

// custom row and column 
int customM, customN;

// loop direction for finding exit and entrance 
int start1,start2;

// Position type represnts positions on the maze
// and which direction (DOWN, RIGHT, UP, LEFT) it is going
struct Position {
   int row;
   int column;
   int isZeroOuterWall;
   char dir;
};

void findPath(char [][N]);
void findEntrance(char [][N], struct Position *pos);
void findExit(char [][N], struct Position *pos); 
void findZeroWall(char [][N], struct Position *pos,int);
void findRowEntrance(char [][N], int, int, struct Position *pos,int);
void findColumnEntrance(char [][N], int, int, struct Position *pos,int);
void copyPoint(struct Position *pos1, struct Position *pos2);
void printArray(char [][N]);
void printNoPathFound();
void printPathFound(struct Position *pos);
int isPositionEqual(struct Position *pos1,struct Position *pos2);
int isEntranceBlocked(char [][N],struct Position *pos);
int isRightBlocked(char [][N],struct Position *pos);
int isLeftBlocked(char [][N],struct Position *pos);
int isUpBlocked(char [][N],struct Position *pos);
int isDownBlocked(char [][N],struct Position *pos);
void markVisitedPath(char [][N],struct Position *pos);
void reverseDirection(struct Position *pos);
int checkRight(char array[][N],struct Position *pos);
int checkForward(char array[][N],struct Position *pos);
void turnRight(char array[][N],struct Position *pos);
void goLeft (struct Position *pos); 
void goRigth (struct Position *pos); 
void goUp (struct Position *pos); 
void goDown (struct Position *pos); 
void changeDirection(struct Position *pos);
void goForward(struct Position *pos);

main()
{
  char array[M][N]={0};
  FILE *fptr;
  char c;
  char file_name[20];
  int i,j;
  printf("%sWarning: the Field row and column number exactly match with the row and column number you provide.\nOtherwise, the PathFinder app will not work.\n",KYLW);
  printf("%s",KNRM);
  printf("Provide the exact row # and column #: \n");
  printf("Enter the # of row: ");
  scanf("%d", &customM);
  printf("Enter the # of column: ");
  scanf("%d", &customN);
  
  printf("Type in the name of the file containing the Field\n");
  printf("Enter the Field name: ");
  scanf("%s",file_name);
  fptr=fopen(file_name,"r");
  for (i=0; i<customM; i++)
   for (j=0; j<customN; j++){
     c=fgetc(fptr); 
     while ( !((c == ONE)||(c ==ZERO)) ) c=fgetc(fptr);
     array[i][j]=c;
   }
  fclose(fptr);

  printArray(array);
  printf("Before Traverse:\n"); 
  printf("Traversing ...\n"); 
    
  findPath(array);
}  

// finding the path (using right hand rule)
void findPath(char array[][N]) {
    
    struct Position currentPos,exitPos,entryPos;
    
    findEntrance(array, &entryPos);
    findExit(array, &exitPos);
    copyPoint(&currentPos,&entryPos);
    
    printf("* Entrance @ row: %d column: %d \n",entryPos.row,entryPos.column);
    printf("* Exit @ row: %d column: %d \n",exitPos.row,exitPos.column);
    
    if(isEntranceBlocked(array,&entryPos)) {
        markVisitedPath(array,&entryPos); 
        printArray(array);
        printNoPathFound();
    } else {
    
        while(1) {
            if(checkRight(array,&currentPos)) {         
                markVisitedPath(array,&currentPos);     
                turnRight(array,&currentPos);                 
                changeDirection(&currentPos);
            } else if(checkForward(array,&currentPos)) {
                markVisitedPath(array,&currentPos);     
                goForward(&currentPos);                     
            } else {
                reverseDirection(&currentPos);          
                continue;
            }
            
            if(isPositionEqual(&currentPos, &entryPos)) {
                printArray(array);
                printNoPathFound();
                break;
            } else if(isPositionEqual(&currentPos, &exitPos)) {
                markVisitedPath(array,&currentPos);
                printArray(array);
                printPathFound(&currentPos);
                break;
            }  
        }
    }
}

void printNoPathFound() {
    printf("After Traverse: %s:( No path found\n\n",KRED);
    printf("%s",KNRM);    
}

void printPathFound(struct Position *pos) {
    printf("After Traverse:\n\n");
    printf("\n****************\n");
    printf("*      WOW     *\n");
    printf("*  Path found  *\n");
    printf("  @ r: %d c: %d  \n",pos->row,pos->column);
    printf("****************\n");
}

void copyPoint(struct Position *pos1, struct Position *pos2) {
    pos1->row = pos2->row;
    pos1->column = pos2->column;
    pos1->dir = pos2->dir;
}

// Checks Entrance Position blocked by three ones
int isEntranceBlocked(char array[][N],struct Position *pos) {
    switch(pos->dir) {
        case DOWN:
            return (isRightBlocked(array,pos) && isLeftBlocked(array,pos) && isDownBlocked(array,pos));
        case UP:
            return (isRightBlocked(array,pos) && isLeftBlocked(array,pos) && isUpBlocked(array,pos));
        case LEFT:
            return (isUpBlocked(array,pos) && isLeftBlocked(array,pos) && isDownBlocked(array,pos));
        case RIGHT:
            return (isRightBlocked(array,pos) && isUpBlocked(array,pos) && isDownBlocked(array,pos));
    }
}

int isRightBlocked(char array[][N],struct Position *pos) {
    return (array[pos->row][pos->column+1] == ONE);   
}

int isLeftBlocked(char array[][N],struct Position *pos) {
    return (array[pos->row][pos->column-1] == ONE);   
}

int isUpBlocked(char array[][N],struct Position *pos) {
    return (array[pos->row-1][pos->column] == ONE);   
}

int isDownBlocked(char array[][N],struct Position *pos) {
    return (array[pos->row+1][pos->column] == ONE);   
}

// finding the entrance 
void findEntrance(char array[][N], struct Position *pos) {
    pos->isZeroOuterWall = 0;
    start1=1;
    start2=0;
    int i;
    for(i=0; i< 4;i++)
    {
        findZeroWall(array,pos,i);
        if(pos->isZeroOuterWall) break;
    }
}

// finding the exit
void findExit(char array[][N], struct Position *pos) {
    pos->isZeroOuterWall = 0;
    start1=0;
    start2=1;
    int i;
    for(i=3; i>= 0;i--)
    {
        findZeroWall(array,pos,i);
        if(pos->isZeroOuterWall) break;
    }
    
}

// finds zero from given wall and 
void findZeroWall(char array[][N], struct Position *pos,int wall) {
    switch(wall) {
        case 0:
            // finding zero from first top row
            findRowEntrance(array,0,customN,pos,start1);
            break;
        case 1:
            // finding entrance from last column
            findColumnEntrance(array,(customN-1),customM,pos,start1);
            break;
        case 2:
            // finding entrance from last bottow row
            findRowEntrance(array,(customM-1),customN,pos,start2);
            break;
        case 3:
            // finding entrance from first column
            findColumnEntrance(array,0,customM,pos,start2);
            break;
    }
        
    if(pos->isZeroOuterWall) {
        switch(wall) {
            case 0:
                pos->dir = DOWN;
                break;
            case 1:
                pos->dir = LEFT;
                break;
            case 2:
                pos->dir = UP;
                break;
            case 3:
                pos->dir = RIGHT;
                break;
        }
    }
}

// finds '0' from given wall(row)
void findRowEntrance(char array[][N],int row, int size, struct Position *pos,int start) {
    int i;
    if(start) {
        for(i=0;i<size;i++) {
         if(array[row][i] == ZERO)
         {
             pos->isZeroOuterWall = 1;
             pos->row = row;
             pos->column = i;
             break;
         }
        }
    } else {
        for(i=(size-1); i >= 0 ; i--) {
         if(array[row][i] == ZERO)
         {
             pos->isZeroOuterWall = 1;
             pos->row = row;
             pos->column = i;
             break;
         }
        }
    }
}

// finds '0' from given wall(column)
void findColumnEntrance(char array[][N], int column, int size, struct Position *pos,int start) 
{
    int i;
    if(start)
    {
        for(i=0;i<size;i++) {
          if(array[i][column] == ZERO)
          {
            pos->isZeroOuterWall = 1;
            pos->row = i;
            pos->column = column;
            break;
          }
        }
    } else {
        for(i=(size-1); i>= 0; i--) {
          if(array[i][column] == ZERO)
          {
            pos->isZeroOuterWall = 1;
            pos->row = i;
            pos->column = column;
            break;
          }
        }
    }
}


// prints maze with kernel color (1:green, 0:white, X:blue)
void printArray(char array[][N]) {
    int i,j;
    for (i=0; i<customM; i++)
      for (j=0; j<customN; j++)  {
        if (j == 0) printf("\n");
        switch(array[i][j]) {
            case ONE:
                printf("%s",KGRN);
                break;
            case ZERO:
                printf("%s",KWHT);
                break;
            case XMARK:
                printf("%s",KBLU);
                break;
        }
        
        printf("%c  ",array[i][j]);
      }
    printf("\n");
    printf("%s",KNRM);
}

// marks the visited path
void markVisitedPath(char array[][N],struct Position *pos) {
    array[pos->row][pos->column]=XMARK;
}

// checks the equality of 2 different Position
int isPositionEqual(struct Position *pos1, struct Position *pos2) {
    return (pos1->row == pos2->row) && (pos1->column == pos2->column);
}

// reverses the given Position's direction
void reverseDirection(struct Position *pos) {
    switch(pos->dir) {
        case UP:
            pos->dir = DOWN;
            break;
        case DOWN:
            pos->dir = UP;
            break;
        case RIGHT:
            pos->dir = LEFT;
            break;
        case LEFT:
            pos->dir = RIGHT;
            break;    
    }
}

// checks the given Position's right side is '0' or 'X' 
// if right side is '0' or 'X' return 1
// else return 0
int checkRight(char array[][N],struct Position *pos) {
    switch(pos->dir) {
        case DOWN:
            return ((array[pos->row][(pos->column-1)] == ZERO) || (array[pos->row][(pos->column-1)] == XMARK));
        case UP:
            return ((array[pos->row][(pos->column+1)] == ZERO) || (array[pos->row][(pos->column+1)] == XMARK));
        case LEFT:
            return ((array[(pos->row-1)][pos->column] == ZERO) || (array[(pos->row-1)][pos->column] == XMARK));
        case RIGHT:
            return ((array[(pos->row+1)][pos->column] == ZERO) || (array[(pos->row+1)][pos->column] == XMARK));
    }
}

// checks the given Position's front side is '0' or 'X'
// based on the it's direction
// if front side is '0' or 'X' return 1
// else return 0
int checkForward(char array[][N],struct Position *pos) {
    switch(pos->dir) {
        case DOWN:
            return ((array[(pos->row+1)][pos->column] == ZERO) || (array[(pos->row+1)][pos->column] == XMARK));
        case UP:
            return ((array[(pos->row-1)][pos->column] == ZERO) || (array[(pos->row-1)][pos->column] == XMARK));
        case LEFT:
            return ((array[pos->row][(pos->column-1)] == ZERO) || (array[pos->row][(pos->column-1)] == XMARK));
        case RIGHT:
            return ((array[pos->row][(pos->column+1)] == ZERO) || (array[pos->row][(pos->column+1)] == XMARK));
    }
}

// changes the given Position's position to right
// based on the it's direction
void turnRight(char array[][N],struct Position *pos) {
    switch(pos->dir) {
        case DOWN:
            goLeft(pos);
            break;
        case UP:
            goRigth(pos);
            break;
        case LEFT:
            goUp(pos);
            break;
        case RIGHT:
            goDown(pos);
            break;
    }
}

void goRigth (struct Position *pos) {
    pos->column = (pos->column+1);
}

void goLeft (struct Position *pos) {
    pos->column = (pos->column-1);
}

void goUp (struct Position *pos) {
    pos->row=(pos->row-1);
}

void goDown(struct Position *pos) {
    pos->row=(pos->row+1);   
}

// changes the given Position's position to forward
// based on the it's direction
void goForward(struct Position *pos) {
    switch(pos->dir) {
        case DOWN:
            goDown(pos);
            break;
        case UP:
            goUp(pos);
            break;
        case LEFT:
            goLeft(pos);
            break;
        case RIGHT:
            goRigth(pos);
            break;
    }
}

// chages the given Position's direction
// based on the it's direction
void changeDirection(struct Position *pos) {
    switch(pos->dir) {
        case DOWN:
            pos->dir = LEFT;
            break;
        case UP:
            pos->dir = RIGHT;
            break;
        case LEFT:
            pos->dir = UP;
            break;
        case RIGHT:
            pos->dir = DOWN;
            break;
    }
}
