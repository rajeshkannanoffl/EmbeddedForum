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

    // Perform left shift on 'a' by 2 positions and display the result
    printf("Left Shift: %d", a << 2);

    // Perform right shift on 'a' by 3 positions and display the result
    printf("\nRight Shift: %d", a >> 3);

    // Return 0 to indicate successful execution
    return 0;
}