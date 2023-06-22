#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

// Structure to hold the log data
typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[10];
} LogEntry;

// Function to extract each line from the .csv file and store it in an array of structures
int extractLogData(LogEntry logEntries[], const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        return 0;
    }

    char line[100];
    int count = 0;

    // Read each line and store it in the array
    while (fgets(line, sizeof(line), file) != NULL) {
        if (count >= MAX_ENTRIES) {
            printf("Exceeded maximum number of entries.\n");
            break;
        }

        LogEntry entry;
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,\n]", &entry.entryNo, entry.sensorNo, &entry.temperature, &entry.humidity, &entry.light, entry.time);
        logEntries[count++] = entry;
    }

    fclose(file);
    return count;
}

// Function to display the contents of the array of structures
void displayLogData(const LogEntry logEntries[], int count) {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTime\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f\t\t%d\t\t%d\t%s\n", logEntries[i].entryNo, logEntries[i].sensorNo, logEntries[i].temperature, logEntries[i].humidity, logEntries[i].light, logEntries[i].time);
    }
}

int main() {
    LogEntry logEntries[MAX_ENTRIES];
    int count = extractLogData(logEntries, "data.csv");
    if (count > 0) {
        displayLogData(logEntries, count);
    }

    return 0;
}