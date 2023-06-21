#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

// Function to initialize all members in the array of structures
void initialize_students(struct Student* students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        students[i].rollno = 0;
        strcpy(students[i].name, "");
        students[i].marks = 0.0;
    }
}

int main() {
    int num_students = 5;
    struct Student students[num_students];

    // Initialize all members in the array of structures
    initialize_students(students, num_students);

    // Print the student details
    for (int i = 0; i < num_students; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    return 0;
}