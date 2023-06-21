#include <stdio.h>
#include <stdlib.h>

struct Member {
    char name[100];
    int age;
};

void rotateMembers(struct Member* members, int size, int k) {
    // Check if rotation is needed
    if (k == 0 || k % size == 0) {
        return;
    }

    // Calculate the effective rotation count
    int effectiveRotation = k % size;

    // Create a temporary array to store the rotated members
    struct Member* tempMembers = (struct Member*)malloc(size * sizeof(struct Member));
    if (tempMembers == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Copy the rotated members to the temporary array
    for (int i = 0; i < size; i++) {
        int rotatedIndex = (i + effectiveRotation) % size;
        tempMembers[rotatedIndex] = members[i];
    }

    // Copy the rotated members back to the original array
    for (int i = 0; i < size; i++) {
        members[i] = tempMembers[i];
    }

    // Free the memory of the temporary array
    free(tempMembers);
}

int main() {
    struct Member members[4];

    // Initialize members
    snprintf(members[0].name, sizeof(members[0].name), "%s", "John");
    members[0].age = 25;
    snprintf(members[1].name, sizeof(members[1].name), "%s", "Alice");
    members[1].age = 30;
    snprintf(members[2].name, sizeof(members[2].name), "%s", "Bob");
    members[2].age = 28;
    snprintf(members[3].name, sizeof(members[3].name), "%s", "Eve");
    members[3].age = 35;

    int k;

    // Get user input for the rotation count
    printf("Enter the rotation count (positive for right rotation, negative for left rotation): ");
    scanf("%d", &k);

    // Perform the rotation
    rotateMembers(members, 4, k);

    // Display members after the rotation
    printf("Members after the rotation:\n");
    for (int i = 0; i < 4; i++) {
        printf("Name: %s, Age: %d\n", members[i].name, members[i].age);
    }

    return 0;
}
