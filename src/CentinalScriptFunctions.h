#ifndef CentinalScriptFunctions_h
#define CentinalScriptFunctions_h

void ScriptMakeFile(char fileName[]) {
    FILE *file;
    file = fopen(fileName, "w");
    
    fclose(file);

    return;
}

void ScriptResetFile(char fileName[]) {
    FILE *file;
    file = fopen(fileName, "w");

    fclose(file);

    return;
}

void ScriptDeleteFile(char fileName[]) {
    remove(fileName);
    return;
}

void ScriptEditFile(char fileName[], char content[]) {
    FILE *file;
    file = fopen(fileName, "a");
    
    fprintf(file, content);
    
    fclose(file);

    return;
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

    return;
}

void ScriptEncrypt(char inFileName[], char outFileName[], int key) {
    FILE *inFile;
    FILE *outFile;

    inFile = fopen(inFileName, "r");
    outFile = fopen(outFileName, "w");

    char currentChar = fgetc(inFile);

    while (currentChar != EOF) {
        int ASCIITOAPPEND = currentChar;

        // Encrypt and write to the file
        fprintf(outFile, "%i ", ASCIITOAPPEND * key);

        currentChar = fgetc(inFile);
    }

    fclose(inFile);
    fclose(outFile);

    return;
}

void ScriptDecrypt(char inFileName[], char outFileName[], int key) {
    FILE *inFile;
    FILE *outFile;
	
	inFile = fopen(inFileName, "r");
	outFile = fopen(outFileName, "w");
	
	
	int encryptedValue;

    while (fscanf(inFile, "%i", &encryptedValue) != EOF) {
        // Decrypt the current ASCII data and append it to the file
        char decryptedChar = encryptedValue / key;
        fputc(decryptedChar, outFile);
    }

    fclose(decryptedFile);
    fclose(encryptedFile);

    return;
}

#endif