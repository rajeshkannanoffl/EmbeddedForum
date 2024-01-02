#include <stdio.h>

int main() {
    int a;

    // Print the segment address of variable 'a' (unspecified behavior, typically prints a random memory address)
    printf("%p ", a);

    // Print the offset address of variable 'a' (the memory address where 'a' is stored)
    printf("%p ", &a);

    // Print the formatted output of segment address : offset address for variable 'a'
    // Note: Using %Fp to format the output, %p for printing pointer values
    printf("%Fp ", a);

    // Return 0 to indicate successful execution
    return 0;
}
