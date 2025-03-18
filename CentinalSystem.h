#ifndef CentinalSystem_h
#define CentinalSystem_h

#include <stdio.h>
#include <stdio.h>

void SystemHelp() {
    printf("Centinal System Commands\n");
    printf("help - display this\n");
    printf("exit - return to main CLI");
    printf("cpu - view data about cpu usage and type\n");
    printf("gpu - view data about gpu usage and type");
    printf("ram - view data about ram usage and type\n");
    printf("disk - view data about hard drive storage\n");
    printf("sum - summarise basic data about system components and resources\n");
}

void SystemCpu() {

}

void SystemGpu() {

}

void SystemRam() {

}

void SystemDisk() {

}

void SystemSum()


void SystemLoop() {
    while(1) {
        // Make sure to reset the command each loop
        char input[100];

        // Get commmand
        printf("System> ");

        if (!fgets(input, sizeof(input), stdin)) {
            printf("Invalid Command\n");
        }
        input[strcspn(input, "\n")] = 0;
        
        // Check through command list
        if (strcmp(input, "help") == 0) {
            SystemHelp();
        }

        else if (strcmp(input, "exit")) {
            break;
        }

        else if (strcmp(input, "cpu") == 0)
    }
}

#endif