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

        currentChar = fgetc(outFile);
    }

    fclose(inFile);
    fclose(outFile);
}

void ScriptDecrypt(char inFileName[], char outFileName[], int key) {
    FILE *inFile;
    FILE *outFile;
	
	inFile = fopen(inFileName, "r");
	outFile = fopen(outFileName, "w");
	
	
	int encryptedValue;
    while (fscanf(inFile, "%i", &encryptedValue) != EOF) {
        char decryptedChar = encryptedValue / userKey;

        // Decrypt and write to the file
        fputc(decryptedChar, decryptedFile);
    }

    fclose(decryptedFile);
    fclose(encryptedFile);
}

#endif