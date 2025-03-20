#ifndef CentinalSecurity_h
#define CentinalSecurity_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

#include "CentinalLogger_h"

FILE *whiteListFile;
FILE *blackListFile;

void SecurityHelp() {
    printf("Centinal Security Commands\n");
    printf("help - display this\n");
    printf("exit - return to main CLI\n");
    printf("scana - scan a directory\n");
    printf("scanb - scan all files\n");
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

void SecurityPurgeThreat(char filePath[100]) {
    printf("Purging file\n");
    
    remove(filePath);
}
    
void SecurityThreatWhitelist(char filePath[100]) {
    printf("White listing file\n");

    char line[100];
    FILE *whiteListAppend;

    whiteListAppend = fopen("WhiteList.txt", "a");

    // Stripping newline from the file path
    filePath[strcspn(filePath, "\n")] = 0;
    fprintf(whiteListAppend, "%s\n", filePath);

    printf("Next time file is scanned, %s, won't be considered a threat\n");

    fclose(whiteListAppend);
}

void ThreatCLI(char filePath[100]) {
    printf("Centinal Threat Manager. Type 'help' for command list\n");

    while (1) {
        char input[100];

        printf("Security>Threat> ");

        if (!fgets(input, sizeof(input), stdin)) {
            return;
        }
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "help") == 0) {
            SecurityThreatHelp();
        }

        else if (strcmp(input, "exit") == 0 || strcmp(input, "ignore") == 0) {
            return;
        }

        else if (strcmp(input, "purge") == 0) {
            SecurityPurgeThreat(filePath);
        }

        else if (strcmp(input, "whitelist") == 0) {
            SecurityThreatWhitelist(filePath);
        }

        else {
            printf("Invalid command. Type 'help' for command list\n");
        }
    }
}

void ScanFile(char filePath[100]) {
    FILE *file;
    file = fopen(filePath, "r");

    char line[100];

    while (fgets(line, sizeof(line), file)) {
        fseek(blackListFile, 0, SEEK_SET);  // Reset file pointer to the beginning of blackListFile

        char blackListWord[30];

        while (fgets(blackListWord, sizeof(blackListWord), blackListFile)) {
            // Remove newline character from the blacklisted word
            blackListWord[strcspn(blackListWord, "\n")] = 0;

            if (strstr(line, blackListWord) != NULL) {
                printf("WARNING, FILE WITH BLACKLISTED WORD FOUND\n");
                printf("%s\n", filePath);
                printf("Opening Centinal threat CLI");
                ThreatCLI(filePath);
                fclose(file);
                return;
            }
        }
    }

    fclose(file);
}

void ScanDir(const char *dirPath) {
    DIR *dir = opendir(dirPath);

    if (dir == NULL) {
        printf("Error: Unable to open directory %s\n", dirPath);
        return;
    }

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char fullPath[256];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);

        struct stat path_stat;
        stat(fullPath, &path_stat);

        // If it's a file, scan it
        if (S_ISREG(path_stat.st_mode)) {
            ScanFile(fullPath); 
        }
    }

    closedir(dir);
	
	LogUpdate("scana", dirPath);
}

void ScanFull(const char *dirPath) {
    DIR *dir = opendir(dirPath);  // Open the directory

    if (dir == NULL) {
        printf("Error: Unable to open directory %s\n", dirPath);
        return;
    }

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char fullPath[256];

        snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);
        struct stat path_stat;

        stat(fullPath, &path_stat);

        if (S_ISREG(path_stat.st_mode)) {
            ScanFile(fullPath);
        }

        else if (S_ISDIR(path_stat.st_mode)) {
            ScanFull(fullPath);
        }
    }

    closedir(dir);
	
	LogUpdate("scanb");
}


void SecurityLoop() {
    char input[100];
    
    printf("Initialising security...\n");
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
        
        else if (strcmp(input, "exit") == 0) {
            // Close files before exiting
            fclose(whiteListFile);
            fclose(blackListFile);
            
            break;
        }

        else if (strcmp(input, "scana") == 0) {
			
			char directoryPath[100];
			
			if (!fgets(directoryPath, sizeof(directoryPath), stdin)) {
				return;
			}
			
            ScanDir(directoryPath);
        }

        else if (strcmp(input, "scanb") == 0) {
            ScanFull(".");
        }

        else {
            printf("Unknown command. Type 'help' for a list of commands.\n");
        }
    }
}

#endif
