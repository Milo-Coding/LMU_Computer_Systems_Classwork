/*
 * Write a “C” program timesTables.cto output the times tables from 2 to N,
 * where N is a user-defined number take from the command line. Output the values
 * in a nice table, using a format specifier that will allow for enough space for
 * the results to be neatly aligned in columns.
 *
 * Limited N to 25 for readability
 */
 
 
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
 
void instructions() {
    printf( "\n   Takes a number between 2 - 25 and returns it's times table from 2 - N.\n\n" );
}

int main (int argc, char * argv[]) {
    // space for the input # (max 2 digits and 0/)
    char numStr[3];
    int num;
 	
    // ask for decimal if its not given
    if (argc < 2) {
        instructions();
        printf("   Enter a number: ");
        fflush (stdout);
        fflush(stdin);
        scanf("%s", numStr);
        
 	} else {
 		strcpy(numStr, argv[1]);
 	}
 	num = atoi(numStr);
 	
 	if (num < 2 || num > 25) {
 		printf("Error! Please only enter integers from 2 to 25\n");
 		exit(0);
 	}
 	
 	printf("Here your times table: \n");
 	
 	// print times table using a nested loop
 	for (int i = 2; i <= num; i++) {
 		for (int j = 2; j <= num; j++) {
 			printf("\t%d", i * j);  // using tabs for line spacing
 		}
 		printf("\n\n");
 	}
 	 	
 	exit(0);
 }