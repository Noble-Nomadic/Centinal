#ifndef CentinalBurner_h
#define CentinalBurner_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BurnerHelp() {
    printf("Centinal File Multitool Commands\n");
    printf("1. help - show this\n");
    printf("2. exit - return to main CLI\n");
    printf("3. burn - burn an ISO file to a cd\n");
    printf("4. read - view the data of a cd\n");
    return;
}

void BurnCD(const char *iso_image) {
    char command[256];

    snprintf(command, sizeof(command), "wodim dev=/dev/cdrom %s", iso_image);

    printf("Burning CD with ISO image: %s\n", iso_image);
    if (system(command) == 0) {
        printf("Burning successful!\n");
    } 

    else {
        printf("Error burning the CD.\n");
    }
}

void ReadCD() {
    printf("Mounting CD...\n");
    if (system("mount /dev/cdrom /mnt") == 0) {
        printf("CD mounted successfully. Listing contents:\n");
        system("ls /mnt");
        printf("Unmounting CD...\n");
        system("umount /mnt");
    } 

    else {
        printf("Error mounting the CD.\n");
    }
}

void BurnerLoop() {
    char input[100];
    char iso_image[256];


    while (1) {
        printf("Burner> ");
        fgets(choice)

        if (strcmp(choice, "burn") == 0) {

            printf("Enter the path to the ISO image or CANCEL to cancel: ");
            scanf("%s", iso_image);

            if (strcmp(iso_image, "CANCEL") == 0) {
                continue;
            }

            BurnCD(iso_image);
        }

        else if (strcmp(choice, "read") == 0) {
            ReadCD();
        }

        else if (strcmp(choice, "help") == 0) {
            BurnerHelp();
        }

        else if (strcmp(choice, "exit") == 0) {
            break;
        }

        else {
            printf("Invalid choice.\n");
        }
    }

    return;
}

#endif
