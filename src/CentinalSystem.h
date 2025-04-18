#ifndef CentinalSystem_h
#define CentinalSystem_h

#include <stdio.h>
#include <stdio.h>

void SystemHelp() {
    printf("Centinal System Commands\n");
    printf("help - display this\n");
    printf("exit - return to main CLI\n");
    printf("cpu - view data about cpu usage and type\n");
    printf("ram - view data about ram usage and type\n");
    printf("disk - view data about hard drive storage\n");
    printf("sum - summarise basic data about system components and resources\n");
    printf("NOTE: In some functions you may need to press enter to continue or finish them\n");
}

void SystemCpu() {
    printf("CPU Information\n");
    system("lscpu");
	
	getchar();

    printf("Current CPU Status\n");
    system("top -n 1 -b");
}

void SystemRam() {
    printf("RAM info\n");
    system("free -h");
}

void SystemDisk() {
    printf("Disk info:\n");
    system("df -h");
}

void SystemSum() {
    printf("System summary");

    printf("\n\nCPU\n\n");
    system("top -n 1");
    getchar();

    printf("GPU\n");
    system("sudo timeout 1s intel_gpu_top");
    getchar();

    printf("RAM\n");
    system("free -h");
    getchar();

    printf("Disk\n");
    system("df -h");
    getchar();
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

        else if (strcmp(input, "ram") == 0) {
            SystemRam();
        }

        else if (strcmp(input, "disk") == 0) {
            SystemDisk();
        }

        else if (strcmp(input, "sum") == 0) {
            SystemSum();
        }

        else {
            printf("Unknown command. Type 'help' for a list of commands.\n");
        }
    }
}

#endif