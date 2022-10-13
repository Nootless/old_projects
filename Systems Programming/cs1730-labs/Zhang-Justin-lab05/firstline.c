#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

    // checks for valid arguments
    if (argc > 2 || argc == 1) {
        printf("Too many or too few arguments.\n");
        exit(1);
    }

    // opens file and sets character limit
    FILE * filep = fopen(argv[1],"r");
    char line[30];

    // gets the first line until the /n operator and prints it
    fgets(line, 100, filep);
    printf(line);


} // main
