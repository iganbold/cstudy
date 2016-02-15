#include <stdio.h>
#include <stdlib.h>
#define  M 100
#define N 100
#define KNRM  "\x1B[0m"
#define KGRN  "\x1B[32m"
#define KBLU  "\x1B[34m"
#define KWHT  "\x1B[37m"


int customM, customN;

struct Position {
   int row;
   int column;
   int isEntrance;
   char dir;
};

void findRowEntrance(char [][N], int, int, struct Position *pos);
void findColumnEntrance(char [][N], int, int, struct Position *pos);
void findEntrance(char [][N], struct Position *pos);
void findExit(char [][N], struct Position *pos); 
void findPath(char [][N]);
void printArray(char [][N]);
int isEqual(struct Position *pos1,struct Position *pos2);
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
  
  printf("Enter row and column: \n");
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
     while ( !((c == '1')||(c =='0')) ) c=fgetc(fptr);
     array[i][j]=c;
   }
  fclose(fptr);

  printArray(array);
  
  //Path Finder App
//   struct Position
  
  findPath(array);
}  

// finding the entrance 
void findEntrance(char array[][N], struct Position *pos) {
    pos->isEntrance = 0;
    
    int i;
    for(i=0; i< 4;i++)
    {
        switch(i) {
            case 0:
                // finding entrance from first top row
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
        
        if(pos->isEntrance) {
            switch(i) {
                case 0:
                    pos->dir = 'd';
                    break;
                case 1:
                    pos->dir = 'l';
                    break;
                case 2:
                    pos->dir = 'u';
                    break;
                case 3:
                    pos->dir = 'r';
                    break;
            }
            break;
        }
    }
}

// finding the exit
void findExit(char array[][N], struct Position *pos) {
    pos->isEntrance = 0;
    
    int i;
    for(i=3; i>= 0;i--)
    {
        switch(i) {
            case 0:
                // finding entrance from first top row
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
        
        if(pos->isEntrance) break;
    }
    
}

void findRowEntrance(char array[][N],int row, int size, struct Position *pos) {
    int i;
    for(i=0;i<size;i++) {
     if(array[row][i] == '0')
     {
         pos->isEntrance = 1;
         pos->row = row;
         pos->column = i;
         break;
     }
    } 
}

void findColumnEntrance(char array[][N], int column, int size, struct Position *pos) 
{
    int i;
    for(i=0;i<size;i++) {
      if(array[i][column] == '0')
      {
        pos->isEntrance = 1;
        pos->row = i;
        pos->column = column;
        break;
      }
    }
}

// finding the path 
void findPath(char array[][N]) {
    struct Position currentPos,exitPos,entryPos;
    findEntrance(array, &entryPos);
    findExit(array, &exitPos);
  
    currentPos.row = entryPos.row;
    currentPos.column = entryPos.column;
    currentPos.dir = entryPos.dir;
    
    int i=0;
    while(i < 100)
    {
        if(checkRight(array,&currentPos)) {         //done
            // printf("\ncheckRight method \n");
            markVisitedPath(array,&currentPos);     //done
            turnRight(array,&currentPos);           //done      
            changeDirection(&currentPos);
        } else if(checkForward(array,&currentPos)) {//done
            // printf("\ncheckForward method \n");
            markVisitedPath(array,&currentPos);     //done
            goForward(&currentPos);                 //done    
        } else {
            // printf("\nreverseDirection method \n");
            reverseDirection(&currentPos);          //done
            continue;
        }
        
        if(isEqual(&currentPos, &entryPos)) {
            printf("No exit");
            printArray(array);
            break;
        } else if(isEqual(&currentPos, &exitPos)) {
            printf("Found exit");
            markVisitedPath(array,&currentPos);
            printArray(array);
            break;
        }  
        
        // printArray(array);
        // break;
        i++;
    }
    
    // printf("\n{ \n\tentrance: \n\t{ \n\t\trow: %d,\n\t\tcol: %d\n\t} \n}",entryPos.row,entryPos.column);
    // printf("\n");
  
    // printf("\n{ \n\tcurrent: \n\t{ \n\t\trow: %d,\n\t\tcol: %d\n\t,\n\t\tdir: %c\n\t,\n\t\tisEntrance: %d\n\t} \n}",currentPos.row,currentPos.column,currentPos.dir,currentPos.isEntrance);
    printf("currentPos column: %d row: %d",currentPos.column,currentPos.row);
    printf("\n");
  
    // printf("\n{ \n\texit: \n\t{ \n\t\trow: %d,\n\t\tcol: %d\n\t} \n}",exitPos.row,exitPos.column);
    // printf("\n");
}

void printArray(char array[][N]) {
    int i,j;
    for (i=0; i<customM; i++)
      for (j=0; j<customN; j++)  {
        if (j == 0) printf("\n");
        switch(array[i][j]) {
            case '1':
                printf("%s",KGRN);
                break;
            case '0':
                printf("%s",KWHT);
                break;
            case 'X':
                printf("%s",KBLU);
                break;
        }
        
        printf("%c  ",array[i][j]);
      }
    printf("\n");
    printf("%s",KNRM);
}

// marking the visited path
void markVisitedPath(char array[][N],struct Position *pos) {
    array[pos->row][pos->column]='X';
}

int isEqual(struct Position *pos1, struct Position *pos2) {
    return (pos1->row == pos2->row) && (pos1->column == pos2->column);
}

void reverseDirection(struct Position *pos) {
    switch(pos->dir) {
        case 'u':
            pos->dir = 'd';
            break;
        case 'd':
            pos->dir = 'u';
            break;
        case 'r':
            pos->dir = 'l';
            break;
        case 'l':
            pos->dir = 'r';
            break;    
    }
}

int checkRight(char array[][N],struct Position *pos) {
    switch(pos->dir) {
        case 'd':
            // printf("checkRight D: %c",array[pos->row][(pos->column-1)]);
            return ((array[pos->row][(pos->column-1)] == '0') || (array[pos->row][(pos->column-1)] == 'X'));
        case 'u':
            // printf("checkRight U: %c",array[pos->row][(pos->column+1)]);
            return ((array[pos->row][(pos->column+1)] == '0') || (array[pos->row][(pos->column+1)] == 'X'));
        case 'l':
            // printf("checkRight L: %c",array[(pos->row-1)][pos->column]);
            return ((array[(pos->row-1)][pos->column] == '0') || (array[(pos->row-1)][pos->column] == 'X'));
        case 'r':
            // printf("checkRight R: %c",array[(pos->row+1)][pos->column]);
            return ((array[(pos->row+1)][pos->column] == '0') || (array[(pos->row+1)][pos->column] == 'X'));
    }
}

int checkForward(char array[][N],struct Position *pos) {
    switch(pos->dir) {
        case 'd':
            // printf("checkForward D: %c",array[(pos->row+1)][pos->column]);
            return ((array[(pos->row+1)][pos->column] == '0') || (array[(pos->row+1)][pos->column] == 'X'));
        case 'u':
            // printf("checkForward U: %c",array[(pos->row-1)][pos->column]);
            return ((array[(pos->row-1)][pos->column] == '0') || (array[(pos->row-1)][pos->column] == 'X'));
        case 'l':
            // printf("checkForward L: %c",array[pos->row][(pos->column-1)]);
            return ((array[pos->row][(pos->column-1)] == '0') || (array[pos->row][(pos->column-1)] == 'X'));
        case 'r':
            // printf("checkForward R: %c",array[pos->row][(pos->column+1)]);
            return ((array[pos->row][(pos->column+1)] == '0') || (array[pos->row][(pos->column+1)] == 'X'));
    }
}

void turnRight(char array[][N],struct Position *pos) {
    switch(pos->dir) {
        case 'd':
            // printf("turnRight origin: D\n");
            goLeft(pos);
            break;
        case 'u':
            // printf("turnRight origin: U\n");
            goRigth(pos);
            break;
        case 'l':
            // printf("turnRight origin: L\n");
            goUp(pos);
            break;
        case 'r':
            // printf("turnRight origin: R\n");
            goDown(pos);
            break;
    }
}

void goRigth (struct Position *pos) {
    pos->column = (pos->column+1);
}

void goLeft (struct Position *pos) {
    // printf("goLeftBefore: %d\n",(pos->column));
    pos->column = (pos->column-1);
    // printf("goLeftAfter: %d\n",(pos->column));
}

void goUp (struct Position *pos) {
    pos->row=(pos->row-1);
}

void goDown(struct Position *pos) {
    pos->row=(pos->row+1);   
}

void changeDirection(struct Position *pos) {
    switch(pos->dir) {
        case 'd':
            pos->dir = 'l';
            break;
        case 'u':
            pos->dir = 'r';
            break;
        case 'l':
            pos->dir = 'u';
            break;
        case 'r':
            pos->dir = 'd';
            break;
    }
}

void goForward(struct Position *pos) {
    switch(pos->dir) {
        case 'd':
            goDown(pos);
            break;
        case 'u':
            goUp(pos);
            break;
        case 'l':
            goLeft(pos);
            break;
        case 'r':
            goRigth(pos);
            break;
    }
}
