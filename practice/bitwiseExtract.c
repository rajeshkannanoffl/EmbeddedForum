#include <stdio.h>
int main(){
    unsigned char a = 0x7B; //0b0111 1011
    unsigned char res;
    // Extracting the fourth binary value
    res = (a>>3)&1;
    printf("Extracted value: %u", res);
    return 0;
}