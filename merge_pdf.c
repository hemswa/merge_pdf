#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_PATH 256

int main() {
    char files[MAX_FILES][MAX_PATH];
    char outputFile[MAX_PATH];
    int fileCount = 0;
    char choice;

    printf("PDF Merger\n");
    printf("==========\n");

    // Collect input PDF files
    do {
        if (fileCount >= MAX_FILES) {
            printf("Reached maximum file limit (%d).\n", MAX_FILES);
            break;
        }
        printf("Enter the path to a PDF file: ");
        scanf("%s", files[fileCount]);
        fileCount++;

        printf("Do you have another file to add? (y/n): ");
        getchar(); // Consume leftover newline
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');

    if (fileCount < 2) {
        printf("At least two files are required to merge PDFs.\n");
        return 1;
    }

    // Get the output file name
    printf("Enter the output file name (e.g., merged.pdf): ");
    scanf("%s", outputFile);

    // Build the pdftk command
    char command[1024] = "pdftk ";
    for (int i = 0; i < fileCount; i++) {
        strcat(command, files[i]);
        strcat(command, " ");
    }
    strcat(command, "cat output ");
    strcat(command, outputFile);

    // Execute the command
    printf("Merging PDFs...\n");
    int result = system(command);

    if (result == 0) {
        printf("PDFs merged successfully into '%s'.\n", outputFile);
    } else {
        printf("An error occurred while merging PDFs.\n");
    }

    return 0;
}