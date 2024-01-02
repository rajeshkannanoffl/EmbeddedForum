#include <stdio.h>

int main() {
    // Declare an integer variable 'a' and initialize it with the value 10
    int a = 10;

    // Declare an integer pointer 'ptr' and initialize it with the address of 'a'
    int *ptr = &a;

    // Display the value stored at the address pointed to by 'ptr' (dereferencing)
    printf("%d", *ptr);

    // Display the address stored in the pointer 'ptr' (address of the variable 'a')
    printf("\n%p", ptr);

    // Display the address of the pointer 'ptr' itself
    printf("\n%p", &ptr);

    // Return 0 to indicate successful execution
    return 0;
}