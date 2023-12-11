/**
 * COI-2_Assignment-1
 * 
 * A program that takes an array and bit reverses the specified number of bits
 * of each element and modifies the values in place.
*/


#include <stdio.h>
#include <math.h>


// Function to return the bit reverse of a given number
unsigned int reverse_bits(unsigned char num, unsigned char nbits);

// Function to compute the bit reversal of numbers in array for given number of bits
int array_process(int size, unsigned char *ptr, unsigned char no_bits);

// Function to print the elements of an array
void printArr(unsigned char *ptr, int size);


/**
 * Driver program
*/
int main()
{
    int retVal;
    
    // Example 1
    /*unsigned char arr1[] = {3, 4, 10, 2, 33, 78, 11, 200};

    printf("Before: ");
    printArr(arr1, 8);

    retVal = array_process(8, arr1, 3);

    printf("After: ");
    printArr(arr1, 8);

    (retVal == 1)? printf("SUCCESSFULL\n\n"): printf("UNSUCCESSFULL\n\n");
    
    // Example 2
    unsigned char arr2[] = {3, 4, 10, 2, 33, 78};

    printf("Before: ");
    printArr(arr2, 6);

    retVal = array_process(6, arr2, 4);

    printf("After: ");
    printArr(arr2, 6);

    (retVal == 1)? printf("SUCCESSFULL\n\n"): printf("UNSUCCESSFULL\n\n");*/


    ///USER INPUT CODE/////////////////////////////////////////////////////////
    int N;
    unsigned char num_bits;
    
    printf("Enter the size of array: ");
    scanf("%d", &N);
    
    unsigned char arr[N];
    
    printf("Enter the values for the array:\n");
    for(int i=0; i<N; i++) {
        scanf("%hhu", &arr[i]);
    }
    
    printf("Enter the number of bits to reverse: ");
    scanf("%hhu", &num_bits);
    
    printf("Before: ");
    printArr(arr, N);

    retVal = array_process(N, arr, num_bits);

    printf("After: ");
    printArr(arr, N);
    
    (retVal == 1)? printf("SUCCESSFULL\n\n"): printf("UNSUCCESSFULL\n\n");

    return 0;
}


/**
 * Function: reverse_bits
 * ----------------------
 * Returns the bit reverse of the given number
 * 
 * num: number to be reversed
 * nbits: number of bits to be reversed
 * 
 * returns: bit reverse of num
*/
unsigned int reverse_bits(unsigned char num, unsigned char nbits) {
    
    unsigned int rnum = 0;
    
    // Iterate through every bit of the given number
    while(nbits > 0) {
        
        // Left shift the result every iteration
        rnum <<= 1;
        
        // Check if the LSB is set in given number
        if(num & 1) {
            rnum |= 1; // Set the LSB of result if true
        }
        
        // Right shift the given number 
        // so as to extract the next bit in the next iteration
        num >>= 1;
        
        // Decrement at the end of going through each bit
        nbits--;
    }
    
    return rnum;
}


/**
 * Function: array_process
 * -----------------------
 * Computes the bit reversal of numbers in array for given number of bits
 * 
 * size: size of the given arrayy
 * ptr: pointer to the array
 * no_bits: number of bits to be reversed
 * 
 * returns: returns nothing. (Performs in place computation of values in array)
*/
int array_process(int size, unsigned char *ptr, unsigned char no_bits) {
    
    // Error handling
    if(ptr == NULL || no_bits > 8) {
        return -1;
    }
    
    // Find the mask value to extract the reqired bits
    unsigned char mask_value = (unsigned char)(pow(2, no_bits) - 1);
    
    unsigned char b;
    for(int i=0; i<size; i++) {
        
        // Extract the required bits
        b = ptr[i] & mask_value;
        
        // Clear the bits that we extracted from the original number
        // to then later modify them
        ptr[i] = ptr[i] & ~(mask_value);
        
        // Reverse the extracted bits
        b = reverse_bits(b, no_bits);
        
        // Modify the original number using the extracted bits we reversed
        ptr[i] = ptr[i] | b;
    }
    
    return 1;
}


/**
 * Function: printArr
 * ------------------
 * Prints the elements of an array
 * 
 * ptr: pointer to the array
 * size: size of the array
 * 
 * returns: returns nothing
*/
void printArr(unsigned char *ptr, int size) {
    
    for(long int i=0; i<size; i++) {
        printf("%hhu ", ptr[i]);
    }
    printf("\n");
}