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
    printf("2. files\n");
    printf("3. security\n");
    printf("4. system\n");
    printf("5. encryption\n");

}


int main() {
    printf("Centinal CLI - Type 'help' for help.\n");

    char input[MAXINPUT];
    
    // Main CLI loop
    while(1) {
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

        else if (strcmp(input, "files") == 0) {
            FileMultitoolLoop();
        }
    }
}