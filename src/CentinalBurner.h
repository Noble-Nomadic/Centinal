#ifndef CentinalBurner_h
#define CentinalBurner_h

#include <stdio.h>
#include <stdlib.h>

void burn_cd(const char *iso_image) {
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

void read_cd() {
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

int main() {
    int choice;
    char iso_image[256];

    printf("CD Manager\n");
    printf("1. Burn a CD\n");
    printf("8. Read from CD\n");
    printf("Enter your choice (1 or 8): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the path to the ISO image: ");
        scanf("%s", iso_image);
        burn_cd(iso_image);
    } 

    else if (choice == 8) {
        read_cd();
    } 

    else {
        printf("Invalid choice.\n");
    }

    return 0;
}

#endif
