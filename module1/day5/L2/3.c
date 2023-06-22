#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50

struct Student {
    char name[MAX_NAME_LENGTH];
    int marks;
};

void readStudents(struct Student *students, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%d", &students[i].marks);
    }
}

void writeStudents(struct Student *students, int n) {
    printf("Student Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Marks: %d\n", students[i].marks);
    }
}

float computeAverageMarks(struct Student *students, int n) {
    int totalMarks = 0;
    for (int i = 0; i < n; i++) {
        totalMarks += students[i].marks;
    }
    return (float)totalMarks / n;
}

void printStudentsAboveAverage(struct Student *students, int n, float averageMarks) {
    printf("Students who scored above the average marks:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].marks > averageMarks) {
            printf("Name: %s\n", students[i].name);
            printf("Marks: %d\n", students[i].marks);
        }
    }
}

void printStudentsBelowAverage(struct Student *students, int n, float averageMarks) {
    printf("Students who scored below the average marks:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].marks < averageMarks) {
            printf("Name: %s\n", students[i].name);
            printf("Marks: %d\n", students[i].marks);
        }
    }
}

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student *students = malloc(n * sizeof(struct Student));

    readStudents(students, n);

    printf("\n");

    writeStudents(students, n);

    float averageMarks = computeAverageMarks(students, n);

    printf("\nAverage marks: %.2f\n\n", averageMarks);

    printStudentsAboveAverage(students, n, averageMarks);

    printf("\n");

    printStudentsBelowAverage(students, n, averageMarks);

    free(students);

    return 0;
}