#include <stdio.h>
int main(){
    // get values from user for the operation as integers.
    int a,b;
    printf("Enter value 1: ");
    scanf("%d", &a);
    printf("Enter value 2: ");
    scanf("%d", &b);
    // Using '<<' we can do left shift.
    printf("Left Shift: %d", a<<2);
    // Using '>>' we can do left shift.
    printf("\nRight Shift: %d", a>>3);
    return 0;
}