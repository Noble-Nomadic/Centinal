#ifndef CentinalMultitool_h
#define CentinalMultitool_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "CentinalLogger.h"

void FileHelp() {
    printf("Centinal File Multitool Commands\n");
    printf("1. help - show this\n");
    printf("2. exit - return to main CLI\n");
    printf("3. new - create new file\n");
    printf("4. view - view contents of file\n");
    printf("5. reset - reset data of a file\n");
    printf("6. delete - delete a file\n");
    printf("7. edit - append data to a file\n");
    printf("8. line - edit a specific line of a file\n");
}

void NewFile() {
    char newFileName[100];

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
    
    LogUpdate("new", newFileName, "blank", 0);
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
    }
    
    else {
        printf("Error: Could not reset file %s\n", fileName);
    }
    
    LogUpdate("reset", fileName, "blank", 0);
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
    }
    
    else {
        printf("Error: Could not delete file %s\n", fileName);
    }
    
    LogUpdate("delete", fileName, "blank", 0);
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

        strcat(lineToAdd, "\n");
        fprintf(file, "%s", lineToAdd);
        
        LogUpdate("edit", fileName, lineToAdd, 0);
    }

    printf("Updated %s\n", fileName);
    fclose(file);
}

void EditLine() {
    char fileName[100];
    char tempFileName[] = "temp.txt";  // Temporary file name

    // Get file name
    printf("Enter filename: ");
    if (!fgets(fileName, sizeof(fileName), stdin)) {
        printf("Error reading the filename.\n");
        return;
    }

    // Remove the newline character if it exists
    fileName[strcspn(fileName, "\n")] = 0;

    // Print the file name for debugging purposes
    printf("File name entered: %s\n", fileName);

    // Open the original file for reading
    FILE *file = fopen(fileName, "r");
    if (!file) {
        printf("Error: Could not open file '%s'. Please check the file path or permissions.\n", fileName);
        return;
    }

    // Open a temporary file for writing
    FILE *tempFile = fopen(tempFileName, "w");
    if (!tempFile) {
        printf("Error: Could not open temporary file '%s' for writing.\n", tempFileName);
        fclose(file);
        return;
    }

    // Get line number and new line data from user
    int lineNumber;
    printf("Enter line number to edit: ");
    if (scanf("%d", &lineNumber) != 1) {
        printf("Invalid line number.\n");
        fclose(file);
        fclose(tempFile);
        return;
    }
    getchar();  // To consume the newline character left by scanf

    char newLineData[100];
    printf("Enter new data for the line: ");
    if (!fgets(newLineData, sizeof(newLineData), stdin)) {
        printf("Error reading new line data.\n");
        fclose(file);
        fclose(tempFile);
        return;
    }
    newLineData[strcspn(newLineData, "\n")] = 0;  // Remove newline from new data

    // Iterate through the original file and copy contents to temporary file
    int currentLine = 0;
    char line[100];

    while (fgets(line, sizeof(line), file)) {
        currentLine++;

        if (currentLine == lineNumber) {
            // Write the modified line to the temporary file
            fprintf(tempFile, "%s\n", newLineData);
        } else {
            // Write the original line to the temporary file
            fprintf(tempFile, "%s", line);
        }
    }

    // If line number exceeds the number of lines, append the new data
    if (currentLine < lineNumber) {
        fprintf(tempFile, "%s\n", newLineData);
    }

    // Close both files
    fclose(file);
    fclose(tempFile);

    // Replace the original file with the modified one
    if (remove(fileName) != 0) {
        printf("Error: Failed to delete the original file '%s'.\n", fileName);
        return;
    }

    if (rename(tempFileName, fileName) != 0) {
        printf("Error: Failed to rename temporary file to '%s'.\n", fileName);
        return;
    }

    printf("Line %d has been successfully modified.\n", lineNumber);
    
    LogUpdate("line", newLineData, "blank", lineNumber);
}

void FileMultitoolLoop() {
    char input[100];

    while (1) {
        printf("Files> ");

        if (!fgets(input, sizeof(input), stdin)) {
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

        else if (strcmp(input, "line") == 0) {
            EditLine();
        }

        else {
            printf("Unknown command. Type 'help' for a list of commands.\n");
        }
    }
}

#endif
