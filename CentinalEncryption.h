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
        printf("Error reading input\n");
        return;
    }

    // Remove newline character if present
    fileName[strcspn(fileName, "\n")] = 0;

    // Debug: Print the entered file name
    printf("Attempting to open file: '%s'\n", fileName);

    FILE *sourceFile = fopen(fileName, "r");

    if (!sourceFile) {
        perror("Error opening file");
        return;
    }

    char encryptedFileName[100];

    printf("Enter name for encrypted file: ");
    if (!fgets(encryptedFileName, sizeof(encryptedFileName), stdin)) {
        printf("Error reading input\n");
        fclose(sourceFile);
        return;
    }

    // Remove newline character from encrypted file name
    encryptedFileName[strcspn(encryptedFileName, "\n")] = 0;

    int userKey;

    printf("Enter a key value between 1 and 10: ");
    scanf("%i", &userKey);
    getchar(); // Consume the newline character left by scanf

    // Validate key
    if (userKey < 1 || userKey > 10) {
        printf("Invalid key. Please enter a value between 1 and 10.\n");
        fclose(sourceFile);
        return;
    }

    FILE *EncryptedFile = fopen(encryptedFileName, "w");
    if (!EncryptedFile) {
        printf("Could not create encrypted file %s\n", encryptedFileName);
        fclose(sourceFile);
        return;
    }

    char currentChar = fgetc(sourceFile);
    while (currentChar != EOF) {
        int ASCIITOAPPEND = currentChar;

        // Encrypt and write to the file
        fprintf(EncryptedFile, "%i ", ASCIITOAPPEND * userKey);

        currentChar = fgetc(sourceFile);
    }

    fclose(EncryptedFile);
    fclose(sourceFile);

    printf("Encrypted file created with %i as the key\n", userKey);
}



void DecryptFile() {
    char encryptedFileName[100];

    printf("Enter encrypted file name: ");
    if (!fgets(encryptedFileName, sizeof(encryptedFileName), stdin)) {
        printf("Error reading input\n");
        return;
    }

    // Remove newline character from encrypted file name
    encryptedFileName[strcspn(encryptedFileName, "\n")] = 0;

    // Debug: Print the entered file name
    printf("Attempting to open encrypted file: '%s'\n", encryptedFileName);

    FILE *encryptedFile = fopen(encryptedFileName, "r");

    if (!encryptedFile) {
        perror("Error opening file");
        return;
    }

    char decryptedFileName[100];

    printf("Enter name for decrypted file: ");
    if (!fgets(decryptedFileName, sizeof(decryptedFileName), stdin)) {
        printf("Error reading input\n");
        fclose(encryptedFile);
        return;
    }

    // Remove newline character from decrypted file name
    decryptedFileName[strcspn(decryptedFileName, "\n")] = 0;

    int userKey;

    printf("Enter the key value used for encryption (between 1 and 100): ");
    scanf("%i", &userKey);
    getchar(); // Consume the newline character left by scanf

    // Validate key
    if (userKey < 1 || userKey > 100) {
        printf("Invalid key. Please enter a value between 1 and 100.\n");
        fclose(encryptedFile);
        return;
    }

    FILE *decryptedFile = fopen(decryptedFileName, "w");
    if (!decryptedFile) {
        printf("Could not create decrypted file %s\n", decryptedFileName);
        fclose(encryptedFile);
        return;
    }

    int encryptedValue;
    while (fscanf(encryptedFile, "%i", &encryptedValue) != EOF) {
        char decryptedChar = encryptedValue / userKey;

        // Decrypt and write to the file
        fputc(decryptedChar, decryptedFile);
    }

    fclose(decryptedFile);
    fclose(encryptedFile);

    printf("Decrypted file created with %i as the key\n", userKey);
}

void EncryptionLoop() {
    char input[100];

    while (1) {
        printf("Encryption> ");
        if (!fgets(input, sizeof(input), stdin)) {
            break;
        }

        input[strcspn(input, "\n")] = 0;  // Remove newline character

        if (strcmp(input, "help") == 0) {
            EncryptionHelp();
        }
        
        else if (strcmp(input, "exit") == 0) {
            break;
        }
        
        else if (strcmp(input, "encrypt") == 0) {
            EncryptFile();
        }

        else if (strcmp(input, "decrypt") == 0) {
            DecryptFile();
        }

        else {
            printf("Unknown command. Type 'help' for a list of commands.\n");
        }
    }
}

#endif
