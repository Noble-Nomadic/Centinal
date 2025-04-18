#ifndef CentinalScripts_h
#define CentinalScripts_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void ScriptHelp() {
    printf("Centinal script reader commands\n");
    printf("help - display this\n");
    printf("exit - return to main CLI\n");
    printf("read - execute a script\n");
}

void ExecuteLine(char line[]) {
    // Compare the current line against commands
    // Tokenise the current line and find the main word
    // After a space, the rest of the line is considered arguments
}

void ReadScript() {
    char fileName[100];
    
    printf("Enter file name: ");
    if (!fgets(fileName, sizeof(fileName), stdin)) {
        return;
    }
    fileName[strcspn(fileName, "\n")] = 0;
    
    FILE *file;
    file = fopen(fileName, "r");
    
    char line[100];
    
    while (fgets(line, sizeof(line), file) != NULL) {
        
    }

    return;
}


void ScriptLoop() {
    char input[100];

    while (1) {
        printf("Scripts> ");

        if (!fgets(input, sizeof(input), stdin)) {
            break;
        }
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "help") == 0) {
            ScriptHelp();
        }
        
        else if (strcmp(input, "exit") == 0) {
            break;
        }
        
        else if (strcmp(input, "read") == 0) {
            ReadScript();
        }
    }
    
    return;
}

#endif