#include <stdio.h>

int main() {
    // Declaration of a wild pointer
    int *ptr;
    // Attempting to dereference the wild pointer (undefined behavior)
    printf("%d", *ptr);
    // Return 0 to indicate successful execution
    return 0;
}
