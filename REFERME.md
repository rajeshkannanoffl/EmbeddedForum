## Number of bits
Number | 64 | 32 | 16 | 8 | 4 | 2 | 1 |
-------|----|----|----|---|---|---|---|
20     |  0 |  0 |  1 | 0 | 1 | 0 | 0 |
10     |  0 |  0 |  0 | 1 | 0 | 1 | 0 |
AND    |  0 |  0 |  0 | 0 | 0 | 0 | 0 |
OR     |  0 |  0 |  1 | 1 | 1 | 1 | 0 |
---
#### FFT - read as array and ouput as array
---
#### Memory Corruption - happens while pointer manipulation
---
#### Memory Leak - allocates memory and should deallocate (malloc(), free())
---
## git.sh
    sleep 1
    git init
    sleep 2
    git status
    sleep 2
    git add .
    sleep 2
    git status
    sleep 2
    git commit -m "Session Update"
    sleep 2
    git push -f
    sleep 2
    echo ""
    echo -n "Successfully Committed to Git!"
    echo ""
    sleep 1
---
## STM32 Path
    C:\Users\rmookkan\OneDrive - Capgemini\Desktop\Git\EmbeddedForum\workspace
---
## Code Coverage
    -> white-box testing (extent to code excuted)
    -> static instrumentation (monitoring code execution)
    -> quantitative metrics (nature and health of code)
    -> easy removal of dead codes and errors (for base efficiency)

#### Levels: (coverage)
    -> Branch - Loops, decision making
    -> Function - testing function with diff parameters
    -> Statement - every line of code, corner and boundary case
    -> Loop - every loop (atleast one)
    -> Condition - conditional statements, proper coverage to control flow
    -> Finite state machine - one state to another

#### Tools:
    -> Gcov - generate coverage infos (-fprofile-arcs -ftest-coverage) 
    -> Lcov - statement, function and branch coverage measurement, overview of file structure,
                classes in tree form. 
---
## Inline Function
    static inline <data_type> <func> (args){ return_type }

    Pros: -> overhead doesn't occur.
    -> preamble

    Cons: -> too much will result cache hit rate.
---
## GoogleTest - UnitTesting

#### Main Function

    int main(){
        testing::InitGoogleTest();
        return RUN_ALL_TESTS();
    }
---
## String Inequality Check
    
    try {
        if(str1!=str2){
            throw 1;
        }
        bool return_value = testStrings(1, str1, str2);
        ASSERT_FALSE(return_value);
    }
    catch (int ex){
        std::cout<<"Error"<<std::endl;
        FAIL();
    }
---
## String Concatenation Check

    try {
        if(strlen(str1) + strlen(str2) > SIZE) {
            throw 1;
        }
        bool return_value = testStrings(2, str1, str2);
        ASSERT_TRUE(return_value);
        ASSERT_STREQ("HelloWorld", str1);
    }
    catch(int ex){
        std::cout<<"Error"<<std::endl;
        FAIL();
    }
---
## Normal Exception Handling
    try {
        if(val < 0) {
            throw std::invalid_argument("Negative value!");
        }
        ASSERT_FALSE(testInt(3, -5, 120));
    }
    catch(const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
---
## Linked List
    -> Dynamically allocated nodes
    -> Node - one date, one link
---
## Steps To Install ST-Link

1) Go to: https://www.st.com/en/development-tools/st-link-server.html

2) Install the latest version

3) Will ask Permission, Give administrative permission ( Option 1)

4) Wait for the permission approval

5) Once its approved , Install the ST-Link again

6) Restart the Application

7) Debug and Run (Make Debug configuration changes as mentioned in the course)
---



























