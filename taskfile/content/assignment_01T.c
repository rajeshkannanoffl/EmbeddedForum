/**
 * COI-2_Assignment-1
 * 
 * Program that takes an array and bit reverses the specified number of bits
 * of each element and modifies the values in place.
*/

// Headers
#include <stdio.h>
#include <math.h>

// Macros
#define MAX_BITS 8
#define SUCCESSFULL 1
#define UNSUCCESSFULL -1

// Structure to pass the elements
typedef struct {
    unsigned char size;
    unsigned char *ptr;
    unsigned char no_bits;
}arguments_t;

// Function to return the bit reverse of a given number
unsigned char reverse_bits(unsigned char, unsigned char);

// Function to compute the bit reversal of numbers in array for given number of bits
int array_process(arguments_t);

// Function to print the elements of an array
void printArr(unsigned char *, int);

/**
 * Driver program
*/
int main()
{
    int status;
    
    // Example 1
    unsigned char arr1[] = {3, 4, 10, 2, 33, 78, 11, 200};
    arguments_t args1 = {8, arr1, 3};
    
    printf("Before: ");
    printArr(arr1, 8);

    status = array_process(args1);

    printf("\nAfter: ");
    printArr(arr1, 8);

    (status == SUCCESSFULL)? printf("\nSUCCESSFULL\n\n"): printf("\nUNSUCCESSFULL\n\n");
    
    // Example 2
    unsigned char arr2[] = {3, 4, 10, 2, 33, 78};
    arguments_t args2 = {6, arr2, 4};

    printf("Before: ");
    printArr(arr2, 6);

    status = array_process(args2);

    printf("\nAfter: ");
    printArr(arr2, 6);

    (status == SUCCESSFULL)? printf("\nSUCCESSFULL\n\n"): printf("\nUNSUCCESSFULL\n\n");


    ///USER INPUT CODE/////////////////////////////////////////////////////////
    
    int size, temp;
    unsigned char num_bits;
    
    printf("Enter the size of array: ");
    scanf("%d", &size);
    
    unsigned char arr[size];
    printf("Enter the values for the array:\n");
    for(long int i=0; i<size; i++) {
        scanf("%d", &temp);
        if(temp < 1) {
            arr[i] = 1;
        }
        else if(temp > 255) {
            arr[i] = 255;
        } else {
            arr[i] = temp;
        }
    }
    
    printf("Enter the number of bits to reverse: ");
    scanf("%hhu", &num_bits);
    
    arguments_t args = {size, arr, num_bits};
    
    printf("Before: ");
    printArr(arr, size);
    
    status = array_process(args);
    printf("\nAfter: ");
    
    printArr(arr, size);
    (status == SUCCESSFULL)? printf("\nSUCCESSFULL\n\n"): printf("\nUNSUCCESSFULL\n\n");
    
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
unsigned char reverse_bits(unsigned char num, unsigned char nbits) {
    
    unsigned char rnum = 0;
    
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
 * args: structure that contains the arguments needed to process the array
 * 
 * returns: returns nothing. (Performs in place computation of values in array)
*/
int array_process(arguments_t args) {
    
    // Error handling
    if(args.size <= 0 || args.ptr == NULL || args.no_bits > MAX_BITS) {
        return UNSUCCESSFULL;
    }
    
    // Find the mask value to extract the reqired bits
    unsigned char mask_value = (unsigned char)(pow(2, args.no_bits) - 1);
    unsigned char b, original_value, processed_value;

    for(int i=0; i<args.size; i++) {
        // Saving the original value
        original_value = args.ptr[i];
        
        // Extract the required bits
        b = args.ptr[i] & mask_value;
        
        // Clear the bits that we extracted from the original number
        // to then later modify them
        args.ptr[i] = args.ptr[i] & ~(mask_value);
        
        // Reverse the extracted bits
        b = reverse_bits(b, args.no_bits);
        
        // Modify the original number using the extracted bits we reversed
        processed_value = args.ptr[i] | b;
        
        // Storing only the greater value between original and processed value
        if(processed_value > original_value) {
            args.ptr[i] = processed_value;
        } else {
            args.ptr[i] = original_value;
        }
    }
    
    return SUCCESSFULL;
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
}