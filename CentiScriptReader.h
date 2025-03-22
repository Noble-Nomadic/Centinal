#ifndef CentiScriptReader_h
#define CentiScriptReader_h

#include <stdio.h>
#include <string.h>

#include "CentinalCommander.h"


void ReadScriptLine(char line[100]) {

}

void ReadScript() {
    char fileName[100];

    if (!fgets(fileName, sizeof(fileName), stdin)) {
        return;
    }

    FILE *file;
    file = fopen(fileName, "r");
    
    char line[100];

    while (fgets(line, sizeof(line), file) != NULL) {
        ReadScriptLine(line);
    }

    fclose(file);
}

#endif