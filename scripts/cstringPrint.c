#include <stdio.h>
#include <string.h>

int main() {
    // Declare a character array 'str1' and initialize it with the string "Hello"
    char str1[10] = "Hello";

    // Declare a character pointer 'str2' and initialize it with the string "5675675765World"
    char *str2 = (char *)"5675675765World";

    // Use strcat function to concatenate 'str2' to 'str1'
    // Note: Ensure that 'str1' has enough space to accommodate the concatenated string
    printf("%s", strcat(str1, str2));

    // Return 0 to indicate successful execution
    return 0;
}