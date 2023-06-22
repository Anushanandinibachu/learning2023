#include <stdio.h>

struct Student {
    char name[50];
    int age;
};

void swapFields(struct Student* s1, struct Student* s2) {
    char tempName[50];
    int tempAge;

    // Swap the name fields
    strcpy(tempName, s1->name);
    strcpy(s1->name, s2->name);
    strcpy(s2->name, tempName);

    // Swap the age fields
    tempAge = s1->age;
    s1->age = s2->age;
    s2->age = tempAge;
}

int main() {
    struct Student student1 = {"Alice", 20};
    struct Student student2 = {"Bob", 18};

    printf("Before swapping:\n");
    printf("Student 1: Name: %s, Age: %d\n", student1.name, student1.age);
    printf("Student 2: Name: %s, Age: %d\n", student2.name, student2.age);

    // Swap the fields using pointers
    swapFields(&student1, &student2);

    printf("\nAfter swapping:\n");
    printf("Student 1: Name: %s, Age: %d\n", student1.name, student1.age);
    printf("Student 2: Name: %s, Age: %d\n", student2.name, student2.age);

    return 0;
}