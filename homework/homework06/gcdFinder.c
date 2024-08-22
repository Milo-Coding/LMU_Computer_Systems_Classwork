/*
 * gcdFinder.c
 * 
 * Call the nasm function to find the gcd
 * and check if it works
 *
 * assemble nasm function:
 *  nasm -f win32 findGCDfunc.nasm
 * compile/link program:
 *  gcc -m32 gcdFinder.c findGCDfunc.obj -o gcdFinder.exe
 */

#include <stdio.h>
#include <assert.h>

extern int gcdFinder( int x, int y );

int main() {

   int gcd = 0;
   
   // GCD of 6 and 4 is 2
   gcd = gcdFinder(6, 4);
   printf( "\n    GCD is %10d\n", gcd );
   assert(2 == gcd);
   
   // GCD of 10 and 10 is 10
   gcd = gcdFinder(10, 10);
   printf( "\n    GCD is %10d\n", gcd );
   assert(10 == gcd);
   
   // GCD of 3113041662 and 11570925 is 462837
   gcd = gcdFinder(3113041662, 11570925);
   printf( "\n    GCD is %10d\n", gcd );
   assert(462837 == gcd);
   
   // GCD of 47934255 and 0 is 1
   gcd = gcdFinder(47934255, 0);
   printf( "\n    GCD is %10d\n", gcd );
   assert(1 == gcd);
   
   // GCD of -2 and -6 is 1
   gcd = gcdFinder(-2, -6);
   printf( "\n    GCD is %10d\n", gcd );
   assert(1 == gcd);

   return 0;
}