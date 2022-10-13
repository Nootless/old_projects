#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * Removes files recursively, takes in mode for recursion
 */
void removeRecurse(char argv[], int mode) {
    // directory
    DIR *dp;
    struct dirent * dirp;
    // arrays to store files
    struct stat s;
    char input[4096];
    char previousPath[strlen(argv)];
    char currentPass[strlen(argv)];
    // assigns strings
    strcpy(previousPath, argv);
    strcpy(currentPass,argv);
    int n;

    // checks if it is a directory
    stat(previousPath,&s);

    if (( n = rmdir(previousPath)) == -1 && (s.st_mode & S_IFDIR)) {
        // while directory has files/directories
        dp = opendir(argv);
        while ((dirp = readdir(dp)) != NULL) {
            // ensures that the previous/ current directory isn't considered
            if (strcmp("..", dirp->d_name) != 0 && strcmp(".", dirp->d_name) != 0) {
                // adds a / if a directory
                if(currentPass[strlen(currentPass)] != '/'){
                    strcat(currentPass, "/");
                } // if
                // recursion
                strcat(currentPass,dirp->d_name);
                removeRecurse(currentPass, mode);
                strcpy(currentPass,previousPath); // will reset the path
            } // if

        } // while

        rmdir(currentPass); // removes parent directory

    } else if (s.st_mode & S_IFREG && mode == 0) {
        // prompts user if the file has write protection

        if (( n = open(argv, O_WRONLY)) == -1) {
            perror("Are you sure you want to delete this write protected file [y/n]?");
            read(0, input, 4096);
            if (strcmp(input, "y") == 10) {
                if (unlink(argv) == -1) {
                    perror("Error");
                } // if
            } // if
        } else {
            unlink(argv);
        } // if

        // runs if is forced
    } else if (mode == 1) {
        if(( n = open(argv, O_WRONLY)) == -1) {


            if (unlink(argv) == -1) {
                perror("Error");
            } // if
        } else
            unlink(argv);
    } // if
} // removeRecurse



int main(int argc, char * argv[])
{
    //int n;
    //int fileDesc;
    char input [4096];

    // checks for proper use
    if (argc == 1) {
        printf("Usage: ./rm [-rf] file...\n");
        exit(1);
    } // if

    if (strcmp(argv[1], "-rf") == 0 || (strcmp(argv[1], "-fr") == 0)) { // recursive force
        for (int i = 2; i < argc; i++) {
            removeRecurse(argv[i], 1);
        } // for

    } else if (strcmp(argv[1], "-r") == 0) { // recursive
        for (int i = 2; i < argc; i++) {
            removeRecurse(argv[i], 0);
        } // for
    } else if (strcmp(argv[1], "-f") == 0) { // force
        for (int i = 2; i < argc; i++) {

            if (opendir(argv[i]) == NULL) { // checks if it is a directory

                if (unlink(argv[i]) == -1) { // checks for failure in unlinking
                    perror("Error: ");
                } // if

            } else { // runs if it is a directory
                if (rmdir(argv[i]) == -1) {
                    perror("Error: ");
                } // if
            } // if
        } // for

    } else { // default case

        for (int i = 1; i < argc; i++) {

            if (opendir(argv[i]) != NULL) { // checks if it is a directory
                if (rmdir(argv[i]) == -1) { // removes folder
                    perror("Error");
                } // if

            } else {
                if ( open(argv[i],O_WRONLY) == 0) {
                    // checks for failure in write permission
                    perror("Are you sure you want to delete this write protected file [y/n]?");
                    read(0, input, 4096);
                    if (strcmp(input, "y") == 0) {
                        if (unlink(argv[i]) == -1) perror("Error");
                    } // if
                } else {
                    if (unlink(argv[i]) == -1) perror("Error");
                } // if

            } // if
        } // for

    } // if

    exit(0);
} // main
