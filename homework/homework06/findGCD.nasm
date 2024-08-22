; ----------------------------------------------------------------------------
; findGCD.nasm
;
; Win32 program to find the GCD
;
; to assemble (windows):
;  nasm -f win32 findGCD.nasm
; to link:
;  gcc -m32 findGCD.obj -o findGCD.exe
; ----------------------------------------------------------------------------

         global      _main
         extern      _printf
         extern      _scanf

         section     .text
_main:
         push        ebx               ;

getone:
         push        message1          ; ask for the first number
         call        _printf
         add         esp,  4           ;

         push        number1           ;
         push        formatin          ;
         call        _scanf            ;
         add         esp,  8           ;

gettwo:
         push        message2          ; ask for the second number
         call        _printf
         add         esp,  4           ;

         push        number2           ;
         push        formatin          ;
         call        _scanf            ;
         add         esp,  8           ;

calc:
         xor         eax,  eax         ; this is the a value (initialized at 0)
         xor         ecx,  ecx         ; this is the b value (initialized at 0)
         mov         eax,  [number1]   ;
         mov         ecx,  [number2]   ;
         cmp         eax,  ecx         ;
         je          end               ; 
         jb          swap              ;
         jmp         top               ;
swap:
         xchg        eax,  ecx         ;
top:
         xor         edx,  edx         ; use Euclid's algorithm
         idiv        ecx               ;
         test        edx,  edx         ;
         je          end
         mov         eax,  ecx         ;
         mov         ecx,  edx         ;
         jmp         top               ;

end:
         mov         eax,  ecx         ; tell the user the gcd
         push        eax               ;
         push        formatout         ;
         call        _printf           ;
         add         esp,  8           ;
         ret

         section     .data
message1:   db    "   First number: ", 0
message2:   db    "   Second number: ", 0
formatin:   db    "%d", 0
formatout:  db    0x0A, "   GCD is: %10d", 0x0A, 0

number1:    dd    0
number2:    dd    0
