#include <stdio.h>
#include <stdlib.h>

struct Member {
    char name[100];
    int age;
};

void deleteMember(struct Member** members, int* size) {
    // Check if the array is empty
    if (*size == 0) {
        printf("No members to delete!\n");
        return;
    }

    // Decrease the size of the array
    int newSize = (*size) - 1;

    // Allocate memory for the updated array
    struct Member* newMembers = (struct Member*)malloc(newSize * sizeof(struct Member));
    if (newMembers == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Copy existing members, starting from the second member, to the new array
    for (int i = 1; i < (*size); i++) {
        newMembers[i - 1] = (*members)[i];
    }

    // Update the members and size with the new values
    free(*members);
    *members = newMembers;
    *size = newSize;
}

int main() {
    struct Member* members = NULL;
    int size = 0;

    // Adding members
    addMember(&members, &size, "John", 25);
    addMember(&members, &size, "Alice", 30);
    addMember(&members, &size, "Bob", 28);

    // Deleting a member at the start
    deleteMember(&members, &size);

    // Displaying members
    for (int i = 0; i < size; i++) {
        printf("Name: %s, Age: %d\n", members[i].name, members[i].age);
    }

    // Clean up the memory
    free(members);

    return 0;
}
