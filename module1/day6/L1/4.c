#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

// Function to swap two Student structures
void swap(struct Student* a, struct Student* b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform descending bubble sort based on marks
void sort_students(struct Student* students, int num_students) {
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = 0; j < num_students - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                swap(&students[j], &students[j + 1]);
            }
        }
    }
}

// Function to display all members in the array of structures
void display_students(const struct Student* students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
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

    // Sort the array of structures in descending order based on marks
    sort_students(students, num_students);

    // Display all members in the sorted array of structures
    display_students(students, num_students);

    return 0;
}