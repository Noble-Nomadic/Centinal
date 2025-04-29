#ifndef CentinalEncryption_h
#define CentinalEncryption_h

#include <stdio.h>
#include <string.h>

#include "CentinalLogger.h"

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

    FILE *sourceFile = fopen(fileName, "rb"); // Open in binary mode
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

    printf("Enter a key value between 1 and 100: ");
    scanf("%i", &userKey);
    getchar(); // Consume the newline character left by scanf

    // Validate key
    if (userKey < 1 || userKey > 100) {
        printf("Invalid key. Please enter a value between 1 and 100.\n");
        fclose(sourceFile);
        return;
    }

    FILE *EncryptedFile = fopen(encryptedFileName, "wb"); // Open in binary mode
    if (!EncryptedFile) {
        printf("Could not create encrypted file %s\n", encryptedFileName);
        fclose(sourceFile);
        return;
    }

    unsigned char buffer[1024];
    size_t bytesRead;

    // Read file in chunks and encrypt
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= userKey; // XOR encryption
        }
        fwrite(buffer, 1, bytesRead, EncryptedFile); // Write encrypted data
    }

    fclose(EncryptedFile);
    fclose(sourceFile);

    LogUpdate("encrypt", fileName, encryptedFileName, 0);

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

    FILE *encryptedFile = fopen(encryptedFileName, "rb"); // Open in binary mode
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

    FILE *decryptedFile = fopen(decryptedFileName, "wb"); // Open in binary mode
    if (!decryptedFile) {
        printf("Could not create decrypted file %s\n", decryptedFileName);
        fclose(encryptedFile);
        return;
    }

    unsigned char buffer[1024];
    size_t bytesRead;

    // Read file in chunks and decrypt
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), encryptedFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= userKey; // XOR decryption
        }
        fwrite(buffer, 1, bytesRead, decryptedFile); // Write decrypted data
    }

    fclose(decryptedFile);
    fclose(encryptedFile);

    LogUpdate("decrypt", encryptedFileName, decryptedFileName, 0);

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
