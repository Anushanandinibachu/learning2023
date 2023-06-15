#include <stdio.h>

int main() {
    int rollNo;
    char name[50];
    int physics, math, chemistry;
    int totalMarks;
    float percentage;

    // Read inputs from the user
    printf("Enter Roll No: ");
    scanf("%d", &rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Marks of Physics: ");
    scanf("%d", &physics);

    printf("Enter Marks of Math: ");
    scanf("%d", &math);

    printf("Enter Marks of Chemistry: ");
    scanf("%d", &chemistry);

    // Calculate total marks and percentage
    totalMarks = physics + math + chemistry;
    percentage = (float)totalMarks / 300 * 100;

    // Print the summary
    printf("\n----- Student Summary -----\n");
    printf("Roll No: %d\n", rollNo);
    printf("Name: %s\n", name);
    printf("Physics: %d\n", physics);
    printf("Math: %d\n", math);
    printf("Chemistry: %d\n", chemistry);
    printf("Total Marks: %d\n", totalMarks);
    printf("Percentage: %.2f%%\n", percentage);

    return 0;
}