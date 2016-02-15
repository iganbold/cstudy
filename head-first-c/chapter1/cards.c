/*
*   My first c program
*
*/

#include <stdlib.h>
#include <stdio.h>

int main() {
    char card_name[3];
    int count=0;
    
    while(card_name[0] != 'X')
    {
        puts("Enter the card name: ");
        scanf("%2s", card_name);    //scans only the first 2 chars
        int val = 0;
        
        // switch statement checkes single value
        switch(card_name[0]) {
            case 'K':
            case 'Q':
            case 'J':
                val = 10;
                break;
            case 'X':
                puts("Bye Bye");
                continue;
            case 'A':
                val = 11;
                break;
            default :
                val = atoi(card_name);  // atoi coverts string to integer
                if( (val < 0) || (val > 10))
                {
                    puts("Please eneter valide input");
                    continue;
                }
        }
        
        if((val >= 3) && (val <= 6)) {
            count++;
        } else if( val == 10) {
            count--;
        }
        
        printf ("The current count is: %i\n",count);
    }
    return 0;
}