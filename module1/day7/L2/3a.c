#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
    FILE *sourceFile, *tempFile;
    char sourcePath[] = "data.csv";
    char tempPath[] = "temp.csv";
    char line[MAX_LINE_LENGTH];
    char entryNoToDelete[20];
    int entryNoFieldIndex = 0;

    // Get the EntryNo to be deleted
    printf("Enter the EntryNo to delete: ");
    scanf("%s", entryNoToDelete);

    // Open the source file for reading
    sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Failed to open the source file.\n");
        return 1;
    }

    // Create the temporary file for writing
    tempFile = fopen(tempPath, "w");
    if (tempFile == NULL) {
        printf("Failed to create the temporary file.\n");
        fclose(sourceFile);
        return 1;
    }

    // Read each line from the source file, skip the line with the matching EntryNo, and write other lines to the temporary file
    while (fgets(line, MAX_LINE_LENGTH, sourceFile) != NULL) {
        char *entryNo = strtok(line, ",");
        
        if (entryNoFieldIndex == 0) {
            // Check if the current line is the header line
            if (strcmp(entryNo, "EntryNo") == 0) {
                entryNoFieldIndex++;
                fputs(line, tempFile); // Write the header line to the temporary file
                continue;
            }
        }

        // Check if the EntryNo matches the one to be deleted
        if (strcmp(entryNo, entryNoToDelete) != 0) {
            fputs(line, tempFile); // Write the line to the temporary file
        }
    }

    // Close the files
    fclose(sourceFile);
    fclose(tempFile);

    // Delete the original source file
    if (remove(sourcePath) != 0) {
        printf("Failed to delete the source file.\n");
        return 1;
    }

    // Rename the temporary file to the original source file name
    if (rename(tempPath, sourcePath) != 0) {
        printf("Failed to rename the temporary file.\n");
        return 1;
    }

    printf("Entry deleted successfully.\n");

    return 0;
}
