#include <stdio.h>
#include <ctype.h>  // for isdigit()
#include <string.h>  // for strlen()
#include <stdlib.h>  // for atof and atoi

// validate if the input is a valid number
int is_valid_number(char *input) {
    int dot_count = 0;

    // if input is empty
    if (*input == '\0') return 0;

    // negative numbers
    if (*input == '-') return 0;

    // ensure every char it a valid
    while (*input) {
        if (*input == '.') {
            dot_count++;
            if (dot_count > 1) return 0;  // invalid if more than one '.'
        } else if (!isdigit(*input)) {
            return 0;  // invalid
        }
        input++;
    }

    return 1;  // valid number if only digits and possibly one '.'
}

// function to calculate compound interest (pass by reference)
void calculate_interest(float *principal, float rate, float years) {
    if (years == 0) {
        return;
    } else {
        *principal = *principal * (1 + rate / 100);
        calculate_interest(principal, rate, years - 1);  // recur for next year
    }
}

int main() {
    char input[100];
    float principal, rate;
    float years;

    // get and validate principal input
    printf("Enter the principal amount: ");
    scanf("%s", input);  // Read input as a string
    while (!is_valid_number(input)) {
        printf("Invalid input. Please enter a valid number for the principal: ");
        scanf("%s", input);  // Read input as a string
    }
    principal = atof(input);  // Convert string to float

    // get and validate interest rate input
    printf("Enter the annual interest rate (in percentage): ");
    scanf("%s", input);  // Read input as a string
    while (!is_valid_number(input)) {
        printf("Invalid input. Please enter a valid number for the interest rate: ");
        scanf("%s", input);  // Read input as a string
    }
    rate = atof(input);  // Convert string to float

    // get and validate the number of years input
    printf("Enter the number of years: ");
    scanf("%s", input);  // Read input as a string
    while (!is_valid_number(input)) {
        printf("Invalid input. Please enter a valid number for the number of years: ");
        scanf("%s", input);  // Read input as a string
    }
    years = atof(input);  // convert string to integer
    if(years<1)
    {
        printf("This calculator only calculates YEARLY compound interest:\n ");
        return 1;
    }
    // call the recursive function to calculate compound interest
    calculate_interest(&principal, rate, years);

    // display the result
    printf("The amount after %f years is: %.2f\n", years, principal);

    return 0;
}
