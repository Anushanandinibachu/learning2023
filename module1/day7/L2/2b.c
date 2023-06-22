#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[10];
} LogEntry;

void updateEntry(LogEntry entries[], int numEntries, int entryNo, float newTemperature) {
    for (int i = 0; i < numEntries; i++) {
        if (entries[i].entryNo == entryNo) {
            entries[i].temperature = newTemperature;
            break;
        }
    }
}

void writeLogEntriesToFile(LogEntry entries[], int numEntries) {
    FILE *file = fopen("data.csv", "w");
    if (file == NULL) {
        printf("Failed to open data.csv file for writing.\n");
        return;
    }

    fputs("EntryNo,SensorNo,Temperature,Humidity,Light,Time\n", file);
    for (int i = 0; i < numEntries; i++) {
        fprintf(file, "%d,%s,%.1f,%d,%d,%s\n", entries[i].entryNo, entries[i].sensorNo, entries[i].temperature,
                entries[i].humidity, entries[i].light, entries[i].timestamp);
    }

    fclose(file);
}

int main() {
    LogEntry entries[100];
    int numEntries = 0;

    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open data.csv file.\n");
        return 0;
    }

    char line[100];
    fgets(line, sizeof(line), file); // Skip the header line

    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,\n]", &entries[numEntries].entryNo, entries[numEntries].sensorNo,
               &entries[numEntries].temperature, &entries[numEntries].humidity, &entries[numEntries].light,
               entries[numEntries].timestamp);
        numEntries++;
    }

    fclose(file);

    int entryNo = 2; // Entry number to update
    float newTemperature = 35.5; // New temperature

    updateEntry(entries, numEntries, entryNo, newTemperature);
    writeLogEntriesToFile(entries, numEntries);
    printf("Entry %d updated successfully in data.csv.\n", entryNo);

    return 0;
}