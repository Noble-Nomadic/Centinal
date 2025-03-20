#ifndef CentinalLogger_h
#define CentinalLogger_h

void LogUpdate(char stringDataA[100], char stringDataB[100], char stringDataC)[100] {
	FILE *file;
	file = fopen("CentinalLog.txt", "a");
	
	// LOGGING DATA
	// String A provides data about what command to log
	// Strings B and C is additonal information to log based on string A
	if (strcmp(stringDataA, "new") == 0) {
		fprinf("Created file %s\n", stringDataB);
	}
	
	else if (strcmp(stringDataA, "reset") == 0) {
		fprintf("Reset file &s\n", stringDataB);
	}
	
	else if (strcmp(stringDataA, "delete") == 0) {
		fprintf("Deleted file %s\n", stringDataB);
	}
	
	else if (strcmp(stringDataA, "edit") == 0) { 
		fprintf("%s, was added to %s\n", stringDataB, stringDataC);
	}
	
	else if (strcmp(stringDataA, "encrypt") == 0) {
		fprintf("Encrypted %s, as %s\n", stringDataB, stringDataC);	
	}
	
	else if (strcmp(stringDataA, "decrypt") == 0) {
		fprintf("Decrypted %s, as %s\n", stringDataB, stringDataC);
	}
	
	else if (strcmp(stringDataA, "scana") == 0) {
		fprintf("Scanned %s for threats\n", stringDataB);
	}
	
	else if (strcmp(stringDataA, "scanB") == 0) {
		fprintf("Scanned full system for threats\n");
	}
	
	fclose(file);
}

#endif