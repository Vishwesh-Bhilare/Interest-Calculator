# Compound Interest Calculator (C Program)

This is a simple C program that calculates compound interest using recursion. The program prompts the user to enter the principal amount, annual interest rate, and the number of years, then computes the amount after the specified number of years based on compound interest.

## Features

- **Recursive Calculation**: The compound interest is calculated recursively.
- **Input Validation**: Ensures all inputs (principal, interest rate, and number of years) are positive numbers and handles invalid inputs gracefully.
- **User-Friendly Interface**: Guides the user through the process with clear prompts and error messages when the input is incorrect.

## How It Works

The program works by using the formula for compound interest:

P = P * ( 1 + r/100)

Where:
-  A  is the amount after n  years.
-  P  is the principal amount.
-  r  is the annual interest rate (in percentage).
-  n  is the number of years.

### Steps:
1. The program asks the user to input the principal amount.
2. It then asks for the annual interest rate (as a percentage).
3. Next, the user is prompted for the number of years.
4. The program validates the inputs to ensure they are numeric and positive.
5. It calculates the compound interest recursively.
6. Finally, the program outputs the amount after the specified number of years.

## File Structure

- `compound_interest_calculator.c`: The main C program that handles the compound interest calculation.
- `README.md`: Documentation for the project.

## Example Usage

### Sample Run:

```
Enter the principal amount: 1000
Enter the annual interest rate (in percentage): 5
Enter the number of years: 10
The amount after 10 years is: 1628.89
```

Explanation:
In this example, the user enters:
```
A principal of 1000
An annual interest rate of 5%
A period of 10 years
The program calculates the amount after 10 years and displays it as 1628.89.
```

Code Explanation
Functions:
```
is_valid_number(char *input):
```

This function checks if the input is a valid number (it can contain only digits and one decimal point, if any). It returns 1 if the number is valid, otherwise 0.
calculate_interest(float *principal, float rate, int years):

This recursive function calculates the compound interest. It multiplies the principal by (1 + rate / 100) for each year recursively until the number of years reaches zero.
Input Validation:
The program ensures that the input is a valid number and that the principal amount, interest rate, and number of years are positive.
Error Handling:
The program checks for:
Negative or zero principal: The program will display an error if the principal is less than or equal to zero.
Negative interest rate: The interest rate cannot be negative.
Non-positive years: The number of years must be greater than zero.
Compilation and Running Instructions
Prerequisites
You need a C compiler (such as GCC) to compile and run this program. If you're using a Linux-based system, GCC is likely already installed. On Windows, you can use MinGW or any other C compiler.



Follow the prompts to enter the principal amount, interest rate, and number of years.
