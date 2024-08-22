/*
For the exercise, write a program called goFish.c that sums and averages a list of numbers,
then creates a string and produces a count. You must use EITHER an array, or a set of pointers
as the data storage. The program's specifications are as follows:

1. The numbers must be prompted for in a loop
2. The special value -9999 is used to indicate that the entries are complete
3. Store the values in a structure of some kind that is initially declared to be size 25 int elements
4. Loop through the structure and sum the elements, then output the sum to the console
5. Count the number of elements in the structure, and output their average to the console
6. Loop through the structure again, and contatenate all the values into a long string
7. Output the string to the console
8. Loop through the string, and count all the 7 [seven] characters; this is like in the game Go Fish when you ask another player, GIMME ALL YOUR SEVENS.
9. Output the count to the console
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY 5

int main( int argc, char * argv[] ) {

    char input[10];
    char storage[MAX_ENTRY][10];
    int values [MAX_ENTRY];
    int sum = 0;
   
    printf( "   hello, world!\n" );
   
    for( int i = 0; i < MAX_ENTRY; i++ ) {
        printf( "\n  enter an integer: " );
        fgets(input, 10, stdin);
      
        printf("%s", (strcmp(input, "-9999") == 0));
      
        if (strcmp(input, "-9999") == 0) {
            break;
        }
        values[i] = atoi(input);
      
        printf( "\n     got: %s", input );
        strcat( storage[i], input);
    }
    
    for (int i = 0; i < MAX_ENTRY; i++ ){
        if (strcmp(storage[i], "-9999") == 0) {
            break;
        }
        sum += values[i];
    }

    printf( "\n     storing: %s", storage );
    printf( "\n     total: %d", sum );
    
    exit(0);
}