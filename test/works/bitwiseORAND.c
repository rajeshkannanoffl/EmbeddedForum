#include <stdio.h>
int main(){
    // get values from user for the operation as integers.
    int a,b;
    printf("Enter value 1: ");
    scanf("%d", &a);
    printf("Enter value 2: ");
    scanf("%d", &b);
    // Using '&' we can do bitwise AND operation.
    printf("Bitwise AND Operation: %d", a&b);
    // Using '|' we can do bitwise OR operation.
    printf("\nBitwise OR Operation: %d", a|b);
    return 0;
}
