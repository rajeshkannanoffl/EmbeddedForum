#include <stdio.h>

int main() {
    // Declare a character variable 'c' and initialize it with the value 100
    char c = 100;

    // Display the address of the variable 'c'
    printf("Address of the variable: %p\n", &c);

    // Declare a character pointer 'ptr' and initialize it with the address of 'c'
    char *ptr = &c;

    // Dereference the pointer and assign the value to a new character variable 'd'
    char d = *ptr;

    // Display the value of 'd' (should be the same as the value of 'c')
    printf("Data: %d\n", d);

    // Change the value of the variable through the pointer
    *ptr = 65;

    // Display the updated value of the variable 'c'
    printf("Value of the variable: %d", c);

    // Return 0 to indicate successful execution
    return 0;
}