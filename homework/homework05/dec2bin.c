/*
 * file: dec2bin.c
 *
 * biggest possible decimal #: 4,294,967,295
 * biggest binary #: 1111 1111 1111 1111 1111 1111 1111 1111
 */
 
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
 
void instructions() {
    printf( "\n\n   This is a decimal to binary converter program \n" );
    printf( "   It converts any posative decimal number less than or equal to 4294967295 to its binary equivolant. \n\n\n" );
}

// helper method for making dec an unsigned int
unsigned int convert(char *st) {
    char *x;
    for (x = st ; *x ; x++) {
        if (!isdigit(*x)) {
            printf("Error! Please only enter integer from 0 to 2147483647\n");
 		    exit(0);
 		}

      }
  return (strtoul(st, 0L, 10));
}

int main (int argc, char * argv[]) {
    // space for the input decimal # (max 10 digits and 0/)
    char decIn[11];
 	
 	// inital string for binary number (== 0)
    char decAsBin[] = "00000000000000000000000000000000";
    
    // dracker of the decimal value and a counter for our twos place
    unsigned int dec;
    long multipleOfTwo = 2147483648;
 	
    // ask for decimal if its not given
    if (argc < 2) {
        instructions();
        printf("   Enter a number: ");
        fflush (stdout);
        fflush(stdin);
        scanf("%s", decIn);
        
 	} else {
 		strcpy(decIn, argv[1]);
 	}
 	
 	// turn our input into a decimal number
 	dec = convert(decIn);
 	
 	
 	if (dec < 0 || dec > 4294967295) {
 		printf("Error! Please only enter integer from 0 to 2147483647\n");
 		exit(0);
 	}
 	
 	printf("   Computing your binary number... \n");
 	
 	// ten is the max length for the binary number
 	for (int powerOf2 = 31; powerOf2 >= 0; powerOf2--) {
 		if (multipleOfTwo <= dec) {
 			decAsBin[31 - powerOf2] = '1';  // add a 1 to the binary in the correct place
 			dec %= multipleOfTwo;  // remove that much from the decimal number
 		}
 		multipleOfTwo /= 2;
 	}
 	
    printf("   Your binary number is: %s\n", decAsBin);
 	 	
 	exit(0);
 }