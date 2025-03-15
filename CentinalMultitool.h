#ifndef CentinalMultitool_h
#define CentinalMultitool_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXINPUT 20
// Main functions for file managing
void FileHelp() {
    printf("Centinal File Multitool Commands\n");
    printf("1. help\n");
    printf("2. new\n");
}

// Inner CLI loop
void FileMultitoolLoop() {

    char input[MAXINPUT];

    while (1) {
        printf("Files> ");

        if (!fgets(input, MAXINPUT, stdin)) {
            break;
        }

        if (strcmp(input, "help")) {
            FileHelp();
        }
    }
}

#endif