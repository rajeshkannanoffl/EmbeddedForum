#include <stdio.h>
int main(){
    int a = 2097224565;
    int *ptr = &a;
    printf("Address of Value: %p", ptr);
    printf("\nValue of Pointer: %X", *ptr);
    
    char *ptr1 = (char*)&a;
    printf("\nBase Address of the value: %p", ptr1);
    printf("\nByte 1: %X", *ptr1);
    printf("\nNext Address of the value: %p", (ptr1+1));
    printf("\nByte 2: %X", *(ptr1+1));
    return 0;
}