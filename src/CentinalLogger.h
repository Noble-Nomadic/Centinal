#ifndef CentinalLogger_h
#define CentinalLogger_h

void LogUpdate(char stringDataA[], const char stringDataB[], char stringDataC[], int integerData) {
	FILE *file;
	file = fopen("CentinalLog.txt", "a");
	
	// LOGGING DATA
	// String A provides data about what command to log
	// Strings B and C is additonal information to log based on string A
	if (strcmp(stringDataA, "new") == 0) {
		fprintf(file, "Created file %s\n", stringDataB);
	}
	
	else if (strcmp(stringDataA, "reset") == 0) {
		fprintf(file, "Reset file %s\n", stringDataB);
	}
	
	else if (strcmp(stringDataA, "delete") == 0) {
		fprintf(file, "Deleted file %s\n", stringDataB);
	}
	
	else if (strcmp(stringDataA, "edit") == 0) { 
		fprintf(file, "%s, was added to %s\n", stringDataC, stringDataB);
	}
	
	else if (strcmp(stringDataA, "line") == 0) {
		fprintf(file, "Line %i was set to %s", integerData, stringDataB);
	}
	
	else if (strcmp(stringDataA, "encrypt") == 0) {
		fprintf(file, "Encrypted %s, as %s\n", stringDataB, stringDataC);	
	}
	
	else if (strcmp(stringDataA, "decrypt") == 0) {
		fprintf(file, "Decrypted %s, as %s\n", stringDataB, stringDataC);
	}
	
	else if (strcmp(stringDataA, "scana") == 0) {
		fprintf(file, "Scanned %s for threats\n", stringDataB);
	}
	
	else if (strcmp(stringDataA, "scanB") == 0) {
		fprintf(file, "Scanned full system for threats\n");
	}

	else if (strcmp(stringDataA, "threat") == 0) {
		fprintf(file, "Threat detected in %s", stringDataB);
	}
	
	fclose(file);
}

#endif
