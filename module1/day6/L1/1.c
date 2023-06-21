#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student
struct Student {
    int rollno;
    char name[20];
    float marks;
};

// Function to parse the string and initialize the array of structures
void parse_string(const char* input, struct Student* students, int num_students) {
    char* token;

    // Copy the input string to avoid modifying the original string
    char* input_copy = strdup(input);

    // Split the string using strtok
    token = strtok(input_copy, " ");

    // Iterate over each token and initialize the structure members
    for (int i = 0; i < num_students; i++) {
        // Read the rollno, name, and marks from the tokens
        students[i].rollno = atoi(token);

        token = strtok(NULL, " ");
        strcpy(students[i].name, token);

        token = strtok(NULL, " ");
        students[i].marks = atof(token);

        // Move to the next set of tokens
        token = strtok(NULL, " ");
    }

    // Free the copied string
    free(input_copy);
}

int main() {
    const char* input = "1001 Aron 100.00";
    int num_students = 1;

    // Create an array of structures
    struct Student* students = (struct Student*)malloc(num_students * sizeof(struct Student));

    // Parse the string and initialize the array of structures
    parse_string(input, students, num_students);

    // Print the student details
    for (int i = 0; i < num_students; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    // Free the memory allocated for the array of structures
    free(students);

    return 0;
}