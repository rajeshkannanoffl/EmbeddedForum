#include <stdio.h>
int main(){
    unsigned char a = 0x7B;
    unsigned char res;
    res = (a>>3)&1;
    printf("Extracted value: %u", res);
    return 0;
}