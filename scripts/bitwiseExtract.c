#include <stdio.h>

int main() {
    // Initialize an unsigned char variable 'a' with hexadecimal value 0x7B (binary: 0111 1011)
    unsigned char a = 0x7B;

    // Declare a variable to store the extracted bit
    unsigned char res;

    // Right shift 'a' by 3 positions to move the fourth binary value to the rightmost position
    // Use a bitwise AND operation with 1 to extract the rightmost bit
    res = (a >> 3) & 1;

    // Display the extracted value (should be the fourth binary value)
    printf("Extracted value: %u", res);

    // Return 0 to indicate successful execution
    return 0;
}