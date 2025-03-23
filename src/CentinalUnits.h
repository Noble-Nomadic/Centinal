#ifndef CentinalUnits_h
#define CentinalUnits_h

// Take in a file and read it character by character to store contents
// If 3 characters or more in a row are found, then that data is stored as [(character), (repetitions)]
// If 3 numbers or more in a row are found, convert to hexadecimal

void Compress() {
    // Get the file name
    char filename[100];

    if (!fgets(filename, sizeof(filename), stdin)) {
        return
    }

    FILE *file;
    file = fopen(filename, "r");

    // Iterate through each character in the file and append it to the list
    char characters[50000];

    for (int i = 0; i < sizeof(characters), i++) {
        
        char currentchar = fgetc(file);

        if (currentchar == NULL) {
            break;
        }
        
        characters[i] = currentchar;
    }

    // Iterate through each character
}

#endif