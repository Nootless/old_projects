#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

int main (int argc, char* argv[])
{
    int newLines = 0;
    int words = 0;
    int bytes = 0;
    int totalNL = 0;
    int totalBytes = 0;
    int totalWords = 0;

    // bools for specific flags
    int nl = 0;
    int bt = 0;
    int wd = 0;
    // file reading
    int n;
    int fileDesc;
    char input[1024];
    char str[1024];
    setvbuf(stdout,NULL,_IONBF,0);

    // no argument specified
    if (argc == 1) {
        while((n = read(STDIN_FILENO, input, 1024)) > 0) {
            bytes += n;

            // adds to new line
            for (int i = 0; i < bytes; i++) {
                if(input[i] == '\n') {
                    newLines++;
                } // if
            } // for

            // finds amount of words
            for(int i = 0; i <= bytes; i++) {
                if((isspace(input[i])) &&
                   (input[i - 1] >= 33 && input[i - 1] <= 135)) {
                    words++;
                } // if
            } // for
        } // while

        sprintf(str, "\t%d\t %d\t %d\n", newLines, words, bytes);
        if (write(STDOUT_FILENO, str, 18) != 18) {
            perror("write");
        } // if

        // checks for parameters
    } else if (strstr(argv[1],"-c") != NULL ||
        strstr(argv[1],"-w") != NULL ||
        strstr(argv[1],"-l") != NULL) {

        // checks for  what param
        if (strstr(argv[1],"c") != NULL) {
            bt = 1;
        } // if
        if (strstr(argv[1],"l") != NULL) {
            nl = 1;
        } // if
        if (strstr(argv[1],"w") != NULL) {
            wd = 1;
        } // if
    } // if
    // checks for parameters and sets them as 1 if they are used


    if ( nl == 1 || bt == 1 || wd == 1 ) {
        for (int i = 2; i < argc; i++) {

            bytes = 0; // resets conditions
            newLines = 0;
            words = 0;

            // standard output
            if (strcmp(argv[i], "-") == 0) {
                while((n = read(STDIN_FILENO, input, 1024)) > 0) {
                       bytes += n;
                       totalBytes = bytes + totalBytes;
                       // adds to new line
                       for (int i = 0; i < bytes; i++) {
                           if(input[i] == '\n') {
                               newLines++;
                               totalNL = newLines + totalNL;
                           } // if
                       } // for

                       // finds amount of words
                       for(int i = 0; i <= bytes; i++) {
                           if((isspace(input[i])) &&
                              (input[i - 1] >= 33 && input[i - 1] <= 135)) {
                               words++;
                               totalWords = words + totalWords;
                           } // if
                       } // for
                } // while
            } else if ((fileDesc = open(argv[i], O_RDONLY)) == -1) {
                perror(argv[i]);
            } else {
                n = read(fileDesc, input, 4096);

                // goes through list of params
                if (nl == 1) {
                    for ( int j = 1; j < n; j++) {
                        if(input[j] == '\n') {
                            newLines++;
                        } // if
                    } // for
                    totalNL = totalNL + newLines;
                    printf(" %d ", newLines);
                } // if

                if (wd == 1) {
                    for ( int k = 0; k <= n; k++) {
                        if((isspace(input[k])) &&
                        (input[k - 1] >= 33 && input[k - 1] <= 135)) {
                            words++;
                        } // if
                    } // for

                    totalWords = totalWords + words;
                    printf(" %d ", words);
                } // if

                if (bt == 1) {
                    printf(" %d ", n);
                    totalBytes = totalBytes + n;
                } // if

                printf("%s\n", argv[i]);
                newLines = 0;
                words = 0;
            } // if
        } // for

        // prints total if arg greater than 3
        if (argc > 3) {
            if (nl == 1) {
                printf(" %d ", totalNL);
            } // if
            if (wd == 1) {
                printf(" %d ", totalWords);
            } // if
            if (bt == 1) {
                printf(" %d ", totalBytes);
            } // if
            printf("total\n");
        } // if


    } else if (argc > 1) {

        for (int i = 1; i < argc; i++) {
            // open and read file into input
            if(strcmp(argv[i], "-") == 0) {
                while((n = read(STDIN_FILENO, input, 1024)) > 0) {
                       bytes += n;

                       // adds to new line
                       for (int i = 0; i < bytes; i++) {
                           if(input[i] == '\n') {
                               newLines++;
                           } // if
                       } // for

                       // finds amount of words
                       for(int i = 0; i <= bytes; i++) {
                           if((isspace(input[i])) &&
                           (input[i - 1] >= 33 && input[i - 1] <= 135)) {
                               words++;
                           } // if
                       } // for
                } // while
                totalNL = newLines + totalNL;
                totalWords = words + totalWords;
                totalBytes = bytes + totalBytes;

                printf("%d %d %d %s\n", newLines, words, bytes, argv[i]);
                newLines = 0;
                words = 0;
                // reset words and new line

            } else if((fileDesc = open(argv[i], O_RDONLY)) == -1) {
                perror(argv[i]);

            } else {
                // reads through and checks for new line
                n = read(fileDesc, input, 4096);
                for ( int j = 1; j < n; j++) {
                    if(input[j] == '\n') {
                        newLines++;
                    } // if
                } // for

                for ( int k = 0; k <= n; k++) {
                    if((isspace(input[k])) &&
                       (input[k - 1] >= 33 && input[k - 1] <= 135)) {
                        words++;
                    } // if
                } // for


                totalNL = newLines + totalNL;
                totalWords = words + totalWords;
                totalBytes = n + totalBytes;

                printf("%d %d %d %s\n", newLines, words, n, argv[i]);
                newLines = 0;
                words = 0;
            } // if
        } // for
        if (argc > 2) {
            printf("%d %d %d %s\n",
                   totalNL, totalWords, totalBytes,"total");
        } // if

    } // if
} // main
