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

/*
    Testing for Integers.
*/
TEST(IntTestSuite, IntEqualTest){
    EXPECT_EQ(10, 10);
    ASSERT_TRUE(testInt(1, 10, 10));
}

TEST(IntTestSuite, IntLesserNotEqualTest){
    EXPECT_LT(10, 15);
    ASSERT_FALSE(testInt(1, 10, 15));
}

TEST(IntTestSuite, IntGreaterNotEqualTest){
    EXPECT_GT(15, 10);
    ASSERT_FALSE(testInt(1, 15, 10));
}

TEST(IntTestSuite, IntFloatEqualTest){
    EXPECT_EQ(10.5, 10.5);
    ASSERT_TRUE(testInt(1, 10.5, 10.5));
}

TEST(IntTestSuite, IntLesserFloatNotEqualTest){
    EXPECT_LT(10.5, 11.9);
    ASSERT_FALSE(testInt(1, 10.5, 11.9));
}

TEST(IntTestSuite, IntGreaterFloatNotEqualTest){
    EXPECT_GT(12.5, 11.9);
    ASSERT_FALSE(testInt(1, 12.5, 11.9));
}

TEST(IntTestSuite, IntNegativeNotEqualTest){
    ASSERT_FALSE(testInt(1, -10, 10));
}

TEST(IntTestSuite, IntNegativeEqualTest){
    ASSERT_TRUE(testInt(1, -10, -10));
}

TEST(IntTestSuite, IntIsNotFactorialTest){
    ASSERT_FALSE(testInt(2, 5, 100));
}

TEST(IntTestSuite, IntIsFactorialTest){
    ASSERT_TRUE(testInt(2, 5, 120));
}

TEST(IntTestSuite, IntFloatIsNotFactorialTest){
    ASSERT_FALSE(testInt(2, 5.5, 100));
}

TEST(IntTestSuite, IntFloatIsFactorialTest){
    ASSERT_TRUE(testInt(2, 5.5, 120));
}

TEST(IntTestSuite, IntIsNotPrimeTest){
    ASSERT_FALSE(testInt(3, 9, 10));
}

TEST(IntTestSuite, IntIsPrimeTest){
    ASSERT_TRUE(testInt(3, 11, 10));
}

TEST(IntTestSuite, IntFloatIsNotPrimeTest){
    ASSERT_FALSE(testInt(3, 9.9, 10));
}

TEST(IntTestSuite, IntFloatIsPrimeTest){
    ASSERT_TRUE(testInt(3, 11.8, 10));
}

TEST(IntTestSuite, IntDefaultTesT){
    ASSERT_TRUE(testInt(0, 10, 11));
}

TEST(StringTestSuite, StringNotEqualTest){
    char *str1 = (char*)"Hello";
    char *str2 = (char*)"World";
    EXPECT_STRNE(str1, str2);
    ASSERT_FALSE(testStrings(1, str1, str2));
}

TEST(StringTestSuite, StringEqualTest){
    char *str1 = (char*)"Hello";
    char *str2 = (char*)"Hello";
    EXPECT_STREQ(str1, str2);
    ASSERT_TRUE(testStrings(1, str1, str2));
}

TEST(StringTestSuite, StringCaseNotEqualTest){
    char *str1 = (char*)"HeLLo";
    char *str2 = (char*)"WORLD";
    EXPECT_STRCASENE(str1, str2);
    ASSERT_FALSE(testStrings(1, str1, str2));
}

TEST(StringTestSuite, StringCaseEqualTest){
    char *str1 = (char*)"HeLLO";
    char *str2 = (char*)"HeLLO";
    EXPECT_STRCASEEQ(str1, str2);
    ASSERT_TRUE(testStrings(1, str1, str2));
}


TEST(StringTestSuite, StringConcatenateTest){
    char str1[15] = "Hello";
    char *str2 = (char*)" World";
    ASSERT_TRUE(testStrings(2, str1, str2));
}

TEST(StringTestSuite, StringDefaultTest){
    char *str1 = (char*)"Hello";
    char *str2 = (char*)"World";
    ASSERT_FALSE(testStrings(0, str1, str2));
}