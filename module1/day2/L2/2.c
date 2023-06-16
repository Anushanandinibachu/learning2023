#include <stdio.h>

int compareBoxes(int boxA[], int boxB[], int size) {
    int count[size];

    // Initialize count array with all elements as 0
    for (int i = 0; i < size; i++) {
        count[i] = 0;
    }

    // Count occurrences of items in boxA
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (boxA[i] == boxB[j]) {
                count[j]++;
                break;
            }
        }
    }

    // Check if each item in boxB has a one-to-one mapping in boxA
    for (int i = 0; i < size; i++) {
        if (count[i] != 1) {
            return 0; // Mapping not found, return 0
        }
    }

    return 1; // One-to-one mapping found, return 1
}

int main() {
    int size;
    printf("Enter the size of the boxes: ");
    scanf("%d", &size);

    int boxA[size], boxB[size];
    printf("Enter the items in box A: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &boxA[i]);
    }

    printf("Enter the items in box B: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &boxB[i]);
    }

    int result = compareBoxes(boxA, boxB, size);

    if (result == 1) {
        printf("Boxes have a one-to-one mapping of items.\n");
    } else {
        printf("Boxes do not have a one-to-one mapping of items.\n");
    }

    return 0;
}
