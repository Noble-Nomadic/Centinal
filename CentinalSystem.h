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
    printf("CPU Hardware:\n");
    system("lscpu");

    printf("Current CPU data:\n");
    system("top -n 1");
}

void SystemGpu() {
    printf("GPU info:\n");
    system("sudo timeout 1s intel_gpu_top");
}

void SystemRam() {
    printf("RAM info");
    system("free -h");
}

void SystemDisk() {
    printf("Disk info:\n");
    system("df -h");
}

void SystemSum() {
    printf("System summary");

    printf("CPU\n");
    system("top -n 1");

    printf("GPU\n");
    system("sudo timeout 1s intel_gpu_top");

    printf("RAM\n");
    system("free -h");

    printf("Disk\n");
    system("df -h");
}


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

        else if (strcmp(input, "exit") == 0) {
            break;
        }

        else if (strcmp(input, "cpu") == 0) {
            SystemCpu();
        }

        else if (strcmp(input, "gpu") == 0) {
            SystemGpu();
        }

        else if (strcmp(input, "ram") == 0) {
            SystemRam();
        }

        else if (strcmp(input, "disk") == 0) {
            SystemDisk();
        }

        else if (strcmp(input, "sum" == 0)) {
            SystemSum();
        }
    }
}

#endif