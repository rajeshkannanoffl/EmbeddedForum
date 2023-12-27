#include <stdio.h>
int main(){
    volatile int data = 0;
    data = 5;
    data = 5;
    printf("%d\n", data);
    return 0;
}