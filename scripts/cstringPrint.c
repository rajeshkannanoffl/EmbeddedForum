#include <stdio.h>
#include <string.h>
int main(){
    char str1[10] = "Hello";
    char *str2 = (char *)"5675675765World";
    printf("%s", strcat(str1, str2));
    return 0;
}