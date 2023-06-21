#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

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
    int num_students = 3;
    struct Student students[] = {
        { 1001, "John", 85.5 },
        { 1002, "Alice", 92.0 },
        { 1003, "Bob", 78.8 }
    };

    // Display all members in the array of structures
    display_students(students, num_students);

    return 0;
}