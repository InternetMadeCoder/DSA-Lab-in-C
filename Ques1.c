// write a menu drive program to implement the 10 arithmetic operations.

#include <stdio.h>
#include <math.h>

int main() {
    int ch;


    do {
        int num1, num2, result;
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Power\n");
        printf("7. Square root\n");
        printf("8. Logarithm \n");
        printf("9. Sine \n");
        printf("10. Cosine \n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                result = num1 + num2;
                printf("Result: %d\n", result);
                break;
            case 2:
                result = num1 - num2;
                printf("Result: %d\n", result);
                break;
            case 3:
                result = num1 * num2;
                printf("Result: %d\n", result);
                break;
            case 4:
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("Result: %d\n", result);
                } else {
                    printf("Division by zero is not allowed.\n");
                }
                break;
            case 5:
                if ((int)num2 != 0) {
                    result = (int)num1 % (int)num2;
                    printf("Result: %d\n", result);
                } else {
                    printf("Modulus by zero is not allowed.\n");
                }
                break;
            case 6:
                result = pow(num1, num2);
                printf("Result: %d\n", result);
                break;
            case 7:
                if (num1 >= 0) {
                    result = sqrt(num1);
                    printf("Result: %d\n", result);
                } else {
                    printf("Square root of a negative number is not defined.\n");
                }
                break;
            case 8:
               result = log10(num1);
                printf("Result: %d\n", result);
                break;
            case 9:
                result = sin(num1);
                printf("Result: %d\n", result);
                break;
            case 10:
                result = cos(num1);
                printf("Result: %d\n", result);
                break;
            case 11:
                printf("Bye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (ch != 11);
}
