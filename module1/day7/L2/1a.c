#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortDataCSV() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open data.csv file.\n");
        return;
    }

    // Read the lines into an array
    char lines[100][100];
    int numLines = 0;
    char line[100];
    fgets(line, sizeof(line), file); // Skip the header line

    while (fgets(line, sizeof(line), file) != NULL) {
        strcpy(lines[numLines++], line);
    }
    fclose(file);

    // Sort the array based on Temperature field in descending order
    for (int i = 0; i < numLines - 1; i++) {
        for (int j = 0; j < numLines - i - 1; j++) {
            char *token1 = strtok(lines[j], ",");
            token1 = strtok(NULL, ","); // Skip EntryNo field
            token1 = strtok(NULL, ","); // Skip SensorNo field
            float temperature1 = atof(strtok(NULL, ",")); // Get Temperature field

            char *token2 = strtok(lines[j + 1], ",");
            token2 = strtok(NULL, ","); // Skip EntryNo field
            token2 = strtok(NULL, ","); // Skip SensorNo field
            float temperature2 = atof(strtok(NULL, ",")); // Get Temperature field

            if (temperature1 < temperature2) {
                char temp[100];
                strcpy(temp, lines[j]);
                strcpy(lines[j], lines[j + 1]);
                strcpy(lines[j + 1], temp);
            }
        }
    }

    // Write the sorted lines back to the file
    file = fopen("data.csv", "w");
    if (file == NULL) {
        printf("Failed to open data.csv file for writing.\n");
        return;
    }

    fputs("EntryNo,SensorNo,Temperature,Humidity,Light,Time\n", file);
    for (int i = 0; i < numLines; i++) {
        fputs(lines[i], file);
    }

    fclose(file);
}

int main() {
    sortDataCSV();
    printf("data.csv sorted based on Temperature field in descending order.\n");
    return 0;
}