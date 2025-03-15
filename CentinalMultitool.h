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
    printf("2. exit\n");
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

    fclose(newFile);
}
// View contents of file
void ViewFile() {
    char fileName[100];

    printf("Enter file name: ");

    if (!fgets(newFileName, MAXINPUT + 20, stdin)) {
        return;
    }
    newFileName[strcspn(newFileName, "\n")] = 0


    FILE *file;
    file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Error: Could not open file %s\n", fileName);
        return;
    }
    // Add code for reading the file

    fclose(file);
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
        input[strcspn(input, "\n")] = 0; 

        if (strcmp(input, "help") == 0) {
            FileHelp();
        }

        else if (strcmp(input, "exit" == 0) == 0) {
            break;
        }
    }
}

#endif