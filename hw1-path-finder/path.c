#include <stdio.h>
#include <stdlib.h>
#define  M 100
#define N 100
#define KNRM  "\x1B[0m"
#define KGRN  "\x1B[32m"
#define KBLU  "\x1B[34m"
#define KWHT  "\x1B[37m"
#define RIGHT 'r'
#define LEFT  'l'
#define UP    'u'
#define DOWN  'd'
#define ZERO  '0'
#define ONE   '1'
#define XMARK 'X'


int customM, customN;

struct Position {
   int row;
   int column;
   int isZeroWall;
   char dir;
};

void findPath(char [][N]);
void findEntrance(char [][N], struct Position *pos);
void findExit(char [][N], struct Position *pos); 
void findZeroWall(char [][N], struct Position *pos,int);
void findRowEntrance(char [][N], int, int, struct Position *pos);
void findColumnEntrance(char [][N], int, int, struct Position *pos);
void printArray(char [][N]);
int isPositionEqual(struct Position *pos1,struct Position *pos2);
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
  
  printf("Provide row # and column #: \n");
  printf("Enter # of row: ");
  scanf("%d", &customM);
  printf("Enter # of column: ");
  scanf("%d", &customN);
  
  printf("Type in the name of the file containing the Field\n");
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
    
  findPath(array);
}  

// finding the path 
void findPath(char array[][N]) {
    
    struct Position currentPos,exitPos,entryPos;
    
    findEntrance(array, &entryPos);
    findExit(array, &exitPos);
  
    currentPos.row = entryPos.row;
    currentPos.column = entryPos.column;
    currentPos.dir = entryPos.dir;
    
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
            printf(" :( No exit");
            printArray(array);
            break;
        } else if(isPositionEqual(&currentPos, &exitPos)) {
            printf("\n****************\n");
            printf("*      WOW     *\n");
            printf("*  Found exit  *\n");
            printf("* @ r: %d c: %d  *\n",currentPos.row,currentPos.column);
            printf("****************\n");
            markVisitedPath(array,&currentPos);
            printArray(array);
            break;
        }  
    }
    
    printf("currentPos column: %d row: %d",currentPos.column,currentPos.row);
    printf("\n");
}

// finding the entrance 
void findEntrance(char array[][N], struct Position *pos) {
    pos->isZeroWall = 0;
    
    int i;
    for(i=0; i< 4;i++)
    {
        findZeroWall(array,pos,i);
        if(pos->isZeroWall) break;
    }
}

// finding the exit
void findExit(char array[][N], struct Position *pos) {
    pos->isZeroWall = 0;
    
    int i;
    for(i=3; i>= 0;i--)
    {
        findZeroWall(array,pos,i);
        if(pos->isZeroWall) break;
    }
    
}

// finds zero from given wall and 
void findZeroWall(char array[][N], struct Position *pos,int wall) {
    switch(wall) {
        case 0:
            // finding zero from first top row
            findRowEntrance(array,0,customN,pos);
            break;
        case 1:
            // finding entrance from last column
            findColumnEntrance(array,(customN-1),customM,pos);
            break;
        case 2:
            // finding entrance from last bottow row
            findRowEntrance(array,(customM-1),customN,pos);
            break;
        case 3:
            // finding entrance from first column
            findColumnEntrance(array,0,customM,pos);
            break;
    }
        
    if(pos->isZeroWall) {
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
void findRowEntrance(char array[][N],int row, int size, struct Position *pos) {
    int i;
    for(i=0;i<size;i++) {
     if(array[row][i] == ZERO)
     {
         pos->isZeroWall = 1;
         pos->row = row;
         pos->column = i;
         break;
     }
    } 
}

// finds '0' from given wall(column)
void findColumnEntrance(char array[][N], int column, int size, struct Position *pos) 
{
    int i;
    for(i=0;i<size;i++) {
      if(array[i][column] == ZERO)
      {
        pos->isZeroWall = 1;
        pos->row = i;
        pos->column = column;
        break;
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
