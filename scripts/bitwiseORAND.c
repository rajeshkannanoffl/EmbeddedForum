#include <stdio.h>

int main() {
    // Declare variables to store user-input values
    int a, b;

    // Prompt the user to enter the first value
    printf("Enter value 1: ");
    // Read the first value from user input
    scanf("%d", &a);

    // Prompt the user to enter the second value
    printf("Enter value 2: ");
    // Read the second value from user input
    scanf("%d", &b);

    // Perform bitwise AND operation on 'a' and 'b', and display the result
    printf("Bitwise AND Operation: %d", a & b);

    // Perform bitwise OR operation on 'a' and 'b', and display the result
    printf("\nBitwise OR Operation: %d", a | b);

    // Return 0 to indicate successful execution
    return 0;
}