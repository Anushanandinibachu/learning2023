#include <stdio.h>

int main() {
    int array[] = {64, 84, 21, 36, 17, 90, 77, 10, 48, 55};
    int length = sizeof(array) / sizeof(array[0]);

    int sumEvenIndexed = 0;
    int sumOddIndexed = 0;

    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) {
            sumEvenIndexed += array[i];
        } else {
            sumOddIndexed += array[i];
        }
    }

    int difference = sumEvenIndexed - sumOddIndexed;

    printf("Sum of even-indexed elements: %d\n", sumEvenIndexed);
    printf("Sum of odd-indexed elements: %d\n", sumOddIndexed);
    printf("Difference between even-indexed and odd-indexed elements: %d\n", difference);

    return 0;
}
