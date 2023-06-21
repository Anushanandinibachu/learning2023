#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

// Function to perform a search operation based on the name of the student
void search_student(const struct Student* students, int num_students, const char* search_name) {
    int found = 0;

    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].name, search_name) == 0) {
            printf("Student Found:\n");
            printf("Roll No: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            printf("\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with name '%s' not found.\n\n", search_name);
    }
}

int main() {
    int num_students = 4;
    struct Student students[] = {
        { 1001, "John", 85.5 },
        { 1002, "Alice", 92.0 },
        { 1003, "Bob", 78.8 },
        { 1004, "Emma", 91.2 }
    };

    char search_name[20];

    printf("Enter the name of the student to search: ");
    scanf("%s", search_name);

    // Perform the search operation based on the name of the student
    search_student(students, num_students, search_name);

    return 0;
}