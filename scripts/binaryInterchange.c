#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Define the size of binary values
#define SIZE 8

int main() {
    // Declare two character arrays to store binary values
    char first_value[SIZE + 1], second_value[SIZE + 1];

    // Prompt user to enter a binary value
    printf("Enter the binary value: ");
    
    // Read the binary value from the user input
    scanf("%s", first_value);

    // Initialize a flag to keep track of the processing state
    int flag = 0;

    // Iterate through each bit of the binary value
    for (int i = SIZE - 1; i >= 0; i--) {
        // Check if the current bit is '1' and the flag is not set
        if (first_value[i] == '1' && flag == 0) {
            second_value[i] = first_value[i];
            flag++;  // Set the flag to indicate the first '1' is found
        } else if (flag == 1) {
            // Flip the bits after encountering the first '1'
            if (first_value[i] == '1') {
                second_value[i] = '0';
            } else {
                second_value[i] = '1';
            }
        } else {
            // Copy bits as-is before encountering the first '1'
            second_value[i] = first_value[i];
        }
    }

    // Null-terminate the second binary value
    second_value[SIZE] = '\0';

    // Display the result of the binary value manipulation
    printf("Result of binary value: %s\n", second_value);

    // Return 0 to indicate successful execution
    return 0;
}