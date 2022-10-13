#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // error checking
    if (argc > 2 || argc == 1) {
        printf("Too many or too few arguments. Usage: /.lastline file_name\n");
        exit(1);
    }

    // opens the file and sets the line max
    FILE * filep = fopen(argv[1], "r");
    char line[30];

    // cycles through every single line until the last one
    while(fgets(line, 100, filep) != NULL) {

    } // while

    printf(line);
} // main
