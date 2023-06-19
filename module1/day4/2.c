#include <stdio.h>
#include <limits.h>

int main() {
    int array[] = {64, 84, 20, 36, 12, 90, 72, 10, 45, 56};
    int length = sizeof(array) / sizeof(array[0]);

    int min = INT_MAX;  
    int max = INT_MIN;  

    
    for (int i = 0; i < length; i++) {
        if (array[i] < min) {
            min = array[i];
        }
        if (array[i] > max) {
            max = array[i];
        }
    }

    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);

    return 0;
}
