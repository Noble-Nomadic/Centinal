#ifndef CentinalMultitool_h
#define CentinalMultitool_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXINPUT 20

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

void ResetFile() {
    char fileName[100];

    printf("Enter file name: ");

    if (!fgets(fileName, sizeof(fileName), stdin)) {
        return;
    }
    fileName[strcspn(fileName, "\n")] = 0;

    printf("WARNING YOU ARE ABOUT TO RESET %s\n", fileName);
    printf("Type 'confirm' to proceed: ");

    char confirmReset[10];
    if (!fgets(confirmReset, sizeof(confirmReset), stdin)) {
        return;
    }
    confirmReset[strcspn(confirmReset, "\n")] = 0;

    if (strcmp(confirmReset, "confirm") != 0) {
        printf("Operation cancelled\n");
        return;
    }

    FILE *file = fopen(fileName, "w");
    if (file) {
        fclose(file);
        printf("Data of %s reset\n", fileName);
    } else {
        printf("Error: Could not reset file %s\n", fileName);
    }
}

void DeleteFile() {
    char fileName[100];

    printf("Enter file name: ");

    if (!fgets(fileName, sizeof(fileName), stdin)) {
        return;
    }
    fileName[strcspn(fileName, "\n")] = 0;

    printf("WARNING YOU ARE ABOUT TO DELETE %s\n", fileName);
    printf("Type 'confirm' to proceed: ");

    char confirmDelete[10];
    if (!fgets(confirmDelete, sizeof(confirmDelete), stdin)) {
        return;
    }
    confirmDelete[strcspn(confirmDelete, "\n")] = 0;

    if (strcmp(confirmDelete, "confirm") != 0) {
        printf("Operation cancelled\n");
        return;
    }

    if (remove(fileName) == 0) {
        printf("Removed %s\n", fileName);
    } else {
        printf("Error: Could not delete file %s\n", fileName);
    }
}

void EditFile() {
    char fileName[100];

    printf("Enter file name: ");

    if (!fgets(fileName, sizeof(fileName), stdin)) {
        return;
    }
    fileName[strcspn(fileName, "\n")] = 0;

    FILE *file;
    file = fopen(fileName, "a");

    while (1) {
        char lineToAdd[100];

        printf("Enter line to add, type END to quit: ");
        
        if (!fgets(lineToAdd, sizeof(lineToAdd), stdin)) {
            return;
        }
        lineToAdd[strcspn(lineToAdd, "\n")] = 0;

        if (strcmp(lineToAdd, "END") == 0) {
            break;
        }

        fprintf(lineToAdd);
    }

    printf("Updated %s\n", fileName);
    fclose(file);
}


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
        
        else if (strcmp(input, "reset") == 0) {
            ResetFile();
        }
        
        else if (strcmp(input, "delete") == 0) {
            DeleteFile();
        }

        else if (strcmp(input, "edit") == 0) {
            EditFile();
        }
    }
}

#endif
