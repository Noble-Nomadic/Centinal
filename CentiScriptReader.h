#ifndef CentiScriptReader_h
#define CentiScriptReader_h

#include <stdio.h>

void ReadScript() {
    char fileName[100];

    if (!fgets(fileName, sizeof(fileName), stdin)) {
        return;
    }

    FILE *file;
    file = fopen("r");

    fclose(file);
}

#endif