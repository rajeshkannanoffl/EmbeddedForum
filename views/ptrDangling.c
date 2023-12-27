#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare a pointer to an integer named ptr (wild pointer)
    int *ptr;

    // Allocate memory for ptr integer using malloc
    ptr = (int*)malloc(sizeof(int));
    
    // Print the memory address where the allocated memory block starts
    printf("%p", ptr);

    // Free the dynamically allocated memory
    free(ptr);

    // Attempt to print the memory address again (undefined behavior after free)
    printf("\n%d", *ptr);

    // Return 0 to indicate successful execution
    return 0;
}








// int* func(){
//     // Local Variable
//     int a = 10;
//     printf("%p", &a);
//     return &a;
// }
// int main(){
//     int *ptr = NULL;
//     ptr = func();
//     printf("\n%p", ptr);
//     return 0;
// }













//  #25 = static

