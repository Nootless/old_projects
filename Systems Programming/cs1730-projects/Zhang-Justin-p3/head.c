#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main (int argc, char* argv[])
{

    int n = -2;
    int fileDesc;
    char input[4096];
    char *ptr;
    int count;

    // unbuffers standard out
    setvbuf(stdout,NULL,_IONBF,0);

    if(argc == 1) {
        // reads standard input if the user specifies NO arguments
        for (int i = 0; i < 10 && n != 0; i++) { // reads the input and stores
            n = read(STDIN_FILENO, input, 1096);
            if (write(STDOUT_FILENO, input, n) != n) { // writes to screen
                perror("write error"); // error if the bytes written don't equal the bytes stored
            } // if
        } // for

        if (n == -1) perror("read");
        // if given byte size

    } else if (strcmp("-c", argv[1]) == 0) {
        if (argv[2] == NULL || (strtol(argv[2],& ptr, 10) == 0)) {
            perror("invalid number of bytes");
            exit(1);
        } else {
            count = atoi(argv[2]);

            int d;
            if((argv[3] != NULL)) {
                d = open(argv[3], O_RDONLY);
            } // if
            if (argc == 3) {
                while(count > 0 && (n = read(STDIN_FILENO, input, count)) != 0) {
                    // reads the input and stores
                    count -= n; // subtracts how many chararcters left
                    if (write(STDOUT_FILENO, input, n)!= n) { // writes to screen
                        perror("write error");
                        // error if the bytes written don't equal the bytes stored
                    } // if
                } // while
                if (n == -1) perror("read");

            } else {
                for(int i = 3; i < argc; i++) {

                    // checks for standard output request by caller
                    if (strcmp(argv[i],"-") == 0) {
                        argv[i] = "standard output"; // replaces standard arg
                    } // if
                    if ( ((fileDesc = open(argv[i], O_RDONLY))) != -1 ||
                           strcmp(argv[i], "standard output") == 0) {
                        if (i == 3 && argc > 4) {
                            printf("==> %s <==\n", argv[i]);
                        } else if (i >= 4 && argc > 4 && d == -1) {
                            printf("==> %s <==\n", argv[i]);
                            d = 0;
                        } else if (i >= 4 && argc > 4) {
                            printf("\n==> %s <==\n", argv[i]);
                        } // if
                    } else {
                        count = atoi(argv[2]);
                        if(strcmp(argv[i],"standard output") == 0) {

                            while(count > 0 && (n = read(STDIN_FILENO, input, count)) != 0) {
                                // reads the input and stores
                                count -= n; // subtracts how many chararcters left
                                if (write(STDOUT_FILENO, input, n)!= n) { // writes to screen
                                    perror("write error");
                                    // error if the bytes written don't equal the bytes stored
                                } // if
                            } // while
                            if (n == -1) perror("read");
                        } else if ((fileDesc = open(argv[i], O_RDONLY)) == -1) {
                            // gets file and writes it out
                            perror(argv[i]);
                        } else {
                            // loops thorugh the arguments

                            read(fileDesc, input, count); // reads file
                            if (write(STDOUT_FILENO,input, count) != count) {
                                // writes out the output
                                perror("write error");
                            } // if
                        } // if
                    } // for
                } // if
            } // if
        }
    } else if(strcmp("-n", argv[1]) == 0) {

        int d;
        if(argv[3] != NULL) {
            d = open(argv[3],O_RDONLY); // used to check for formatting later
        } // if
        // loops through all arguments

        if (argv[2] == NULL || (strtol(argv[2],& ptr, 10) == 0)) {
            perror("invalid number of bytes");
            exit(1);
        } // if

        if (argc == 3) {
            for(int i = 0; i < atoi(argv[2]) && n != -1; i++) {
                if((n = read(STDIN_FILENO, input, 4096)) == -1) {
                    i = atoi(argv[2]) + 3;
                } // if
                // reads the input and stores
                if (write(STDOUT_FILENO, input, n)!= n) { // writes to screen
                    perror("write error");
                    // error if the bytes written don't equal the bytes stored
                } // if
            } // for
        } else  {
            for (int i = 3; i < argc; i++) {

                // output for multiple files
                if (strcmp(argv[i], "-")) {
                    argv[i] = "standard output";
                } // if
                if (i == 3 && argc > 4) {
                    printf("==> %s <==\n", argv[i]);
                } else if (i >= 4 && argc > 4 && d == -1) {
                    printf("==> %s <==\n", argv[i]);
                    d = 0;
                } else if (i >= 4 && argc > 4) {
                    printf("\n==> %s <==\n", argv[i]);
                } // if

            if (strcmp(argv[i], "standard output") == 0) {
                for(int i = 0; i < atoi(argv[2]); i++) {
                    n = read(STDIN_FILENO, input, 4096);
                    // reads the input and stores
                    if (write(STDOUT_FILENO, input, n)!= n) { // writes to screen
                        perror("write error");
                        // error if the bytes written don't equal the bytes stored
                    } // if
                } // for

            } else if ( ((fileDesc = open(argv[i], O_RDONLY))) == -1) {
                perror(argv[i]);
            } else {
                n = read(fileDesc,input, 4096); // opens the file
                int c;
                // checks for 2 conditions
                // counter reaches end of file
                // goes through the pre-determined amount of lines
                for( int j = 0, counter = 0; (j < atoi(argv[2])) && (counter <= n); counter++ ) {
                    if (input[counter] == '\n') {
                            j++; // adds for each new line
                    } // if
                    c = counter + 1;
                } // for
                int result; // stores errors

                if(strcmp(argv[i],"standard output") == 0) {
                    for(int i = 0; i < 10 && n != -1; i++) {
                            n = read(STDIN_FILENO, input, 4096);
                            // reads the input and stores
                            if (write(STDOUT_FILENO, input, n)!= n) { // writes to screen
                                perror("write error");
                                // error if the bytes written don't equal the bytes stored
                            } // if
                    } // for

                    // prints out or error
                    } else if ((result = write(STDOUT_FILENO,input, c)) != c) {
                        perror("write error");
                    } // if
                } // if
            } // for
        } // if
    } else {
        int d;
        if(argv[2] != NULL) {
            d = open(argv[2],O_RDONLY);
        } // if

         // loops through all arguments
         for (int i = 1; i < argc; i++) {

            if (strcmp(argv[i],"-") == 0) {
                // checks through and sets up multiple file
                // printing
                argv[i] = "standard output";
            } // if
            if ((fileDesc = open(argv[i], O_RDONLY)) != -1 ||
                 strcmp("standard output", argv[i]) == 0) {

                if (i == 1 && argc > 2) {
                    printf("==> %s <==\n", argv[i]);
                } else if (i >= 2 && argc > 2 && d == -1) {
                    printf("==> %s <==\n", argv[i]);
                    d = 0;
                } else if (i >= 2 && argc > 2) {
                    printf("\n==> %s <==\n", argv[i]);
                } // if
            }
            // reads standard input if the user specifies NO arguments
            if (strcmp(argv[i],"standard output") == 0) {
                for (int i = 0; i < 10 && n != 0; i++) { // reads the input and stores
                    n = read(STDIN_FILENO, input, 1096);
                    if (write(STDOUT_FILENO, input, n) != n) { // writes to screen
                        perror("write error");
                        // error if the bytes written don't equal the bytes stored
                    } // if
                } // for
                if (n == -1) perror("read");

            } else if ( ((fileDesc = open(argv[i], O_RDONLY))) == -1) {
                perror(argv[i]);
            } else {

                n = read(fileDesc,input, 4096);

                // checks for either 10 lines or end of file
                int c;
                for(int j = 0, counter = 0; (j < 10) && (counter <= n); counter++ ) {
                    if (input[counter] == '\n') {
                        j++;
                    } // if
                    c = counter + 1;
                } // for
                int result; // stores errors

                if(strcmp(argv[i],"standard output") == 0) {
                    for(int i = 0; i < 10; i++) {
                        n = read(STDIN_FILENO, input, 4096);
                        // reads the input and stores
                        if (write(STDOUT_FILENO, input, n)!= n) { // writes to screen
                            perror("write error");
                            // error if the bytes written don't equal the bytes stored
                        } // if
                    } // for

                    // prints out or error
                } else if ((result = write(STDOUT_FILENO,input, c)) != c) {
                    perror("write error");
                } // if

            } // else
        } // else
    } // for
} // main
