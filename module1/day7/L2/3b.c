#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_FIELD_LENGTH 50

struct Entry {
    char EntryNo[MAX_FIELD_LENGTH];
    char Name[MAX_FIELD_LENGTH];
    char Age[MAX_FIELD_LENGTH];
    char City[MAX_FIELD_LENGTH];
};

int main() {
    FILE *file;
    char filePath[] = "data.csv";
    struct Entry entries[MAX_ENTRIES];
    int numEntries = 0;
    char entryNoToDelete[MAX_FIELD_LENGTH];

    // Read the contents of the file into the array of structures
    file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    char line[MAX_FIELD_LENGTH * 4];  // Assuming each field can have a maximum length of MAX_FIELD_LENGTH and there are 4 fields

    // Read each line from the file and populate the array of structures
    while (fgets(line, sizeof(line), file) != NULL && numEntries < MAX_ENTRIES) {
        char *entryNo = strtok(line, ",");
        char *name = strtok(NULL, ",");
        char *age = strtok(NULL, ",");
        char *city = strtok(NULL, ",");

        strcpy(entries[numEntries].EntryNo, entryNo);
        strcpy(entries[numEntries].Name, name);
        strcpy(entries[numEntries].Age, age);
        strcpy(entries[numEntries].City, city);

        numEntries++;
    }

    fclose(file);

    // Prompt the user to enter the EntryNo to be deleted
    printf("Enter the EntryNo to delete: ");
    scanf("%s", entryNoToDelete);

    int found = 0;

    // Search for the entry with the matching EntryNo and remove it from the array
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].EntryNo, entryNoToDelete) == 0) {
            // Shift the remaining entries to fill the gap
            for (int j = i; j < numEntries - 1; j++) {
                strcpy(entries[j].EntryNo, entries[j + 1].EntryNo);
                strcpy(entries[j].Name, entries[j + 1].Name);
                strcpy(entries[j].Age, entries[j + 1].Age);
                strcpy(entries[j].City, entries[j + 1].City);
            }

            found = 1;
            numEntries--;
            break;
        }
    }

    if (!found) {
        printf("Entry not found.\n");
        return 1;
    }

    // Open the file in write mode, truncating its contents
    file = fopen(filePath, "w");
    if (file == NULL) {
        printf("Failed to open the file for writing.\n");
        return 1;
    }

    // Write the modified array of structures back to the file
    for (int i = 0; i < numEntries; i++) {
        fprintf(file, "%s,%s,%s,%s\n", entries[i].EntryNo, entries[i].Name, entries[i].Age, entries[i].City);
    }

    fclose(file);

    printf("Entry deleted successfully.\n");

    return 0;
}
