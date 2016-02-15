/* Obstacle field generator */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 12
#define N 10

#define POSSIBLE_ZEROS (N*N)*2/3

void FieldGenerator(char [][N]);
void printField(const char[][N]);

main()
{
   char field[M][N];
   int loop, loop2;

   for (loop = 0; loop < M; loop++)
      for (loop2 = 0; loop2 < N; loop2++)
         field[loop][loop2] = '1';

   FieldGenerator(field);

   printField(field);

}

void printField(const char maze[][N])
{
   int x, y;
               
   for (x = 0; x < M; x++) {
                  
      for (y = 0; y < N; y++)
         printf("%c ", maze[x][y]);

      printf("\n");
   }
}

void FieldGenerator(char maze[][N])
{
   int a, x, y, entry, exit, loop;
   
      
   srandom(time(NULL));

   do {
      entry = random() % 4;
      exit = random() % 4;  
   } while (entry == exit);

   /* Determine entry position */
      
   if (entry == 0) {
      x = 1 + random() % (M-2);    /* avoid corners */
      y = 0;
      maze[x][0] = '0';
   }
   else if (entry == 1) {
      x = 0;   
      y = 1 + random() % (N-2);
      maze[0][y] = '0';
   }
   else if (entry == 2) { 
      x = 1 + random() % (M-2);
      y = N-1;
      maze[x][y] = '0';
   }
   else {
      x = M-1;
      y = 1 + random() % (N-2);
      maze[x][y] = '0';
   }
      
   /* Determine exit location */
   
   if (exit == 0) {
      a = 1 + random() % (M-2);
      maze[a][0] = '0';
   }
   else if (exit == 1) { 
      a = 1 + random() % (N-2);
      maze[0][a] = '0';
   }
   else if (exit == 2) {
      a = 1 + random() % (M-2);
      maze[a][N-1] = '0';
   }
   else {
      a = 1 + random() % (N-2);
      maze[M-1][a] = '0';
   }

   for (loop = 1; loop < POSSIBLE_ZEROS; loop++) {   /* add zeroes */
      x = 1 + random() % (M-2);
      y = 1 + random() % (N-2);
      maze[x][y] = '0';
   }
}
