#include <stdio.h>
#include <math.h>

// Function declared to print an array elements
int array_elements(unsigned char *, int);
// Function declared to process an array of unsigned char by reversing specified bits
int array_process(int, unsigned char *, unsigned char);
// Function declared to reverse the specified number of bits in an unsigned char
int bit_reverse(unsigned char, unsigned char);

int main(){
    int array_size;
    // Input of the size of the array
    printf("\nEnter the size of an array: ");
    scanf("%d", &array_size);

    unsigned char array[array_size];
    // Input of the elements of the array from user
    for(int i=0; i<array_size; i++){
        printf("Enter the array element - %d: ",(i+1));
        scanf("%hhu", &array[i]);
    }

    unsigned char bit_reverse;
    // Input of the number of bits to be reversed
    printf("\nEnter the no.of bits to be reversed: ");
    scanf("%hhd", &bit_reverse);

    // Print the list of array elements
    printf("\nList of array elements are: ");
    array_elements(array, array_size);
    
    int result = 0;
    // Process and get the modified array by reversing the specified number of bits
    result = array_process(array_size, array, bit_reverse);
    
    // Print the return value by identifying '1' or '-1'
    if(result==1){
        // Print the list of modified array elements
        printf("\nList of modified array elements are: ");
        array_elements(array, array_size);
        printf("\nSuccessful");
    } else {
        printf("\nNot Successful");
    }
    return 0;
}

// Function to print an array elements get from the user
int array_elements(unsigned char *get_array, int get_array_size){
    for(int i=0; i<get_array_size; i++){
        // To print the array elements
        printf("%d ", get_array[i]);
    }
    return 0;
}

// Function to process an array of unsigned char by reversing specified bits
int array_process(int size, unsigned char *ptr, unsigned char no_bits){
    if(size==0 || ptr==NULL || no_bits>8){
        return -1;
    }
    // Create a bitmask for the specified number of bits
    unsigned char mask = (pow(2, no_bits))-1;
    // Create an unsigned char to store the reversed bits
    unsigned char reversed_value;
    for (int i=0; i<size; i++){
        // Reverse the specified number of bits in the current array element
        reversed_value = bit_reverse(ptr[i], no_bits);
        // Clear and Set the the bits to be reversed in the current array element using the bitmask
        ptr[i] = (ptr[i]&(~mask)) | reversed_value;
    }
    return 1;
}

// Function to reverse the specified number of bits in an unsigned char
int bit_reverse(unsigned char num, unsigned char n_bits){
    // Temporary variable to store the reversed bits
    unsigned char result = 0;
    for(int i=0; i<n_bits; i++){
        // Left shift 'result' to set the next bit
        result<<=1;
        // Set the least significant bit if the current bit in 'num' is 1
        if((num&1)==1){
            result|=1;
        }
        // Right shift 'num' to process the next bit
        num>>=1;
    }
    return result;
}