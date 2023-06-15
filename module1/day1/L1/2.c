//program to print the grade of the given student using if else if block

#include <stdio.h>

//IF LOOP Block
void grade(int score) {
    if (score >= 90 && score <= 100) {
        printf("Grade A\n");
    } else if (score >= 75 && score <= 89) {
        printf("Grade B\n");
    } else if (score >= 60 && score <= 74) {
        printf("Grade C\n");
    } else if (score >= 50 && score <= 59) {
        printf("Grade D\n");
    } else if (score >= 0 && score <= 49) {
        printf("Grade F\n");
    } else {
        printf("Invalid score\n");
    }
}

//Main function
int main() {
    int score;
    printf("Enter the score: ");
    scanf("%d", &score);
    
    grade(score);
    
    return 0;
}