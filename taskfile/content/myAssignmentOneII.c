/**
 * Program to extract and reverse the least significant bits of
   an each array element and return the modified array
*/

// Headers
#include <stdio.h>
#include <math.h>

// Macros
#define MAX_BITS 8
#define MASK_VALUE(n) (pow(2, n))-1
#define SUCCESSFUL 0
#define UNSUCCESSFUL 1

// Structure to pass elements to get user input
struct Elements {
    int array_size;
    unsigned char bit_reverse;
};

// Structure to pass elements to the function
typedef struct {
    int size;
    unsigned char *ptr;
    unsigned char no_bits;
} arguments_t;

// Function Declaration

// Function declared to print an array elements
void array_elements(unsigned char *, int);
// Function declared to process an array of unsigned char by reversing specified bits
unsigned char array_process(arguments_t *);
// Function declared to reverse the specified number of bits in an unsigned char
unsigned char bit_reverse(unsigned char, unsigned char);

/** Driver Code */
int main(){
    // Creating structure object to pass elements
    struct Elements e;
    // Input of the size of the array
    e.array_size = 0;
    printf("Enter the size of an array: ");
    scanf("%d", &e.array_size);

    // Input of the elements of the array from user
    unsigned char array[e.array_size];
    for(int i=0; i<e.array_size; i++){
        printf("Enter the array element - %d: ",(i+1));
        scanf("%hhu", &array[i]);
    }

    // Input of the number of bits to be reversed
    printf("\nEnter the no.of bits to be reversed: ");
    scanf("%hhd", &e.bit_reverse);

    // Print the list of array elements
    printf("\nList of array elements are: ");
    array_elements(array, e.array_size);

    // Creating struture variable to store the elements of the structure
    arguments_t parameters = {e.array_size, array, e.bit_reverse};
    // Creating structure pointer to store the elements of the structure
    arguments_t *arguments = &parameters;

    // Process and get the modified array by reversing the specified number of bits
    int result = 0;
    result = array_process(arguments);
    
    // Print the return value by identifying '0' or '1'
    if(result==SUCCESSFUL){
        // Print the list of modified array elements
        printf("\nList of modified array elements are: ");
        array_elements(array, e.array_size);
        // Prints if the program meets the condition as 0
        printf("\nProgram execution is successful");
    } else {
        // Prints if the program meets the condition as 1
        printf("\nProgram Execution is not successful");
    }
    return 0;
}

/**
 * Function: array_elements
 * ------------------
 * To Print the elements of an array
 * 
 * get_array: pointer to an array elements
 * get_array_size: size of an array
 * 
 * returns: returns nothing
*/
void array_elements(unsigned char *get_array, int get_array_size){
    for(int i=0; i<get_array_size; i++){
        // To print the array elements
        printf("%d ", get_array[i]);
    }
}

/**
 * Function: array_process
 * -----------------------
 * the bit reversal of numbers in array for given number of bits
 * 
 * size: size of an array
 * ptr: pointer to the array elements
 * no_bits: number of bits to be reversed
 * 
 * returns: returns the status as successful or not successful
*/
unsigned char array_process(arguments_t *arguments){
    // Return unsuccessful if the following parameters are satisfied
    if(arguments->size<=0 || arguments->ptr==NULL || arguments->no_bits>MAX_BITS){
        return UNSUCCESSFUL;
    }
    // Create a bitmask for the specified number of bits
    unsigned char mask = MASK_VALUE(arguments->no_bits);
    // Create an unsigned char to store the reversed bits
    unsigned char original_value, reversed_value, processed_value;
    for (int i=0; i<arguments->size; i++){
        original_value = arguments->ptr[i];
        // Extract the bits from the element to be reversed and stored it in a pointer
        arguments->ptr[i] = arguments->ptr[i] & mask;
        // Reverse the specified number of bits in the current array element
        reversed_value = bit_reverse(arguments->ptr[i], arguments->no_bits);
        // Clear and Set the the bits to be reversed in the current array element using the bitmask
        processed_value = (arguments->ptr[i]&(~mask)) | reversed_value;
        // Comparing the original value with processed value for the output
        if(original_value <= processed_value){
            // Prints processed value if the processed value is greater than original value
            arguments->ptr[i] = processed_value;
        } else {
            // Prints original value if the original value is greater than processed value
            arguments->ptr[i] = original_value;
        }
    }
    return SUCCESSFUL;
}

/**
 * Function: bit_reverse
 * ----------------------
 * Returns the reversed bit of an element
 * 
 * num: element to be reversed
 * nbits: number of bits to be reversed
 * 
 * returns: reversed bit of an element
*/
unsigned char bit_reverse(unsigned char num, unsigned char n_bits){
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