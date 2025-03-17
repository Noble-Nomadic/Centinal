#ifndef CentinalEncryption_h
#define CentinalEncryption_h

#include <stdio.h>
#include <string.h>

void EncryptionHelp() {
    printf("Centinal Encryption Commands\n");
    printf("help - show this\n");
    printf("exit - return to main CLI\n");
    printf("encrypt - encrypt a file\n");
    printf("decrypt - decrypt a file\n");
}

void EncryptFile() {
    char fileName[100];

    printf("Enter file name: ");
    if (!fgets(fileName, sizeof(fileName), stdin)) {
        return;
    }

    FILE *sourceFile = fopen(fileName, "r");

    if (!sourceFile) {
        printf("Could not open file %s\n", fileName);
        return;
    }

    char encryptedFileName[100];

    printf("Enter name for encrypted file: ");
    if (!fgets(encryptedFileName, sizeof(encryptedFileName), stdin)) {
        return;
    }

    encryptedFileName[strcspn(encryptedFileName, "\n")] = 0;

    int userKey;

    printf("Enter a key value between 1 and 10: ");
    scanf("%i", &userKey);
    
    getchar();

    FILE *EncryptedFile = fopen(encryptedFileName, "w");
    if (!EncryptedFile) {
        printf("Could not create encrypted file %s\n", encryptedFileName);
        fclose(sourceFile);
        
        return;
    }

    char currentChar = fgetc(sourceFile);
    while (currentChar != EOF) {
        int ASCIITOAPPEND = currentChar;

        fprintf(EncryptedFile, "%i ", ASCIITOAPPEND * userKey);

        currentChar = fgetc(sourceFile);
    }

    fclose(EncryptedFile);
    fclose(sourceFile);

    printf("Encrypted file with %i as the key\n", userKey);
}

void EncryptionLoop() {
    char input[100];

    while (1) {
        printf("Encryption> ");
        if (!fgets(input, sizeof(input), stdin)) {
            break;
        }

        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "help") == 0) {
            EncryptionHelp();
        }
        
        else if (strcmp(input, "exit") == 0) {
            break;
        }
        
        else if (strcmp(input, "encrypt") == 0) {
            EncryptFile();
        }
    }
}

#endif
