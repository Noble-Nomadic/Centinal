#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "CentinalMultitool.h"
#include "CentinalSecurity.h"
#include "CentinalEncryption.h"
#include "CentinalSystem.h"


void Help() {
    printf("Centinal CLI Commands\n");
    printf("1. help - display this\n");
    printf("2. exit - quit the program\n");
    printf("3. files - multitool for basic file operations\n");
    printf("4. security - antivirus scanning\n");
    printf("5. system - moniter your system resource\n");
    printf("6. encryption - encrypt and decrypt files\n");
    printf("7. units - store data in unit memory files\n");
}


int main() {
    printf("Centinal CLI - Type 'help' for help.\n");
    
    // Main CLI loop
    while(1) {
        // Make sure to reset the command each loop
        char input[100];

        // Get commmand
        printf("> ");

        if (!fgets(input, sizeof(input), stdin)) {
            printf("Invalid Command\n");
        }
        input[strcspn(input, "\n")] = 0;
        
        // Check through command list
        if (strcmp(input, "help") == 0) {
            Help();
        }

        else if (strcmp(input, "exit") == 0) {
            break;
        }

        else if (strcmp(input, "files") == 0) {
            FileMultitoolLoop();
        }

        else if (strcmp(input, "system") == 0) {
            SystemLoop();
        }

        else if (strcmp(input, "encryption") == 0) {
            EncryptionLoop();
        }

        else if (strcmp(input, "security" == 0)) {
            SecurityLoop();
        }
        
        else {
            printf("Unknown command. Type 'help' for a list of commands.\n");
        }
    }

    return 0;
}