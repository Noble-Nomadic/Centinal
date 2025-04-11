#ifndef CentinalCommander_h
#define CentinalCommander_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Help() {
    printf(" ######  ######## ##    ## ######## #### ##    ##    ###    ## \n");
    printf("##    ## ##       ###   ##    ##     ##  ###   ##   ## ##   ## \n");
    printf("##       ##       ####  ##    ##     ##  ####  ##  ##   ##  ##   \n");
    printf("##       ######   ## ## ##    ##     ##  ## ## ## ##     ## ##  \n");
    printf("##       ##       ##  ####    ##     ##  ##  #### ######### ##\n");
    printf("##    ## ##       ##   ###    ##     ##  ##   ### ##     ## ##  \n");
    printf(" ######  ######## ##    ##    ##    #### ##    ## ##     ## ########\n");
    printf("\n");
    printf("V0.3.0\n");
    printf("\n");
    printf("Centinal CLI Commands\n");
    printf("1. help - display this                                              2. exit - quit the program\n");
    printf("3. files - multitool for basic file operations                      4. security - antivirus like file scanner\n");
    printf("5. system - moniter your system resource                            6. encryption - encrypt and decrypt files\n");
    printf("7. script - read a text file and execute its commands (NOT ADDED)   8. settings - configure centinal: (NOT ADDED) \n");
    printf("9. burner - read and write data to CDs\n");
}

int processCommand(char input[100]) {
    if (strcmp(input, "help") == 0) {
        Help();
    }

    else if (strcmp(input, "exit") == 0) {
        exit(0);
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

    else if (strcmp(input, "security") == 0) {
        SecurityLoop();
    }

    else if (strcmp(input, "burner") == 0) {
        BurnerLoop();
    }
    
    else {
        printf("Unknown command. Type 'help' for a list of commands.\n");
    }
}


#endif