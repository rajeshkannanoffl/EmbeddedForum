#include <stdio.h>

int main(){
    int a = 10;
    int *ptr = &a;
    printf("%d", *ptr);     // Prints value stored in pointer
    printf("\n%p", ptr);    // Prints address of the variable
    printf("\n%p", &ptr);   // Prints address of the pointer
}