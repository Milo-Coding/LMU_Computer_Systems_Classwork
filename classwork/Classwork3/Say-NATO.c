#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *nato_phonetic[] = {
    "ALPHA", "BRAVO", "CHARLIE", "DELTA", "ECHO", "FOXTROT",
    "GOLF", "HOTEL", "INDIA", "JULIETT", "KILO", "LIMA",
    "MIKE", "NOVEMBER", "OSCAR", "PAPA", "QUEBEC", "ROMEO",
    "SIERRA", "TANGO", "UNIFORM", "VICTOR", "WHISKEY", "XRAY",
    "YANKEE", "ZULU"
};

void print_nato_phonetic(char letter) {
    if (isalpha((unsigned char)letter)) {
        int index = toupper((unsigned char)letter) - 'A';
        if (index >= 0 && index < 26) {
            printf("%s\n", nato_phonetic[index]);
        } else {
            printf("UNKNOWN\n");
        }
    } else {
        printf("%c\n", letter);
    }
}

int main() {
    char input[100];
    
    printf("Enter a word or phrase: ");
    fgets(input, sizeof(input), stdin);
    
    printf("\n");
    
    for (int i = 0; input[i] != '\0'; i++) {
        print_nato_phonetic(input[i]);
    }
    
    printf("\n");

    exit(0);
}