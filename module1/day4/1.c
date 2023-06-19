#include <stdio.h>

int main() {
    int array[] = {12, 84, 20, 36, 64, 56, 72, 10, 45, 90};
    int length = sizeof(array) / sizeof(array[0]);
    int sum = 0;

    // Calculate the sum of the elements
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }

    // Calculate the average
    float average = (float)sum / length;

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);

    return 0;
}
