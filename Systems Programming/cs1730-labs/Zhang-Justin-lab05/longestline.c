#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

    // checks for arguments
    if (argc > 2 || argc == 1) {
        printf("Too many or too few arguments.");
        exit(1);
    }
    // opens file
    FILE * filep = fopen(argv[1], "r");

    // defines needed constants
    int max = 0;
    int counter = 0;
    char currentChar;

    // while the current character is not the end of the file
    while((currentChar = fgetc(filep)) != EOF) {

        // sets the longest line to  the max counter if it is less than the current line
        if( currentChar == '\n') {
            if ( max < counter) {
                max = counter;
            } // if
            counter = 0; // resets the counter for the next line
        } else {
            counter++; // adds to the counter if not a new line character
        } // if
    } // while

    if (max < counter) { // checks the last line to set the longest line value
        max = counter;
    } // if

    printf("%d\n", max);

} // main
