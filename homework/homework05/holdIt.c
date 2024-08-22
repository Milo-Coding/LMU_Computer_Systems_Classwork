/*
 * Write a “C” program holdit.c that times you as you hold your breath. The program
 * must put out a short message that has instructions on what to do, which should
 * read something like:
 * "This program will time how long you can hold your breath. Take a deep breath,
 * then press the 'Enter' key. When you absolutely have to exhale, press the enter
 * key again. The duration will be displayed in minutes and seconds."
 * You will need to research the way the time functions work in “C”.
 */

#include <stdio.h>
#include <time.h>

void instructions() {
    printf("This program will time how long you can hold your breath. Take a \n");
    printf("deep breath, then press the 'Enter' key. When you absolutely have \n");
    printf("to exhale, press the enter key again. The duration will be displayed \n");
    printf("in minutes and seconds. \n");
}

int main(int argc, char* argv[]) {
    char temp;

    instructions();

    printf("   Take a breath and press enter/return to start the timer\n");
    fflush(stdout);
    fflush(stdin);
    temp = fgetc(stdin);
    time_t start = time(NULL);

    printf("   Press enter/return again to stop when you have to breath\n");
    fflush(stdout);
    fflush(stdin);
    temp = fgetc(stdin);
    time_t stop = time(NULL);

    int breathHeld = difftime(stop, start);

    printf("You held your breath for %d seconds\n", breathHeld);
    return 0;
}
