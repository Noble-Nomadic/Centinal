#ifndef CentinalSettings_h
#define CentinalSettings_h

void SettingsHelp() {
    
}


void SettingsLoop() {
    char input[100];

    while (1) {
        printf("Settings> ");

        if (!fgets(input, sizeof(input), stdin)) {
            break;
        }
        input[strcspn(input, "\n")] = 0;

        else if (strcmp(input, "help") == 0) {
            SettingsHelp();
        }
    }
}

#endif