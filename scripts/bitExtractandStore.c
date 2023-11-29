#include <stdio.h>
int main(){
    unsigned char a = 0xDF;
    unsigned char res, res1;
    // extract for last 3 bits
    res = a&7;
    // extract for last 4 bits
    res1 = a&15;
    printf("Extracted value: %X", res);
    printf("\tExtracted value: %X", res1);
    return 0;
}