#include <stdio.h>

char getGrade(int score) {
    char grade;
    switch (score) {
        case 90 ... 100:
            grade = 'A';
            break;
        case 75 ... 89:
            grade = 'B';
            break;
        case 60 ... 74:
            grade = 'C';
            break;
        case 50 ... 59:
            grade = 'D';
            break;
        case 36 ... 49:
            grade = 'E';
            break;
        case 0 ... 35:
            grade = 'F';
            break;
        default:
            grade = 'X'; // Invalid score
    }
    return grade;
}

int main() {
    int score;
    scanf("%d",&score);
    char grade = getGrade(score);
    printf("Grade %c\n", grade);
    return 0;
}