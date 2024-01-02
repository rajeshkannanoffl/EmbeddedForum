#include <stdio.h>

int main() {
    // Declare an unsigned char variable 'a' and initialize it with hexadecimal value 0xD3 (binary: 11010011)
    unsigned char a = 0xD3;

    // Declare an unsigned char variable 'b' to store the result
    unsigned char b;

    // Perform bitwise XOR operation on 'a' and the value 6, and store the result in 'b'
    // XORing with 6 effectively toggles the 3rd and 4th bits of 'a'
    b = a ^ 6;

    // Display the result in hexadecimal format
    printf("Value: %X", b);

    // Return 0 to indicate successful execution
    return 0;
}