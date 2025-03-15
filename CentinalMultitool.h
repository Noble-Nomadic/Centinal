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
    printf("2. exit\n")
    printf("3. new\n");
    printf("4. view\n");
    printf("5. reset");
    printf("6. delete\n");
    printf("7. edit\n");
}

// New file command
void NewFile() {
    char newFileName[MAXINPUT + 20];

    printf("Enter file name \n > ");

    if (!fgets(newFileName, MAXINPUT + 20, stdin)) {
        return;
    }

    FILE *newFile;
    newFile = fopen(newFileName, "w");

    printf("File created");

    fclose();
}
// View contents of file
void ViewFile() {
    char fileName[100];

    printf("Enter file name: ");
    scanf("%s", fileName);


    FILE *file;
    file = fopen(fileName, "r");
}

// Inner CLI loop
void FileMultitoolLoop() {
    // Reset input variable each loop
    char input[MAXINPUT] = "";

    while (1) {
        printf("Files> ");

        if (!fgets(input, MAXINPUT, stdin)) {
            break;
        }

        if (strcmp(input, "help") == 0) {
            FileHelp();
        }

        else if (strcmp(input, "exit") == 0) {
            break;
        }
    }
}

#endif