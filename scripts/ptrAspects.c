#include <stdio.h>
int main(){
    char c = 100;
    printf("Address of the variable: %p\n", &c);

    char *ptr = &c;
    char d = *ptr;
    printf("Data: %d\n", d);
    
    *ptr = 65;
    printf("Value of the variable: %d", c);
    return 0;
}