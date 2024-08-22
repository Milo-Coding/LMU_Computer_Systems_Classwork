/*
 * file: dec2bin.c
 *
 * biggest possible decimal (32) #: 4,294,967,295
 * biggest hex (32) #: FFFFFFFF
 * biggest possible decimal (64) #: 18,446,744,073,709,551,616
 * biggest hex (32) #: FFFFFFFFFFFFFFFF
 */
 
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
 
void instructions() {
    printf( "\n\n   This is a decimal to hexidecimal converter program \n" );
    printf( "   It converts any posative decimal number less than or equal to 4294967295 to its hexidecimal equivolant. \n\n\n" );
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
    // inital string for the hex numver (also == 0)
    char decAsHex[] = "00000000";
    
    // dracker of the decimal value and a counter for our twos place
    unsigned int dec;
    long multipleOfTwo = 2147483648;
    
    // the number of bits we want represented
    char bits[] = "32";
 	
    // ask for decimal if its not given
    if (argc < 3) {
        instructions();
        printf("   Enter a number: ");
        fflush (stdout);
        fflush(stdin);
        scanf("%s", decIn);
        printf("   would you like 32 or 64 bits?: ");
        fflush (stdout);
        fflush(stdin);
        scanf("%s", bits);
        
 	} else if (argc < 2) {
        instructions();
        printf("   Enter a number: ");
        fflush (stdout);
        fflush(stdin);
        scanf("%s", decIn);
        strcpy(bits, argv[2]);
        
 	} else {
 		strcpy(decIn, argv[1]);
 		strcpy(bits, argv[2]);
 	}
 	
 	// turn our input into a decimal number
 	dec = convert(decIn);
 	
 	
 	if (dec < 0 || dec > 4294967295) {
 		printf("Error! Please only enter integer from 0 to 2147483647\n");
 		exit(0);
 	}
 	
 	if ((strcmp(bits, "32") != 0) && (strcmp(bits, "64") != 0)) {
 		printf("Error! Please only pick 32 or 64 bits\n");
 		exit(0);
 	}
 	
 	printf("   Computing your hexidecimal number... \n");
 	
 	// ten is the max length for the binary number
 	for (int powerOf2 = 31; powerOf2 >= 0; powerOf2--) {
 		if (multipleOfTwo <= dec) {
 			decAsBin[31 - powerOf2] = '1';  // add a 1 to the binary in the correct place
 			dec %= multipleOfTwo;  // remove that much from the decimal number
 		}
 		multipleOfTwo /= 2;
 	}
 	
 	/*
 	 * after we have our binary number, convert it to hex
 	 * do this by looping through the binary number and adding
 	 * its value to the corrosponding spot in the hex number
 	 */
 	int binaryIndex;
 	for (int hexDigit = 0; hexDigit < 8; hexDigit++) {
 		// for each hex digit
 		for (int binDigit = 3; binDigit >= 0; binDigit--) {
 			// for each group of 4 bits
 			// get the current bits index
 			binaryIndex = 4 * hexDigit + (3 - binDigit);
 			// add that bit's value to the hex digit
			if (decAsBin[binaryIndex] == '1') {
				// should add 1 for each on bit				
 				decAsHex[hexDigit] += pow(2, binDigit);
 				// account for ASCII offset of characters by shifting digits > 9
 				if (decAsHex[hexDigit] == ':') {
 					decAsHex[hexDigit] = 'A';
 				} else if (decAsHex[hexDigit] == ';') {
 					decAsHex[hexDigit] = 'B';
 				} else if (decAsHex[hexDigit] == '<') {
 					decAsHex[hexDigit] = 'C';
 				} else if (decAsHex[hexDigit] == '=') {
 					decAsHex[hexDigit] = 'D';
 				} else if (decAsHex[hexDigit] == '>') {
 					decAsHex[hexDigit] = 'E';
 				} else if (decAsHex[hexDigit] == '?') {
 					decAsHex[hexDigit] = 'F';
 				} 
 			}
 		}
 	}	
 	
    if (strcmp(bits, "32") == 0) {
    	printf("   Your hexidecimal number is: 0x%s\n", decAsHex);	
    } else {
    	// can't handle input numbers greater than 4294967295 = 0x00000000FFFFFFFF
    	printf("   Your hexidecimal number is: 0x00000000%s\n", decAsHex);	
    }
 	exit(0);
 }