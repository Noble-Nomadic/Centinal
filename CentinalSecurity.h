#ifndef CentinalSecurity_h
#define CentinalSecurity_h


FILE *whiteListFile;
FILE *blackListFile;

void SecurityHelp() {
	printf("Centinal Security Commands\n");
	printf("help - display this\n");
	printf("exit - return to main CLI\n");
	printf("scana - scan a directory\n");
	printf("scanb - scan directory including subfolders\n");
}

void SecurityInit() {
	// Open files, return if files are not found	
	whiteListFile = fopen("WhiteList.txt", "r");
	blackListFile = fopen("BlackList.txt", "r");
	
	if (whiteListFile == NULL) {
		printf("WARNING, WHITELIST NOT FOUND\n");
		return;
	}
	
	else if (blackListFile == NULL) {
		printf("WARNING, BLACKLIST NOT FOUND\n");
		return;
	}
}

void SecurityLoop() {
	char input[100];
	
	printf("Initialising security...");
	SecurityInit();
	
    while (1) {
        printf("Security> ");

        if (!fgets(input, sizeof(input), stdin)) {
            break;
        }
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "help") == 0) {
            SecurityHelp();
        }
        
        else if (strcmp(input, "exit")) {
			// Close files before exiting
			fclose(whiteListFile);
			fclose(blackListFile);
			
			break;
		}
	}
}

#endif
