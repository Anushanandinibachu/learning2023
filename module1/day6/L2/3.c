#include <stdio.h>
#include <stdlib.h>

struct Member {
    char name[100];
    int age;
};

void swapMembers(struct Member* members, int index1, int index2) {
    // Swap the members at the given indexes
    struct Member temp = members[index1];
    members[index1] = members[index2];
    members[index2] = temp;
}

int main() {
    struct Member members[3];

    // Initialize members
    snprintf(members[0].name, sizeof(members[0].name), "%s", "John");
    members[0].age = 25;
    snprintf(members[1].name, sizeof(members[1].name), "%s", "Alice");
    members[1].age = 30;
    snprintf(members[2].name, sizeof(members[2].name), "%s", "Bob");
    members[2].age = 28;

    int index1, index2;

    // Get user input for the indexes to swap
    printf("Enter the index of the first member to swap (0-2): ");
    scanf("%d", &index1);

    printf("Enter the index of the second member to swap (0-2): ");
    scanf("%d", &index2);

    // Perform the swap
    swapMembers(members, index1, index2);

    // Display members after the swap
    printf("Members after the swap:\n");
    for (int i = 0; i < 3; i++) {
        printf("Name: %s, Age: %d\n", members[i].name, members[i].age);
    }

    return 0;
}
