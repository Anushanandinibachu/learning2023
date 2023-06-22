#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[10];
} LogEntry;

void swapEntries(LogEntry *entry1, LogEntry *entry2) {
    LogEntry temp = *entry1;
    *entry1 = *entry2;
    *entry2 = temp;
}

int main() {
    FILE *file = fopen("data.csv", "r+");
    if (file == NULL) {
        printf("Failed to open data.csv file.\n");
        return 1;
    }
    
    LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;
    
    char line[100];
    fgets(line, sizeof(line), file); // Skip the header line
    
    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,]",
               &logEntries[numEntries].entryNo,
               logEntries[numEntries].sensorNo,
               &logEntries[numEntries].temperature,
               &logEntries[numEntries].humidity,
               &logEntries[numEntries].light,
               logEntries[numEntries].timestamp);
        
        numEntries++;
    }
    
    // Bubble sort based on "Temperature" field in descending order
    for (int i = 0; i < numEntries - 1; i++) {
        for (int j = 0; j < numEntries - i - 1; j++) {
            if (logEntries[j].temperature < logEntries[j + 1].temperature) {
                swapEntries(&logEntries[j], &logEntries[j + 1]);
            }
        }
    }
    
    fseek(file, 0, SEEK_SET);
    fgets(line, sizeof(line), file); // Read the header line again
    
    for (int i = 0; i < numEntries; i++) {
        sprintf(line, "%d,%s,%.2f,%d,%d,%s\n",
                logEntries[i].entryNo,
                logEntries[i].sensorNo,
                logEntries[i].temperature,
                logEntries[i].humidity,
                logEntries[i].light,
                logEntries[i].timestamp);
        
        fputs(line, file);
    }
    
    fclose(file);
    
    printf("Data.csv sorted based on Temperature in descending order.\n");
    
    return 0;
}