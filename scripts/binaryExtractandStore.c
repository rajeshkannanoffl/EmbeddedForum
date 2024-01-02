#include <stdio.h>

int main() {
    // Declare an unsigned char variable and initialize it with hexadecimal value 0xDF (binary: 11011111)
    unsigned char a = 0xDF;

    // Declare variables to store the extracted values
    unsigned char res, res1;

    // Extract the last 3 bits of the binary representation of 'a'
    res = a & 7; // Binary '7' is 00000111

    // Extract the last 4 bits of the binary representation of 'a'
    res1 = a & 15; // Binary '15' is 00001111

    // Display the extracted values in hexadecimal format
    printf("Extracted value (last 3 bits): %X", res);
    printf("\tExtracted value (last 4 bits): %X", res1);

    // Return 0 to indicate successful execution
    return 0;
}
