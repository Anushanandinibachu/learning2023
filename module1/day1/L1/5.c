#include <stdio.h>

int bit_operations(int num, int oper_type) {
    switch (oper_type) {
        case 1:
            // Set 1st bit
            num |= (1 << 0);
            break;
        case 2:
            // Clear 31st bit
            num &= ~(1 << 30);
            break;
        case 3:
            // Toggle 16th bit
            num ^= (1 << 15);
            break;
        default:
            printf("Invalid operation type.\n");
            break;
    }

    return num;
}

int main() {
    int num, oper_type;

    printf("Enter the integer (32 bits): ");
    scanf("%d", &num);

    printf("Enter the operation type (1, 2, or 3): ");
    scanf("%d", &oper_type);

    int result = bit_operations(num, oper_type);

    printf("Result: %d\n", result);

    return 0;
}