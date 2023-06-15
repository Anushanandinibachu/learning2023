//Functions to find Biggest of two numbers

//using if-else

int find_biggest(int number1, int number2) {
    if (number1 > number2) {
        return number1;
    } else {
        return number2;
    }
}

//Using ternary operator:


int find_biggest(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}
