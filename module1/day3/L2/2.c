#include <stdio.h>

#define DEC_TO_BCD(dec) ((dec / 10) << 4) | (dec % 10)

unsigned char decimalToBCD(unsigned char decimal) {
    return DEC_TO_BCD(decimal);
}

int main() {
    unsigned char decimal = 23; // Example decimal number

    unsigned char bcd = decimalToBCD(decimal);

    printf("Decimal: %d\n", decimal);
    printf("BCD: 0x%02X\n", bcd);

    return 0;
}