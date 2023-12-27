#include <stdio.h>
int main(){
    int i=12;
    int *ptr=&i;
    *ptr=22;
    printf("%d",i);
    printf("\n%d", *ptr);
}