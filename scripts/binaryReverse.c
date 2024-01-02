#include <stdio.h>

// Function to reverse the bits of an unsigned char
unsigned char bitReverse(unsigned char n) {
    unsigned char num = 0;

    // Iterate through each bit of the input 'n'
    for (int i = 0; i < 8; i++) {
        // Left shift 'num' by 1 to make room for the next bit
        num <<= 1;

        // Check if the rightmost bit of 'n' is 1
        if ((n & 1) == 1) {
            // If yes, set the rightmost bit of 'num' to 1
            num |= 1;
        }

        // Right shift 'n' by 1 to process the next bit
        n >>= 1;
    }

    // Return the reversed bit value
    return num;
}

int main() {
    // Initialize an unsigned char variable 'a' with hexadecimal value 0x0C (binary: 00001100)
    // After reversing the bits, it should become 0xD0 (binary: 11010000)
    unsigned char a = 0x0C;

    // Display the reversed bit value in hexadecimal format
    printf("Reversed Bit Value: %X", bitReverse(a));

    // Return 0 to indicate successful execution
    return 0;
}