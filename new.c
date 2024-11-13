#include <stdio.h>
#include <ctype.h>  // For isdigit()
#include <string.h>  // For strlen()
#include <stdlib.h>  // For atof and atoi

// Function to validate if the input is a valid number
int is_valid_number(char *input) {
    int dot_count = 0;

    // Check if input is empty
    if (*input == '\0') return 0;

    // Handle negative numbers
    if (*input == '-') return 0;

    // Iterate through the input and ensure it's a valid number
    while (*input) {
        if (*input == '.') {
            dot_count++;
            if (dot_count > 1) return 0;  // Invalid if more than one period
        } else if (!isdigit(*input)) {
            return 0;  // Invalid if non-digit and not a period
        }
        input++;
    }

    return 1;  // Valid number if only digits and possibly one period
}

// Recursive function to calculate compound interest (pass by reference)
void calculate_interest(float *principal, float rate, int years) {
    if (years == 0) {
        return;
    } else {
        *principal = *principal * (1 + rate / 100);
        calculate_interest(principal, rate, years - 1);  // Recur for next year
    }
}

int main() {
    char input[100];
    float principal, rate;
    int years;

    // Get and validate principal input
    printf("Enter the principal amount: ");
    scanf("%s", input);  // Read input as a string
    while (!is_valid_number(input)) {
        printf("Invalid input. Please enter a valid number for the principal: ");
        scanf("%s", input);  // Read input as a string
    }
    principal = atof(input);  // Convert string to float

    // Get and validate interest rate input
    printf("Enter the annual interest rate (in percentage): ");
    scanf("%s", input);  // Read input as a string
    while (!is_valid_number(input)) {
        printf("Invalid input. Please enter a valid number for the interest rate: ");
        scanf("%s", input);  // Read input as a string
    }
    rate = atof(input);  // Convert string to float

    // Get and validate the number of years input
    printf("Enter the number of years: ");
    scanf("%s", input);  // Read input as a string
    while (!is_valid_number(input)) {
        printf("Invalid input. Please enter a valid number for the number of years: ");
        scanf("%s", input);  // Read input as a string
    }
    years = atoi(input);  // Convert string to integer

    // Edge case: Make sure principal, rate, and years are positive
    if (principal <= 0) {
        printf("Principal amount must be greater than zero.\n");
        return 1;
    }
    if (rate < 0) {
        printf("Interest rate cannot be negative.\n");
        return 1;
    }
    if (years <= 0) {
        printf("Number of years must be greater than zero.\n");
        return 1;
    }

    // Call the recursive function to calculate compound interest
    calculate_interest(&principal, rate, years);

    // Display the result
    printf("The amount after %d years is: %.2f\n", years, principal);

    return 0;
}