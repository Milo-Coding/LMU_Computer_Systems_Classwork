/*
 * whichEndIsUp.c
 * determines whether this is a big-endian
 * or a little-endian computer
 *
 * compile/link program:
 *  gcc -m32 whichEndIsUp.c -o whichEndIsUp.exe
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isLittleEndian() {

  unsigned int x = 0x76543210;
  char *c = (char*)&x;
  return (*c == 0x10);

}

int main( int argc, char * argv[] ) {

   printf( "\n\n   This computer is " );
   printf( "%s", (isLittleEndian() ? "little-endian.\n\n" : "big-endian.\n\n") );

   return( 0 );

}
