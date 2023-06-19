#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encode(char *str) {
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        str[i] = str[i] + 5;  // Add 5 to each character for encoding
    }
}

void decode(char *str) {
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        str[i] = str[i] - 5;  // Subtract 5 from each character for decoding
    }
}

int main() {
    char originalString[100];
    char encodedString[100];

    printf("Enter a string: ");
    fgets(originalString, sizeof(originalString), stdin);
    originalString[strcspn(originalString, "\n")] = '\0';  // Remove trailing newline character

    // Encode the string
    strcpy(encodedString, originalString);
    encode(encodedString);

    printf("Encoded string: %s\n", encodedString);

    // Decode the string
    decode(encodedString);

    printf("Decoded string: %s\n", encodedString);

    return 0;
}
