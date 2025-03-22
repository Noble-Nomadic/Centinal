#ifndef CentinalCommander_h
#define CentinalCommander_h

void Help() {
    printf("Centinal CLI Commands\n");
    printf("1. help - display this\n");
    printf("2. exit - quit the program\n");
    printf("3. files - multitool for basic file operations\n");
    printf("4. security - antivirus scanning\n");
    printf("5. system - moniter your system resource\n");
    printf("6. encryption - encrypt and decrypt files\n");
    printf("7. units - compress data in unit memory files\n");
	printf("8. script - read a txt file containing commands\n");
}

int processCommand(char input[100]) {
    if (strcmp(input, "help") == 0) {
        Help();
    }

    else if (strcmp(input, "exit") == 0) {
        break;
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
    
    else {
        printf("Unknown command. Type 'help' for a list of commands.\n");
    }
}


#endif