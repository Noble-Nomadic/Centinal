#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "CentinalMultitool.h"
#include "CentinalSecurity.h"
#include "CentinalEncryption.h"
#include "CentinalSystem.h"
#include "CentinalScripts.h"
#include "CentinalScriptFunctions.h"
#include "CentinalBurner.h"
#include "CentinalCommander.h"

int main(int argc, char *argv[]) {
    
    if (argc == 1) { // No command-line arguments
        printf(" ######  ######## ##    ## ######## #### ##    ##    ###    ## \n");
        printf("##    ## ##       ###   ##    ##     ##  ###   ##   ## ##   ## \n");
        printf("##       ##       ####  ##    ##     ##  ####  ##  ##   ##  ##   \n");
        printf("##       ######   ## ## ##    ##     ##  ## ## ## ##     ## ##  \n");
        printf("##       ##       ##  ####    ##     ##  ##  #### ######### ##\n");
        printf("##    ## ##       ##   ###    ##     ##  ##   ### ##     ## ##  \n");
        printf(" ######  ######## ##    ##    ##    #### ##    ## ##     ## ########\n");
        printf("\n");
        printf("V1.0.0\n");

        printf("Centinal CLI - Type 'help' for help.\n");
        
        // Main CLI loop
        while (1) {
            // Make sure to reset the command each loop
            char input[100];

            // Get command
            printf("> ");

            if (!fgets(input, sizeof(input), stdin)) {
                printf("Invalid Command\n");
            }
            input[strcspn(input, "\n")] = 0;

            processCommand(input);        
        }
    } else { // Command-line arguments provided
        // Combine all arguments into a single command string
        char command[256] = {0};

        for (int i = 1; i < argc; i++) {

            strcat(command, argv[i]);
            if (i < argc - 1) {
                strcat(command, " ");
            }
        }

        // Parse the input to ExecuteLine()
        printf("Executing command: %s\n", command);
        ExecuteLine(command);
    }

    return 0;
}