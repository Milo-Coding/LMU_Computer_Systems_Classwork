#include <stdio.h>
#include <stdlib.h>

// says hello <name> to the user
int main( int argc, char * argv[] ) {
    
    // take the user input using scanf
    char input[25];
    printf("Enter Your name: ");
    scanf("%s", input);
	
    // say hello the user
    printf("\n   Hello %s! \n ", input);
	
    // quits the program
    exit(0);  
}