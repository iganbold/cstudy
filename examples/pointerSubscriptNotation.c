#include <stdio.h>

 

main()

{ int i, offset, b[] = {10, 20, 30, 40};

int *bPtr = b; /* set bPtr to point to array b */

 

printf("Array b printed with array subscript notation\n");

 

for (i = 0; i <= 3; i++)

printf("b[%d] = %d\n", i, b[i]);

 

printf("\nPointer/offset notation where \n"

"the pointer is the array name\n");

 

for (offset = 0; offset <= 3; offset++)

printf("*(b + %d) = %d\n", offset, *(b + offset));

 

printf("\nPointer subscript notation\n");

 

for (i = 0; i <= 3; i++)

printf("bPtr[%d] = %d\n", i, bPtr[i]);

 

printf("\nPointer/offset notation\n");

 

for (offset = 0; offset <= 3; offset++)

printf("*(bPtr + %d) = %d\n", offset, *(bPtr + offset));

 

return 0;

}