#include <stdio.h>
unsigned char bitReverse(unsigned char n){
    int num = 0;
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
    unsigned int a=0x0B;    //0000 1011 -> 1101 0000
    printf("Reversed Bit Value: %X", bitReverse(a));
    return 0;
}