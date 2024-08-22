; ----------------------------------------------------------------------------
; paritygen.nasm
;
; Win32 program that prints a "1" if we have odd parity and a "0" otherwise
;
; to assemble (windows):
;  nasm -f win32 paritygen.nasm
; to link:
;  gcc -m32 paritygen.obj -o paritygen.exe
; ----------------------------------------------------------------------------

         global      _main
         extern      _printf
         extern      _scanf

         section     .text

_main:
         push        ebx                  ;
         
getnumber:
         push        message              ; ask for the first number
         call        _printf
         add         esp,  4              ;

         push        number               ;
         push        formatin             ;
         call        _scanf               ;
         add         esp,  8              ;



top1:
         mov         eax,  [number]       ;
         mov         ebx,  0x00000001     ; the mask
         mov         ecx,  0x00000020     ; count all 32 bits in the byte
         xor         edx,  edx            ;
         and         eax,  ebx            ;
         cmp         eax,  0x00000000     ; see if the last bit is a 1
         jne         count                ; if so count it

top2:
         mov         eax,  [number]       ; loop for counting all the other bits
         shl         ebx,  1              ;
         and         eax,  ebx            ;
         cmp         eax,  0x00000000     ;
         jne         count                ;
         dec         ecx                  ;
         cmp         ecx,  0x00000000     ;
         jne         top2                 ;
         jmp         result               ;

count:   inc         edx                  ; keeps track of loop
         dec         ecx                  ; 
         cmp         ecx,  0x00000000     ; 
         jne         top2                 ; 

result:
         and         edx,  0x00000001     ; check if even or odd
         cmp         edx,  0x00000001     ; 
         jne         print1               ; print a '1' if even

print0:
         push        format0              ;
         call        _printf              ;
         ret                              ;
print1:
         push        format1              ;
         call        _printf              ;
         ret                              ;

         section     .data
counter: db          32                   ; for 32 bits

message:   db    "   Enter your decimal number: ", 0
formatin:   db    "%d", 0

format0: db          0xA, 0xA, '  Parity bit: 0', 0xA, 0xA, 0
format1: db          0xA, 0xA, '  Parity bit: 1', 0xA, 0xA, 0

number:    dd    0
