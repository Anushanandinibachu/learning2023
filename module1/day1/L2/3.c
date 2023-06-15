#include <stdio.h>

int isVowel(char ch) {
    int isVowel = 0;
    switch (ch) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            isVowel = 1;
            break;
        default:
            isVowel = 0;
    }
    return isVowel;
}

int main() {
    char character;
    scanf("%s", &character);
    int result = isVowel(character);
    if (result == 1) {
        printf("Vowel\n");
    } else {
        printf("Not Vowel\n");
    }
    return 0;
}