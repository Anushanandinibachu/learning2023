#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void updateEntry(int entryNo, float newTemperature) {
    FILE *originalFile = fopen("data.csv", "r");
    if (originalFile == NULL) {
        printf("Failed to open data.csv file.\n");
        return;
    }

    FILE *tempFile = fopen("temp.csv", "w");
    if (tempFile == NULL) {
        printf("Failed to create temporary file.\n");
        fclose(originalFile);
        return;
    }

    char line[100];
    fgets(line, sizeof(line), originalFile); // Read and write the header line to the temporary file
    fputs(line, tempFile);

    while (fgets(line, sizeof(line), originalFile) != NULL) {
        int currentEntryNo = atoi(strtok(line, ","));
        if (currentEntryNo == entryNo) {
            // Update the line with the new temperature
            char *token = strtok(NULL, ","); // Skip SensorNo field
            token = strtok(NULL, ","); // Skip Temperature field
            snprintf(token, 10, "%.1f", newTemperature); // Write the new temperature

            // Write the modified line to the temporary file
            fputs(line, tempFile);
        } else {
            // Write the line as it is to the temporary file
            fputs(line, tempFile);
        }
    }

    fclose(originalFile);
    fclose(tempFile);

    remove("data.csv"); // Delete the original file
    rename("temp.csv", "data.csv"); // Rename the temporary file to "data.csv"
}

int main() {
    int entryNo = 2; // Entry number to update
    float newTemperature = 35.5; // New temperature

    updateEntry(entryNo, newTemperature);
    printf("Entry %d updated successfully in data.csv.\n", entryNo);

    return 0;
}