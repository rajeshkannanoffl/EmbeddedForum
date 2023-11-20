#include <stdio.h>
#include <conio.h>
#include  <stdlib.h>
#define SIZE 8

int main(){
    char first_value[SIZE+1], second_value[SIZE+1];
    printf("Enter the binary value: ");
    scanf("%s", first_value);

    int flag=0;
    for(int i=SIZE-1; i>=0; i--){
        if(first_value[i]=='1' && flag==0){
            second_value[i] = first_value[i];
            flag++;
        }
        else if(flag==1){
            if(first_value[i]=='1'){
                second_value[i] = '0';
            } else {
                second_value[i] = '1';
            }
        } else {
            second_value[i] = first_value[i];
        }
    }
    second_value[SIZE+1]='\0';
    printf("Result of binary value: %s\n", second_value);
    return 0;
}