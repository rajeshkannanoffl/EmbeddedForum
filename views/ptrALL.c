#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare a pointer to an integer named ptr (uninitialized) (wild pointer)
    int *ptr;

    // Print the uninitialized memory address of the pointer
    printf("\nPointer Memory address : %p", ptr);

    // Allocate memory for ptr integer using malloc
    ptr = (int*)malloc(sizeof(int));

    // Check if memory allocation was successful (Error Handling)
    if (ptr == NULL) {
        printf("\nMemory is Not Allocated");
    } else {
        printf("\nMemory is Allocated");
    }

    // Print the memory address where the allocated memory block starts
    printf("\nPointer Memory Address: %p", ptr);

    // Free the dynamically allocated memory, creating a dangling pointer
    free(ptr);

    // Print the memory address of the dangling pointer
    printf("\nDangling Pointer Address: %p", ptr);

    // Set the pointer to NULL to avoid accidental misuse
    ptr = NULL;

    // Print the NULL pointer address
    printf("\nNULL Pointer Address: %p", ptr);

    // Return 0 to indicate successful execution
    return 0;
}
