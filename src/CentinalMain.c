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

int main() {
    printf(" ######  ######## ##    ## ######## #### ##    ##    ###    ## \n");
    printf("##    ## ##       ###   ##    ##     ##  ###   ##   ## ##   ## \n");
    printf("##       ##       ####  ##    ##     ##  ####  ##  ##   ##  ##   \n");
    printf("##       ######   ## ## ##    ##     ##  ## ## ## ##     ## ##  \n");
    printf("##       ##       ##  ####    ##     ##  ##  #### ######### ##\n");
    printf("##    ## ##       ##   ###    ##     ##  ##   ### ##     ## ##  \n");
    printf(" ######  ######## ##    ##    ##    #### ##    ## ##     ## ########\n");
    printf("\n");
    printf("V0.4.0\n");

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

        processCommand(input);        
    }

    return 0;
}
