#include <stdio.h>
unsigned char bitReverse(unsigned char n){
    unsigned char num = 0;
    for(int i=0; i<8; i++){
        num<<=1;
        if((n&1)==1){
            num|=1;
        }
        n>>=1;
    }
    return num;
}
int main(){
    unsigned char a=0x0C;    //0000 1011 -> 1101 0000
    printf("Reversed Bit Value: %X", bitReverse(a));
    return 0;
}