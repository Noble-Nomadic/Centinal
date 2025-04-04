#ifndef CentinalScriptFunctions_h
#define CentinalScriptFunctions_h

void ScriptMakeFile(char fileName[]) {
    FILE *file;
    file = fopen(fileName, "w");
    
    fclose(file);
}

void ScriptResetFile(char fileName[]) {
    FILE *file;
    file = fopen(fileName, "w");

    fclose(file);
}

void ScriptDelteFile(char fileName[]) {
    remove(fileName);
}

void ScriptEditFile(char fileName[], char content[]) {
    FILE *file;
    file = fopen(fileName, "a");
    
    fprintf(file, content);
    
    fclose(file);
}

void ScriptEditLine(const char *fileName, int lineNumber, const char *newLineData) {
    char tempFileName[] = "temp.txt";

    FILE *file;
    file = fopen(fileName, "r");

    FILE *tempFile;
    tempFile = fopen(tempFileName, "w");

    int currentLine = 0;
    char line[100];

    while (fgets(line, sizeof(line), file)) {
        currentLine++;
        
        if (currentLine == lineNumber) {
            fprintf(tempFile, "%s\n", newLineData);
        } 
        
        else {
            fprintf(tempFile, "%s", line);
        }
    }

    if (currentLine < lineNumber) {
        fprintf(tempFile, "%s\n", newLineData);
    }

    fclose(file);
    fclose(tempFile);
}

#endif