#include <stdio.h>

int main() {
    // Declare an integer variable 'i' and initialize it with the value 12
    int i = 12;

    // Declare an integer pointer 'ptr' and initialize it with the address of 'i'
    int *ptr = &i;

    // Dereference the pointer and assign the value 22 to the variable 'i'
    *ptr = 22;

    // Display the value of 'i' after modification
    printf("%d", i);

    // Display the value pointed to by 'ptr' (should be the same as the modified value of 'i')
    printf("\n%d", *ptr);

    // Return 0 to indicate successful execution
    return 0;
}