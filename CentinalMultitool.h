#ifndef CentinalMultitool_h
#define CentinalMultitool_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXINPUT 20
// Main functions for file managing
void FileHelp() {
    printf("Centinal File Multitool Commands\n");
    printf("1. help - show this\n");
    printf("2. exit - return to main CLI\n");
    printf("3. new - create new file\n");
    printf("4. view - view contents of file\n");
    printf("5. reset - reset data of a file\n");
    printf("6. delete - delete a file\n");
    printf("7. edit - append data to a file\n");
}

// New file command
void NewFile() {
    char newFileName[MAXINPUT + 20];

    printf("Enter file name \n > ");

    if (!fgets(newFileName, sizeof(newFileName), stdin)) {
        return;
    }
    newFileName[strcspn(newFileName, "\n")] = 0;

    FILE *newFile = fopen(newFileName, "w");
    if (newFile == NULL) {
        printf("Error: Could not create file %s\n", newFileName);
        return;
    }

    printf("File created\n");
    fclose(newFile);
}

// View contents of file
void ViewFile() {
    char fileName[100];

    printf("Enter file name: ");

    if (!fgets(fileName, sizeof(fileName), stdin)) {
        return;
    }
    fileName[strcspn(fileName, "\n")] = 0;

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", fileName);
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    printf("\n");

    fclose(file);
}
// Keep file but remove all contents
void ResetFile() {
    char fileName[100];

    printf("Enter file name: ");

    // Get file name
    if (!fgets(fileName, sizeof(fileName), stdin)) {
        return;
    }

    FILE *file;

    // Confirm file deletion
    printf("WARNING YOU ARE ABOUT TO RESET %s\n", fileName);
    printf("Type 'confim' to procede: ");

    char confirmReset[10];
    if (!fgets(confirmReset, sizeof(confirmReset), stdin)) {
        return;
    }
    input[strcspn(input, "\n")] = 0;

    // Confirm user wants to reset data
    if (strcmp(confirmReset, "confirm") != 0) {
        printf("Operation cancelled\n");
        return;
    }
    input[strcspn(input, "\n")] = 0;
    
    file = fopen(fileName, "w");
    fclose(file);

    printf("Data of %i reset\n", fileName);
}
// Remove file function. Deletes a file specified
void DeleteFile() {
    char fileName[100];

    printf("Enter file name: ");

    // Get the file name
    if (!fgets(fileName, sizeof(fileName), stdin)) {
        return;
    }
    input[strcspn(input, "\n")] = 0;

    // Confirm user wants to delete this file
    char confirmDelete[10];

    printf("WARNING YOU ARE ABOUT TO DELETE %s\n", fileName);
    printf("Type 'confirm' to procede: ");

    if (!fgets(confirmDelete, sizeof(confirmDelete), stdin)) {
        return;
    }

    if (strcmp(confirmDelete, "confim") != 0) {
        printf("Operation cancelled\n");
        return;
    }

    // User has confirmed file deletion
    remove(fileName);
    printf("Removed %s\n", fileName);
}


// Inner CLI loop
void FileMultitoolLoop() {
    char input[MAXINPUT];

    while (1) {
        printf("Files> ");

        if (!fgets(input, MAXINPUT, stdin)) {
            break;
        }
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "help") == 0) {
            FileHelp();
        }
        
        else if (strcmp(input, "exit") == 0) {
            break;
        }
        
        else if (strcmp(input, "new") == 0) {
            NewFile();
        }
        
        else if (strcmp(input, "view") == 0) {
            ViewFile();
        }

        else if (strcmp(input, "reset")) {
            ResetFile();
        }

        else if (strcmp(input, "delete")) {
            DeleteFile();
        }
    }
}

#endif
