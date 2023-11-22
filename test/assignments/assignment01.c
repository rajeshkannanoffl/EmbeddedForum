#include <stdio.h>
#include <math.h>

// Function to reverse the specified number of bits in an unsigned char
int bitReverse(unsigned char num, unsigned char n_bits){
    unsigned char res = 0;
    for(int i=0; i<n_bits; i++){
        // Left shift the result
        res<<=1;
        // Set the least significant bit if the current bit in 'num' is 1
        if((num&1)==1){
            res|=1;
        }
        // Right shift 'num' to process the next bit
        num>>=1;
    }
    return res;
}

// Function to process an array of unsigned char by reversing specified bits
int array_process(int size, unsigned char *ptr, unsigned char no_bits){
    // Create a bitmask for the specified number of bits
    unsigned char mask = (pow(2, no_bits))-1;
    // Create an unsigned char to store the reversed bits
    unsigned char value;
    for (int i=0; i<size; i++){
        // Reverse the specified number of bits in the current array element
        value = bitReverse(ptr[i], no_bits);
        // Clear the bits to be reversed in the current array element using the bitmask
        ptr[i] &=(~mask);
        // Set the reversed bits in the current array element
        ptr[i] |= value;
        // Print the modified array element
        printf("%d ", ptr[i]);
    }
    return 0;
}

int main(){
    int arr_size;
    // Input of the size of the array
    printf("Enter the size of an array: ");
    scanf("%d", &arr_size);

    unsigned char arr[arr_size];
    // Input of the elements of the array from user
    for(int i=0; i<arr_size; i++){
        printf("Enter the array element - %d: ",(i+1));
        scanf("%hhu", &arr[i]);
    }

    unsigned char bit_reverse;
    // Input of the number of bits to be reversed
    printf("Enter the no.of bits to be reversed: ");
    scanf("%hhd", &bit_reverse);

    // Process and get the modified array by reversing the specified number of bits
    array_process(arr_size, arr, bit_reverse);
    return 0;
}