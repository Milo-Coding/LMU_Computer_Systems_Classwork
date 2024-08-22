/*
 * Write a C program wordcount.c that counts the number of words in a file of text.
 * Your program should take a file name as a command line argument. As you read the
 * file contents, keep a count of the number of words which are separated by
 * "whitespace". [Research what is meant by "whitespace" in the C environment.] When
 * the file has been completely read, close the file and write out the number of
 * words. Be sure you handle error conditions like files that don't exist or errors
 * while reading the file. You should also be able to handle files that are in
 * different directories from where your program resides
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening the file");
        return 1;
    }

    int wordCount = 0;
    int inWord = 0;
    char c;

    while ((c = fgetc(file)) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (inWord) {
                inWord = 0;
                wordCount++;
            }
        } else {
            inWord = 1;
        }
    }

    // Check for the last word
    if (inWord) {
        wordCount++;
    }

    fclose(file);

    printf("Number of words in %s: %d\n", argv[1], wordCount);

    return 0;
}