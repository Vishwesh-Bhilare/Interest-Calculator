#include <stdio.h>

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
    float principal, rate;
    int years;

    // Get user input
    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    printf("Enter the annual interest rate (in percentage): ");
    scanf("%f", &rate);
    printf("Enter the number of years: ");
    scanf("%d", &years);

    // Call the recursive function to calculate compound interest
    calculate_interest(&principal, rate, years);

    // Display the result
    printf("The amount after %d years is: %.2f\n", years, principal);
    
    return 0;
}
