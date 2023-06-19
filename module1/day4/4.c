#include <stdio.h>

int main() {
    int array[] = {64, 84, 21, 36, 17, 90, 77, 10, 48, 55};
    int length = sizeof(array) / sizeof(array[0]);

    int sumEven = 0;
    int sumOdd = 0;

    for (int i = 0; i < length; i++) {
        if (array[i] % 2 == 0) {
            sumEven += array[i];
        } else {
            sumOdd += array[i];
        }
    }

    int difference = sumEven - sumOdd;

    printf("Sum of even elements: %d\n", sumEven);
    printf("Sum of odd elements: %d\n", sumOdd);
    printf("Difference between even and odd elements: %d\n", difference);

    return 0;
}
