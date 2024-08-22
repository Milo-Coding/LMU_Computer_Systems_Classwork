; ----------------------------------------------------------------------------
; findGCDfunc.nasm
;
; Win32 function to find the GCD when called by gcdFinder.c
;
; to assemble (windows):
;  nasm -f win32 findGCDfunc.nasm
; to link for win32:
;  see gcdFinder.c
; ----------------------------------------------------------------------------

         global      _gcdFinder

         section     .text

_gcdFinder:
filetop:
         push        ebp               ;
         mov         ebp,  esp         ;

getnums:
         mov         eax,  [ebp+8]     ; get first number (arg 2)
         mov         ecx,  edx         ; get second number (arg 3)

calc:
         cmp         eax,  ecx         ;
         je          end               ;
         jb          swap              ; 
         jmp         top               ;
swap:
         xchg        eax,  ecx         ;
top:
         xor         edx,  edx         ; 
         idiv        ecx               ;
         test        edx,  edx         ;
         je          end
         mov         eax,  ecx         ;
         mov         ecx,  edx         ;
         jmp         top               ; 

end:
         mov         eax,  ecx         ;
         mov         esp,  ebp         ;
         pop         ebp               ;
         ret
