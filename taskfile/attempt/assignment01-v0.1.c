#include <stdio.h>
int bitReverse(unsigned char num, unsigned char n_bits){
    unsigned char res = 0;
    for(int i=0; i<n_bits; i++){
        res<<=1;
        if((num&1)==1){
            res|=1;
        }
        num>>=1;
    }
    return res;
}

int array_process(int size, unsigned char *ptr, unsigned char no_bits){
    unsigned char value;
    for (int i=0; i<size; i++){
        //value = ptr[i]&7;
        value = bitReverse(value, no_bits);
        ptr[i] = ptr[i]&(~7);
        ptr[i] = ptr[i] | value;
        printf("%d ", ptr[i]);
    }
    return 0;
}

int main(){
    unsigned char arr[] = {3, 4, 10, 2, 33, 78, 11, 200};
    int arr_size = sizeof(arr);
    array_process(arr_size, arr, 3);
    return 0;
}