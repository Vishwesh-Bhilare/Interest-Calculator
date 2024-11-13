#include <stdio.h>
#include <ctype.h>  // For isdigit()

// Function to validate if the input is a valid number
int is_valid_number(char *input) {
    // Check if every character in the string is a digit
    while (*input) {
        if (!isdigit(*input) && *input != '.') {
            return 0;  // Invalid input if non-digit or non-period is found
        }
        input++;
    }
    return 1;  // Valid number if only digits and possibly one period
}

// Recursive function to calculate compound interest
void calculate_interest(float *principal, float rate, int years) {
    // Base case: if years is 0, stop recursion
    if (years == 0) {
        return;
    } else {
        // Update the principal amount based on the interest for this year
        *principal = *principal * (1 + rate / 100);
        
        // Recur for the next year
        calculate_interest(principal, rate, years - 1);
    }
}

int main() {
    char input[100];
    float principal, rate;
    int years;

    // Get and validate principal input
    printf("Enter the principal amount: ");
    while (1) {
        fgets(input, sizeof(input), stdin);  // Get input as a string
        if (is_valid_number(input)) {
            principal = atof(input);  // Convert string to float
            break;  // Valid input, break the loop
        } else {
            printf("Invalid input. Please enter a valid number for the principal: ");
        }
    }

    // Get and validate interest rate input
    printf("Enter the annual interest rate (in percentage): ");
    while (1) {
        fgets(input, sizeof(input), stdin);  // Get input as a string
        if (is_valid_number(input)) {
            rate = atof(input);  // Convert string to float
            break;  // Valid input, break the loop
        } else {
            printf("Invalid input. Please enter a valid number for the interest rate: ");
        }
    }

    // Get and validate the number of years input
    printf("Enter the number of years: ");
    while (1) {
        fgets(input, sizeof(input), stdin);  // Get input as a string
        if (is_valid_number(input)) {
            years = atoi(input);  // Convert string to integer
            break;  // Valid input, break the loop
        } else {
            printf("Invalid input. Please enter a valid number for the number of years: ");
        }
    }

    // Call the recursive function to calculate compound interest
    calculate_interest(&principal, rate, years);

    // Display the result
    printf("The amount after %d years is: %.2f\n", years, principal);
    
    return 0;
}
