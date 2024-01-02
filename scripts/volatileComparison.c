#include <stdio.h>

int main() {
    // Declare a volatile integer variable 'data' (volatile is used to indicate that the value may change at any time)
    volatile int data = 0;

    // Assign the value 5 to the variable 'data'
    data = 5;

    // Assign the value 5 to the variable 'data' again (volatile ensures that the compiler does not optimize away the assignment)
    data = 5;

    // Display the current value of the variable 'data'
    printf("%d\n", data);

    // Return 0 to indicate successful execution
    return 0;
}