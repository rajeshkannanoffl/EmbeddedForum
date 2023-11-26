#include <stdio.h>
int main(){
    unsigned char a=0xD3;
    unsigned char b;
    b = a^6;               // XOR - Diff is O/P.
    printf("Value: %X", b);
    return 0;
}