#include <stdio.h>

int main() {
    // Declaring a Void Pointer
    void *ptr ;

    // Initializing variables
    int a = 10;
    char b = 'A';
    char *str = "Hello";

    // Pointing to an Integer
    ptr = &a;
    // Printing the memory address and the integer by typecasting
    printf("%p - %d\n", ptr, *(int*)ptr);

    // Pointing to a Character
    ptr = &b;
    // Printing the memory address and the character by typecasting
    printf("%p - %c\n", ptr, *(char*)ptr);

    // Pointing to a String
    ptr = str;
    // Printing the memory address and the second character in the string
    printf("%p - %c\n", ptr, *((char*)ptr+1));

    // Return 0 to indicate successful execution
    return 0;
}
