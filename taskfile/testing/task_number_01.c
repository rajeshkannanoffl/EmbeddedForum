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

TEST(IntTestSuite, IntEqualTest){
    // Arrange
    int a = 10;
    int b = 10;
    // Act
    bool equal_test = testInt(1, a, b);
    // Assert
    EXPECT_EQ(a, b);
    ASSERT_TRUE(equal_test);
}

TEST(IntTestSuite, IntLesserNotEqualTest){
    // Arrange
    int a = 10;
    int b = 15;
    // Act
    bool equal_test = testInt(1, a, b);
    // Assert
    EXPECT_LT(a, b);
    ASSERT_FALSE(equal_test);
}

TEST(IntTestSuite, IntGreaterNotEqualTest){
    // Arrange
    int a = 15;
    int b = 10;
    // Act
    bool equal_test = testInt(1, a, b);
    // Assert
    EXPECT_GT(a, b);
    ASSERT_FALSE(equal_test);
}

TEST(IntTestSuite, IntFloatEqualTest){
    // Arrange
    int a = 10.5;
    int b = 10.5;
    // Act
    bool equal_test = testInt(1, a, b);
    // Assert
    EXPECT_FLOAT_EQ(a, b);
    ASSERT_TRUE(equal_test);
}

TEST(IntTestSuite, IntLesserFloatNotEqualTest){
    // Arrange
    int a = 10.5;
    int b = 11.9;
    // Act
    bool equal_test = testInt(1, a, b);
    // Assert
    EXPECT_LT(a, b);
    ASSERT_FALSE(equal_test);
}

TEST(IntTestSuite, IntGreaterFloatNotEqualTest){
    // Arrange
    int a = 12.5;
    int b = 11.9;
    // Act
    bool equal_test = testInt(1, a, b);
    // Assert
    EXPECT_GT(a, b);
    ASSERT_FALSE(equal_test);
}

TEST(IntTestSuite, IntNegativeNotEqualTest){
    // Arrange
    int a = -10;
    int b = 10;
    // Act
    bool equal_test = testInt(1, a, b);
    // Assert
    ASSERT_FALSE(equal_test);
}

TEST(IntTestSuite, IntNegativeEqualTest){
    // Arrange
    int a = -10;
    int b = -10;
    // Act
    bool equal_test = testInt(1, a, b);
    // Assert
    ASSERT_TRUE(equal_test);
}

TEST(IntTestSuite, IntIsNotFactorialTest){
    // Arrange
    int a = 5;
    int b = 100;
    // Act
    bool factorial_test = testInt(2, a, b);
    // Assert
    ASSERT_FALSE(factorial_test);
}

TEST(IntTestSuite, IntIsFactorialTest){
    // Arrange
    int a = 5;
    int b = 120;
    // Act
    bool factorial_test = testInt(2, a, b);
    // Assert
    ASSERT_TRUE(factorial_test);
}

TEST(IntTestSuite, IntFloatIsNotFactorialTest){
    // Arrange
    int a = 5.5;
    int b = 100;
    // Act
    bool factorial_test = testInt(2, a, b);
    // Assert
    ASSERT_FALSE(factorial_test);
}

TEST(IntTestSuite, IntFloatIsFactorialTest){
    // Arrange
    int a = 5.5;
    int b = 120;
    // Act
    bool factorial_test = testInt(2, a, b);
    // Assert
    ASSERT_TRUE(factorial_test);
}

TEST(IntTestSuite, IntIsNotPrimeTest){
    // Arrange
    int a = 9;
    int b = 10;
    // Act
    bool prime_test = testInt(3, a, b);
    // Assert
    ASSERT_FALSE(prime_test);
}

TEST(IntTestSuite, IntIsPrimeTest){
    // Arrange
    int a = 11;
    int b = 10;
    // Act
    bool prime_test = testInt(3, a, b);
    // Assert
    ASSERT_TRUE(prime_test);
}

TEST(IntTestSuite, IntFloatIsNotPrimeTest){
    // Arrange
    int a = 9.9;
    int b = 10;
    // Act
    bool prime_test = testInt(3, a, b);
    // Assert
    ASSERT_FALSE(prime_test);
}

TEST(IntTestSuite, IntFloatIsPrimeTest){
    // Arrange
    int a = 11.8;
    int b = 10;
    // Act
    bool prime_test = testInt(3, a, b);
    // Assert
    ASSERT_TRUE(prime_test);
}

TEST(IntTestSuite, IntDefaultTesT){
    // Arrange
    int a = 10;
    int b = 11;
    // Act
    bool default_test = testInt(0, a, b);
    // Assert
    ASSERT_TRUE(default_test);
}

TEST(StringTestSuite, StringNotEqualTest){
    // Arrange
    char *str1 = (char*)"Hello";
    char *str2 = (char*)"World";
    // Act
    bool comparison_test = testStrings(1, str1, str2);
    // Assert
    EXPECT_STRNE(str1, str2);
    ASSERT_FALSE(comparison_test);
}

TEST(StringTestSuite, StringEqualTest){
    // Arrange
    char *str1 = (char*)"Hello";
    char *str2 = (char*)"Hello";
    // Act
    bool comparison_test = testStrings(1, str1, str2);
    // Assert
    EXPECT_STREQ(str1, str2);
    ASSERT_TRUE(comparison_test);
}

TEST(StringTestSuite, StringCaseNotEqualTest){
    // Arrange
    char *str1 = (char*)"HeLLo";
    char *str2 = (char*)"WORLD";
    // Act
    bool comparison_test = testStrings(1, str1, str2);
    // Assert
    EXPECT_STRCASENE(str1, str2);
    ASSERT_FALSE(comparison_test);
}

TEST(StringTestSuite, StringCaseEqualTest){
    // Arrange
    char *str1 = (char*)"HeLLO";
    char *str2 = (char*)"HeLLO";
    // Act
    bool comparison_test = testStrings(1, str1, str2);
    // Assert
    EXPECT_STRCASEEQ(str1, str2);
    ASSERT_TRUE(comparison_test);
}


TEST(StringTestSuite, StringConcatenateTest){
    // Arrange
    char str1[10] = "Hello";
    char *str2 = (char*)" World";
    // Act
    bool concatenate_test = testStrings(2, str1, str2);
    // Assert
    ASSERT_TRUE(concatenate_test);
}

TEST(StringTestSuite, StringDefaultTest){
    // Arrange
    char *str1 = (char*)"Hello";
    char *str2 = (char*)"World";
    // Act
    bool default_test = testStrings(0, str1, str2);
    // Assert
    ASSERT_FALSE(default_test);
}