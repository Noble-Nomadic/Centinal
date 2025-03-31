#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "CentinalMultitool.h"
#include "CentinalSecurity.h"
#include "CentinalEncryption.h"
#include "CentinalSystem.h"
#include "CentinalCommander.h"


int main() {

    printf(" ________  _______   ________   _________  ___  ________   ________  ___  \n");
    printf("|\   ____\|\  ___ \ |\   ___  \|\___   ___\\  \|\   ___  \|\   __  \|\  \ \n");
    printf("\ \  \___|\ \   __/|\ \  \\ \  \|___ \  \_\ \  \ \  \\ \  \ \  \|\  \ \  \  \n");
    printf(" \ \  \    \ \  \_|/_\ \  \\ \  \   \ \  \ \ \  \ \  \\ \  \ \   __  \ \  \ \n");
    printf("  \ \  \____\ \  \_|\ \ \  \\ \  \   \ \  \ \ \  \ \  \\ \  \ \  \ \  \ \  \____\n");
    printf("   \ \_______\ \_______\ \__\\ \__\   \ \__\ \ \__\ \__\\ \__\ \__\ \__\ \_______\\n");
    printf("    \|_______|\|_______|\|__| \|__|    \|__|  \|__|\|__| \|__|\|__|\|__|\|_______|\n");
    printf("\n");

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