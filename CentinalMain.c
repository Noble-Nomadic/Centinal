#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXINPUT 20

void Help() {
    printf("Centinal CLI Commands\n");
    printf("1. Help\n");
}


int main() {
    printf("Centinal CLI - Type 'help' for help.\n");

    char input[MAXINPUT];
    
    // Main CLI loop
    while(1) {
        // Get commmand
        printf("> ");
        if (!fgets(input, MAX_INPUT, stdin)) {
            break;
        }
        input[strcspn(input, "\n")] = 0;

        if(strcmp(input, "help")) {
            Help();
        }
    }
}