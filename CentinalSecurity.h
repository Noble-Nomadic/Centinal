#ifndef CentinalSecurity_h
#define CentinalSecurity_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
// Secondary CLI system for when blacklisted keyword is found in a file
void SecurityThreatHelp() {
	printf("Centinal Security Threat Manager Commands\n");
	printf("help - display this\n");
	printf("exit / ignore - return to scan without action\n");
	printf("purge - delete the file\n");
	printf("whitelist - add file path to whitelist, will not be scanned again\n");
}

void SecurityPurgeThreat() {
	printf("Purging file\n");
}

void ThreatCLI() {
	printf("Centinal Threat Manager. Type 'help' for command list\n");

	while (1) {
		char input[100];

		printf("Threat> ");

		if (!fgets(input, sizeof(input), stdin)) {
			return;
		}
		input[strcspn(input, "\n")] = 0;

		if (strcmp(input, "help") == 0) {
			SecurityThreatHelp();
		}
	}
}

void ScanFile(char filePath) {
	FILE *file;
	file = fopen(filePath, "r");

	char line[100]

	while (fgets(line, sizeof(line), file)) {
		for (int i = 0; i < 100; i++) {

			char[30] blackListWord;

			blackListWord = fgets(blackListWord, 100, blackListFile);

			if (strstr(line, blackListWord) != NULL) {
				printf("WARNING, FILE WITH BLACKLISTED WORD FOUND\n");
				printf("%s\n", filePath);
				printf("Opening Centinal threat CLI");
			}
		}
	}
}

void ScanDir() {

}

void ScanFull() {

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

		else if (strcmp(input, "scana")) {
			ScanDir();
		}

		else if (strcmp(input, "scanb")) {
			ScanFull();
		}

		else {
			printf("Unknown command. Type 'help' for a list of commands.\n");
		}
	}
}

#endif
