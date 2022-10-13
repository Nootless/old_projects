#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main (int argc, char* argv[])
{
    // used for files
    int n;
    int bytes = 0;
    int count = 0;
    int fileDesc;
    char input [1000000];
    char output[1000000];
    char tail  [1000000];
    // int newLines = 0;
    char* ptr;

    // unbuffers standard out
    setvbuf(stdout,NULL,_IONBF,0);


    if(argc == 1) {
        while (( n = read(STDIN_FILENO, input, 4096)) != 0) {

            for (int i = 0; i < n; i++) {
                output[bytes+i] = input[i];
            } // for
            bytes += n;
        } // while

        // where to start the printing process
        int startpoint;
        // reads through the file backwards to find all the new line operators
        for(int i = bytes; i >= 0 && count < 11; i--) {
            if(output[i] == '\n') {
                count++;
            } // if
            startpoint = i;
        } // for

        for( int i = startpoint , j = 0; i < bytes; i++, j++) {
            tail[j] = output[i];

        } // for
        write(STDOUT_FILENO,tail, bytes);

        // reads through all user input until FILE_END

    } else if(strcmp("-c", argv[1]) == 0) {
        // checks to make sure that the number after the arg is a number
        if(argv[2] == NULL || strtol(argv[2], &ptr, 10) == 0) {
            perror("invalid number of bytes");
            exit(1);

        } else {
            int d;
            count = atoi(argv[2]);
            // used to print if there are multiple files

            // used for checking formatting later
            if((d = open(argv[3],O_RDONLY))) {

            } // if

            if (argc == 3) {
                while (( n = read(STDIN_FILENO, input, count)) != 0) {
                    for (int i = 0; i < n; i++) {
                        output[bytes+i] = input[i];
                    } // for
                    bytes += n;
                } // while

                // where to start the printing process
                int startpoint = bytes;
                // goes up to the count that it should be at
                for(int i = bytes; i >= (bytes - count); i--) {
                    startpoint = i;
                } // for

                for( int i = startpoint , j = 0; i < bytes; i++, j++) {
                    tail[j] = output[i];

                } // for
                write(STDOUT_FILENO,tail, bytes);
            } else {

                // loops through all arguments
                for (int i = 3; i < argc; i++) {
                    if (strcmp(argv[i],"-") == 0) {
                        argv[i] = "standard output"; // replaces standard arg
                    } // if
                    if (i == 3 && argc > 4) { // sets up the printing in case of multiple files
                        printf("==> %s <==\n", argv[i]);
                    } else if (i >= 4 && argc > 4 && d == -1) {
                        printf("==> %s <==\n", argv[i]);
                        d = 0;
                    } else if (i >= 4 && argc > 4) {
                        printf("\n==> %s <==\n", argv[i]);
                    } // if

                    // standard input case
                    if (strcmp(argv[i], "standard output") == 0) {
                        bytes = 0;
                        while (( n = read(STDIN_FILENO, input, count)) != 0) {
                            for (int i = 0; i < n; i++) {
                                output[bytes+i] = input[i];
                            } // for
                            bytes += n;
                        } // while

                        // where to start the printing process
                        int startpoint = bytes;
                        // goes up to the count that it should be at
                        for(int i = bytes, j = 0; i >= (bytes - count) && j <= bytes ; i--, j++) {
                            startpoint = i;
                        } // for

                        for( int i = startpoint , j = 0; i < bytes; i++, j++) {
                            tail[j] = output[i];

                        } // for
                        write(STDOUT_FILENO,tail, bytes);

                        // file case
                    } else if((fileDesc = open(argv[i], O_RDONLY)) == -1) {
                        perror(argv[i]); // error handling
                    } else {

                        if((bytes = read(fileDesc, output, 4096)) == -1) {
                            perror("read");
                        } // if
                        int startpoint;
                        // goes up to the count that it should be at
                        for(int i = bytes; i >= (bytes - count); i--) {
                            startpoint = i;
                        } // for

                        for( int i = startpoint , j = 0; i < bytes; i++, j++) {
                            tail[j] = output[i];

                        } // for
                        write(STDOUT_FILENO,tail, (bytes - count));
                    } // if
                } // for
            } // if
        } // if

    } else if (strcmp("-n",argv[1]) == 0) {
        int d;
        if(argv[3] != NULL) {
            d = open(argv[3],O_RDONLY); // used for formatting
        } // if

        // exits if no argument 2 or cannot convert the int
        if (argv[2] == NULL || (strtol(argv[2],& ptr, 10) == 0)) {
            perror("invalid number of new lines");
            exit(1);
        } // if
        if (argc == 3) {
            while (( n = read(STDIN_FILENO, input, 4096)) != 0) {

                for (int i = 0; i < n; i++) {
                    output[bytes+i] = input[i];
                } // for
                bytes += n;
            } // while

            // where to start the printing process
            int startpoint;
            // reads through the file backwards to find all the new line operators
            for(int i = bytes; i >= 0 && count < atoi(argv[2]) + 1; i--) {
                if(output[i] == '\n') {
                    count++;
                } // if
                startpoint = i;
            } // for

            for( int i = startpoint , j = 0; i < bytes; i++, j++) {
                tail[j] = output[i];

            } // for
            write(STDOUT_FILENO,tail, bytes);

            // reads through all user input until FILE_END

        } else {
            for (int i = 3; i < argc; i++) {
                count = 0;
                if (strcmp(argv[i],"-") == 0) {
                    argv[i] = "standard ouput"; // replaces standard arg
                } // if
                if (i == 3 && argc > 4) { // sets up the printing in case of multiple files
                    printf("==> %s <==\n", argv[i]);
                } else if (i >= 4 && argc > 4 && d == -1) {
                    printf("==> %s <==\n", argv[i]);
                    d = 0;
                } else if (i >= 4 && argc > 4) {
                    printf("\n==> %s <==\n", argv[i]);
                } // if

                if (strcmp(argv[i],"standard ouput") == 0) {
                    bytes = 0;

                    while (( n = read(STDIN_FILENO, input, 4096)) != 0) {
                        for (int i = 0; i < n; i++) {
                            output[bytes+i] = input[i];
                        } // for
                        bytes += n;
                    } // while

                    // where to start the printing process
                    int startpoint;
                    // reads through the file backwards to find all the new line operators
                    for(int i = bytes; i >= 0 && count < atoi(argv[2]) + 1; i--) {
                        if(output[i] == '\n') {
                            count++;
                        } // if
                        startpoint = i;
                    } // for

                    for( int i = startpoint , j = 0; i < bytes; i++, j++) {
                        tail[j] = output[i];

                    } // for
                    write(STDOUT_FILENO,tail, bytes);

                    // reads through all user input until FILE_END

                } else if ((fileDesc = open(argv[i], O_RDONLY)) == -1) {
                    perror(argv[i]);
                } else {

                    if((bytes = read(fileDesc, output, 100000)) == -1) {
                        perror("read");
                    } // if
                    int startpoint;
                    // goes up to the count that it should be at
                    for(int i = bytes; i >= 0 && count < atoi(argv[2]) + 1; i--) {
                        if(output[i] == '\n') {
                            count++;
                        } // if
                        startpoint = i;
                    } // for

                    for( int i = startpoint , j = 0; i < bytes; i++, j++) {
                        tail[j] = output[i];
                    } // for

                    write(STDOUT_FILENO,tail, (bytes));
                } // if
            } // for
        } // if
    } else {
        int d;

        for (int i = 1; i < argc; i++) {
            bytes = 0;
            if (strcmp(argv[i],"-") == 0) {
                argv[i] = "standard output"; // replaces standard arg
            } // if
            if (i == 1 && argc > 2) { // sets up the printing in case of multiple files
                printf("==> %s <==\n", argv[i]);
            } else if (i >= 2 && argc > 2 && d == -1) {
                printf("==> %s <==\n", argv[i]);
                d = 0;
                } else if (i >= 2 && argc > 2) {
                printf("\n==> %s <==\n", argv[i]);
            } // if

            if (strcmp(argv[i], "standard output") == 0) {
                while (( n = read(STDIN_FILENO, input, 4096)) != 0) {
                    count = 0;
                    for (int i = 0; i < n; i++) {
                        output[bytes+i] = input[i];
                    } // for
                    bytes += n;
                } // while

                // where to start the printing process
                int startpoint;
                // reads through the file backwards to find all the new line operators

                for(int i = bytes; i >= 0 && count < 11; i--) {
                    if(output[i] == '\n') {
                        count++;
                    } // if
                    startpoint = i;
                } // for

                for( int i = startpoint , j = 0; i < bytes; i++, j++) {
                    tail[j] = output[i];

                } // for
                write(STDOUT_FILENO,tail, bytes);

                // reads through all user input until FILE_END


            } else {
                if ( ((fileDesc = open(argv[i], O_RDONLY))) == -1) {
                    perror(argv[i]);
                } else {
                    if(argv[2] != NULL) {
                        d = open(argv[2],O_RDONLY);
                    } // if

                    if((bytes = read(fileDesc, output, 1000)) == -1) {
                        perror("read");
                    } // if
                 int startpoint;
                 // goes up to the count that it should be at
                 for(int i = bytes; i >= 0 && count < 11; i--) {
                     if(output[i] == '\n') {
                         count++;
                     } // if
                     startpoint = i;
                 } // for

                 for( int i = startpoint + 1 , j = 0; i < bytes; i++, j++) {
                     tail[j] = output[i];

                 } // for
                 write(STDOUT_FILENO,tail, (bytes));
                } // if
            } // if
        } // for
    } // if
} // main
