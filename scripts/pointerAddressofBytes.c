#include <stdio.h>

int main() {
    // Declare an integer variable 'a' and initialize it with a value
    int a = 2097224565;

    // Declare an integer pointer 'ptr' and initialize it with the address of 'a'
    int *ptr = &a;

    // Display the address of the variable 'a' using the pointer 'ptr'
    printf("Address of Value: %p", ptr);

    // Display the value stored at the address pointed to by 'ptr' (hexadecimal format)
    printf("\nValue of Pointer: %X", *ptr);
    
    // Declare a character pointer 'ptr1' and initialize it with the address of 'a'
    char *ptr1 = (char*)&a;

    // Display the base address of the variable 'a' as a character pointer
    printf("\nBase Address of the value: %p", ptr1);

    // Display the value of the first byte of 'a' (interpreted as a character)
    printf("\nByte 1: %X", *ptr1);

    // Display the next address of the variable 'a' (interpreted as a character)
    printf("\nNext Address of the value: %p", (ptr1 + 1));

    // Display the value of the second byte of 'a' (interpreted as a character)
    printf("\nByte 2: %X", *(ptr1 + 1));

    // Return 0 to indicate successful execution
    return 0;
}