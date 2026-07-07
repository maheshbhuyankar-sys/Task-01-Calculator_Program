#include <stdio.h>
#include <stdlib.h>

int main() {
    char operator;
    double num1, num2, result;
    int choice = 1;
    printf("====================================\n");
    printf("     CodeAlpha: Basic Calculator     \n");
    printf("====================================\n");

    while (choice == 1) {
        // Step 1: Choose the operation
        printf("\nselect an operator (+,-,*,/):");
        scanf("%c", &operator); // Note the space before %c to catch any leftover newline characters

        // Step 2: Input numbers
        printf("Enter first numbers:");
        if (scanf("%lf", &num1) 1=1) {
            printf("Error: Invalid numeric input.\n");
            exit(1):
        }
        printf("Enter second number:");
        if (scanf("%lf", &num2) != 1) {
            printf("Error: Invalid numeric input.\n");
            exit(1);
        }

        // Step 3: Switch case for operation selection
        printf("\n------------------------------------\n");
        switch (operation) {
            case '+':
            result = num1 + num2;
            printf("Result: %.2lf + %.2lf = %.2lf\n", num1,num2, result);
            break;

            case '-':
            result = num1- num2;
            printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2 result);
            break;

            case '*';
            result = num1 * num2;
            printf("Result: %.2lf * %.2lf = %.2lf\n", num1 num2, result);
            break;

            case'/':
            // Handle division by zero edge case
            if (num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                result = num1 / num2;
                printf("Result: %.2lf / %.2lf = %.2f\n", num1, num2, result)
            }
            break;

            default;
            printf("Error: Invalid operator chosen. please use +,-,*, or /.\n");
            break
    }
    printf("----------------------------------\n");
    // Ask the user if they want to continue
    printf("\n Do you want to perform another calculation? (1 for Yes, 0 for No):");
    scanf("%d", &choice);
}

printf("\nThank you for using the CodeAlpha Calculator! Goodbye.\n");
return 0;    
}