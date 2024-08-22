/*
 * testMakeNBOC.c
 *
 * tests the code for makeNBOC
 *
 * compile/link program:
 *  gcc -m32 testMakeNBOC.c makeNBOC.c -o makeNBOC.exe
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <inttypes.h>

bool machineIsLittleEndian();
uint64_t makeBigEndian32( uint64_t number );
uint64_t makeBigEndian64( uint64_t number );

int main( int argc, char * argv[] ) {

   uint64_t input = 0;

   if( argc < 2 ) {
      printf( "\n\n   USAGE: makeNBO <unsigned_integer_number>\n   Please try again.\n\n" );
      return -1;
   } else {
      input = strtoull( argv[1], NULL, 10 );
      if( input <= 4294967295 ) {
         if( machineIsLittleEndian() ) {
            printf( "\n\n   This computer is little-endian.\n" );
            printf( "   Network byte order for %llu [0x%16llx] is %llu [0x%16llx]\n\n",
                     input, input, makeBigEndian32(input), makeBigEndian32(input) );
         } else {
            printf( "\n\n   This computer is big-endian.\n" );
            printf( "   Network byte order for %llu [0x%16llx] is %llu [0x%16llx]\n\n",
                     input, input, input, input );
         }
      } else {
         uint64_t input64 = strtoull( argv[1], NULL, 10 );
         if( machineIsLittleEndian() ) {
            printf( "\n\n   This computer is little-endian.\n" );
            printf( "   Network byte order for %llu [0x%16llx] is %llu [0x%16llx]\n\n",
                     input64, input64, makeBigEndian64(input64), makeBigEndian64(input64) );
         } else {
            printf( "\n\n   This computer is big-endian.\n" );
            printf( "   Network byte order for %llu [0x%16llx] is %llu [0x%16llx]\n\n",
                     input64, input64, input64, input64 );
         }
      }
   }

   return( 0 );

}