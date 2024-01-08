#include "gtest/gtest.h"
#include "string.h"
#include "stdbool.h"
#include <math.h> 

bool isPrime(int val) {
    int check = 1; 
    for (int i = 2; i <= sqrt(val); i++) { 
        if (val % i == 0) { 
            check = 0; 
            break; 
        } 
    } 
    if (val <= 1) { 
        check = 0; 
    } 
    if (check == 1) { 
        return true; 
    }
    else {
        return false; 
    }
}

bool isFactorial(int val1, int val2) {
    int i;
    int fact1 = 1;
    for (i = 1; i <= val1; i++)
    {
        fact1 = fact1 * i;
    }
    return fact1==val2 ? 1 : 0;
}

bool testInt(int option, int val1, int val2) {
    switch(option) {
        // Compare the integers
        case 1:
            return val1 == val2;
        break;
        // Check if val2 is factorial of val1
        case 2:
        {
            return isFactorial(val1, val2);
        }
        break;
        // Check if val1 is a prime number
        case 3:
            return isPrime(val1);
        break;
        default:
            return 1;
        break;
    }
}

bool testStrings(int option, char* val1, char* val2) {
    
    switch(option) {
        // Compare the strings
        case 1:
            return (!strcmp(val1, val2));
        break;
        // Concatenate the strings
        case 2:
            strcat(val1, val2);
            return true;
        break;
        default:
            return false;
        break;

    }
}


/* testInt:
 * Testing Option 1 - Equality
*/

TEST(TestInt, EqualityTest)
{
    ASSERT_TRUE(testInt(1, 12, 12));
}

TEST(TestInt, EqualityTestNegativeValues)
{
    ASSERT_TRUE(testInt(1, -12, -12));
}

TEST(TestInt, EqualityTestFloatValues1)
{
    ASSERT_TRUE(testInt(1, 12.5, 12.5));
}

TEST(TestInt, EqualityTestFloatValues2)
{
    ASSERT_TRUE(testInt(1, 12.5, 12.6));
}

TEST(TestInt, EqualityTestAsciiValues)
{
    ASSERT_TRUE(testInt(1, 'A', 'A'));
}

TEST(TestInt, EqualityTestBoolValues1)
{
    ASSERT_TRUE(testInt(1, true, true));
}

TEST(TestInt, EqualityTestBoolValues2)
{
    ASSERT_TRUE(testInt(1, false, false));
}

TEST(TestInt, EqualityTestZeroValue)
{
    ASSERT_TRUE(testInt(1, 0, 0));
}

TEST(TestInt, EqualityTestMinValue)
{
    ASSERT_TRUE(testInt(1, -2147483648, -2147483648));
}

TEST(TestInt, EqualityTestMaxValue)
{
    ASSERT_TRUE(testInt(1, 2147483647, 2147483647));
}

TEST(TestInt, OverflowTestOption1)
{
    ASSERT_TRUE(testInt(1, -2147483648, 2147483648));
}


/* testInt:
 * Testing Option 1 - Inequality
*/

TEST(TestInt, InequalityTest)
{
    ASSERT_FALSE(testInt(1, 10, 12));
}

TEST(TestInt, InequalityTestNegativeValues)
{
    ASSERT_FALSE(testInt(1, -12, -50));
}

TEST(TestInt, InequalityTestFloatValues)
{
    ASSERT_FALSE(testInt(1, 12.5, 15.5));
}

TEST(TestInt, InequalityTestAsciiValues)
{
    ASSERT_FALSE(testInt(1, 'A', 'C'));
}

TEST(TestInt, InequalityTestBoolValues)
{
    ASSERT_FALSE(testInt(1, true, false));
}


/* testInt:
 * Testing Option 2 - Factorial
*/

TEST(TestInt, FactorialTest)
{
    ASSERT_TRUE(testInt(2, 5, 120));
}

TEST(TestInt, NonFactorialTest)
{
    ASSERT_FALSE(testInt(2, 3, 120));
}


/* testInt:
 * Testing Option 2 - Factorial (Negative values)
*/

TEST(TestInt, FactorialTestNegativeValue1)
{
    ASSERT_FALSE(testInt(2, -5, 120));
}

TEST(TestInt, FactorialTestNegativeValue2)
{
    ASSERT_FALSE(testInt(2, 5, -120));
}

TEST(TestInt, FactorialTestNegativeValue1Value2)
{
    ASSERT_FALSE(testInt(2, -5, -120));
}


/* testInt:
 * Testing Option 2 - Factorial (Float values)
*/

TEST(TestInt, FactorialTestFloatValue1)
{
    ASSERT_TRUE(testInt(2, 5.5, 120));
}

TEST(TestInt, FactorialTestFloatValue2)
{
    ASSERT_TRUE(testInt(2, 5, 120.5));
}

TEST(TestInt, FactorialTestFloatValue1Value2)
{
    ASSERT_TRUE(testInt(2, 5.5, 120.5));
}


/* testInt:
 * Testing Option 2 - Factorial (Ascii values)
*/

TEST(TestInt, FactorialTestAsciiValue1)
{
    ASSERT_TRUE(testInt(2, '\0', 1));
}

TEST(TestInt, FactorialTestAsciiValue2)
{
    ASSERT_TRUE(testInt(2, 5, 'x'));
}

TEST(TestInt, FactorialTestAsciiValue1Value2)
{
    ASSERT_FALSE(testInt(2, 'A', 'Z'));
}


/* testInt:
 * Testing Option 2 - Factorial (Bool values)
*/

TEST(TestInt, FactorialTestBoolValue1)
{
    ASSERT_TRUE(testInt(2, true, true));
}

TEST(TestInt, FactorialTestBoolValue2)
{
    ASSERT_TRUE(testInt(2, false, true));
}


/* testInt:
 * Testing Option 3 - Primality
*/

TEST(TestInt, PrimeTest)
{
    ASSERT_TRUE(testInt(3, 5, 120));
}

TEST(TestInt, NonPrimeTest)
{
    ASSERT_FALSE(testInt(3, 12, 120));
}


/* testInt:
 * Testing Option 3 - Primality (Negative value)
*/

TEST(TestInt, PrimeTestNegativeValue)
{
    ASSERT_FALSE(testInt(3, -5, 120));
}


/* testInt:
 * Testing Option 3 - Primality (Float value)
*/

TEST(TestInt, PrimeTestFloatValue1)
{
    ASSERT_TRUE(testInt(3, 5.5, 120));
}

TEST(TestInt, PrimeTestFloatValue2)
{
    ASSERT_FALSE(testInt(3, 6.5, 120));
}


/* testInt:
 * Testing Option 3 - Primality (Ascii value)
*/

TEST(TestInt, PrimeTestAsciiValue1)
{
    ASSERT_TRUE(testInt(3, 'C', 120));
}

TEST(TestInt, PrimeTestAsciiValue2)
{
    ASSERT_FALSE(testInt(3, 'B', 120));
}


/* testInt:
 * Testing Option 3 - Primality (Bool value)
*/

TEST(TestInt, PrimeTestBoolValue1)
{
    ASSERT_FALSE(testInt(3, true, 120));
}

TEST(TestInt, PrimeTestBoolValue2)
{
    ASSERT_FALSE(testInt(3, false, 120));
}


/* testInt:
 * Testing Invalid Option
*/

TEST(TestInt, InvalidOptionTest)
{
    ASSERT_TRUE(testInt(4, 5, 120));
}


/* testStrings:
 * Testing Option 1 - String equality
*/

TEST(TestStrings, EqualityTest)
{
    // Arrange
    char *str1 = (char *)"Hello";
    char *str2 = (char *)"Hello";

    // Act
    bool return_value = testStrings(1, str1, str2);

    // Assert
    ASSERT_TRUE(return_value);
}


/* testStrings:
 * Testing Option 1 - String Inequality
*/

TEST(TestStrings, InequalityTest)
{
    // Arrange
    char *str1 = (char *)"Hello";
    char *str2 = (char *)"Hi";

    // Act
    bool return_value = testStrings(1, str1, str2);

    // Assert
    ASSERT_FALSE(return_value);
}


/* testStrings:
 * Testing Option 2 - String Concatenation
*/

TEST(TestStrings, StringConcatenationTest)
{
    // Arrange
    char str1[100] = "Hello";
    char *str2 = (char *)"World";

    // Act
    bool return_value = testStrings(2, str1, str2);

    // Assert
    ASSERT_TRUE(return_value);
    ASSERT_STREQ("HelloWorld", str1);
}


/* testStrings:
 * Testing Invalid Option
*/

TEST(TestStrings, InvalidOptionTest)
{
    // Arrange
    char *str1 = (char *)"Hello";
    char *str2 = (char *)"Hi";

    // Act
    bool return_value = testStrings(3, str1, str2);

    // Assert
    ASSERT_FALSE(return_value);
}