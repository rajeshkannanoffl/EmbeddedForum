#include <stdio.h>

// Function that returns a pointer to an integer (Local variable)
int* func() {
    // Local Variable 'a' with automatic storage duration
    // Add static to return local variable
    int a = 10;

    // Print the address of local variable 'a'
    printf("%p", &a);

    // Return the address of local variable 'a'
    return &a;
}

int main() {
    int *ptr;   // Declare a pointer to an integer

    // Call the function and assign the returned pointer to 'ptr'
    ptr = func();

    // Print the value of 'ptr' (which points to a local variable in func)
    printf("\n%p", ptr);

    // Return 0 to indicate successful execution
    return 0;
}
