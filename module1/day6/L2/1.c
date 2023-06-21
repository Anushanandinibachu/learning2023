#include <stdio.h>
#include <stdlib.h>

struct Member {
    char name[100];
    int age;
};

void addMember(struct Member** members, int* size, const char* name, int age) {
    // Create a new member with the given name and age
    struct Member newMember;
    snprintf(newMember.name, sizeof(newMember.name), "%s", name);
    newMember.age = age;

    // Increase the size of the array
    int newSize = (*size) + 1;

    // Reallocate memory for the updated array
    struct Member* newMembers = (struct Member*)realloc(*members, newSize * sizeof(struct Member));
    if (newMembers == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Add the new member at the end
    newMembers[(*size)] = newMember;

    // Update the members and size with the new values
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

    // Displaying members
    for (int i = 0; i < size; i++) {
        printf("Name: %s, Age: %d\n", members[i].name, members[i].age);
    }

    // Clean up the memory
    free(members);

    return 0;
}
