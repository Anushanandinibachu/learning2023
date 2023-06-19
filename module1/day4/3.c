#include <stdio.h>

int main() {
    int array[] = {64, 84, 20, 36, 12, 90, 72, 10, 45, 56};
    int length = sizeof(array) / sizeof(array[0]);

    printf("Original Array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }

    printf("\nReversed Array: ");
    for (int i = length - 1; i >= 0; i--) {
        printf("%d ", array[i]);
    }

    return 0;
}
