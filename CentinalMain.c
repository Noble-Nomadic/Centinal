#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "CentinalMultitool.h"
#include "CentinalSecurity.h"
#include "CentinalEncryption.h"
#include "CentinalSystem.h"

#define MAXINPUT 20

void Help() {
    printf("Centinal CLI Commands\n");
    printf("1. help\n");
    printf("2. exit");
    printf("3. files\n");
    printf("4. security\n");
    printf("5. system\n");
    printf("6. encryption\n");

}


int main() {
    printf("Centinal CLI - Type 'help' for help.\n");
    
    // Main CLI loop
    while(1) {
        // Make sure to reset the command each loop
        char input[MAXINPUT] = "";

        // Get commmand
        printf("> ");
        if (!fgets(input, MAXINPUT, stdin)) {
            break;
        }
        input[strcspn(input, "\n")] = 0;
        
        // Check through command list
        if (strcmp(input, "help") == 0) {
            Help();
        }

        else if (strcmp(input, "exit")) {
            break;
        }

        else if (strcmp(input, "files") == 0) {
            FileMultitoolLoop();
        }
    }

    return 0;
}