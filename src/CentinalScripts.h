#ifndef CentinalScripts_h
#define CentinalScripts_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CentinalScriptFunctions.h"


void ScriptHelp() {
    printf("Centinal script reader commands\n");
    printf("help - display this\n");
    printf("exit - return to main CLI\n");
    printf("execute - execute a script\n");
}

void ExecuteLine(char line[]) {
    // Remove newline character
    line[strcspn(line, "\n")] = 0;

    char mainWord[20];
    char arg1[100];
    int lineNumber;
    char content[500];

    if (sscanf(line, "%s", mainWord) != 1) return;

    if (strcmp(mainWord, "new") == 0) {
        if (sscanf(line, "%*s %s", arg1) == 1) {
            ScriptMakeFile(arg1);
        }
    }

    else if (strcmp(mainWord, "reset") == 0) {
        if (sscanf(line, "%*s %s", arg1) == 1) {
            ScriptResetFile(arg1);
        }
    }

    else if (strcmp(mainWord, "delete") == 0) {
        if (sscanf(line, "%*s %s", arg1) == 1) {
            ScriptDeleteFile(arg1);
        }
    }

    else if (strcmp(mainWord, "edit") == 0) {
        if (sscanf(line, "%*s %s %[^\n]", arg1, content) == 2) {
            ScriptEditFile(arg1, content);
        }
    }

    else if (strcmp(mainWord, "line") == 0) {
        if (sscanf(line, "%*s %s %d %[^\n]", arg1, &lineNumber, content) == 3) {
            ScriptEditLine(arg1, lineNumber, content);
        }
    }

    else if (strcmp(mainWord, "encrypt") == 0) {
        char arg2[100];
        int key;
        if (sscanf(line, "%*s %s %s %d", arg1, arg2, &key) == 3) {
            ScriptEncrypt(arg1, arg2, key);
        }
    }

    else if (strcmp(mainWord, "decrypt") == 0) {
        char arg2[100];
        int key;
        if (sscanf(line, "%*s %s %s %d", arg1, arg2, &key) == 3) {
            ScriptDecrypt(arg1, arg2, key);
        }
    }

    else if (strcmp(mainWord, "execute") == 0) {
        if (sscanf(line, "%*s %s", arg1) == 1) {
            ScriptExecuteScript(arg1);
        }
    }
}

void ReadScript(char fileName[100]) {
    
    char line[600];
    while (fgets(line, sizeof(line), file)) {
        ExecuteLine(line);
    }

    fclose(file);
}

void ScriptLoop() {
    char input[100];

    while (1) {
        printf("Scripts> ");
        if (!fgets(input, sizeof(input), stdin)) break;
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "help") == 0) {
            ScriptHelp();
        }

        else if (strcmp(input, "exit") == 0) {
            break;
        }

        else if (strcmp(input, "execute") == 0) {
            char fileName[100];
    
            printf("Enter file name: ");
            if (!fgets(fileName, sizeof(fileName), stdin)) return;
            fileName[strcspn(fileName, "\n")] = 0;

            FILE *file = fopen(fileName, "r");
            if (!file) {
                printf("Failed to open file: %s\n", fileName);
                return;
            }

            ReadScript(fileName);
        }
    }
}

#endif
