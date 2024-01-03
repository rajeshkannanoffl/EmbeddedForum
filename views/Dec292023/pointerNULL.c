#include <stdio.h>

int main() {
    // Declaring a pointer and initializing it to NULL
    int *ptr = NULL;  

    // Checking if the pointer is NULL
    if (ptr == NULL) {
        printf("It's a Null pointer");
    } else {
        printf("It's not a null pointer");
    }

    // Printing the memory address (which is NULL)
    printf("\n%p", ptr);

    // Return 0 to indicate successful execution
    return 0;
}
