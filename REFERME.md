## Number of bits
Number | 64 | 32 | 16 | 8 | 4 | 2 | 1 |
-------|----|----|----|---|---|---|---|
20     |  0 |  0 |  1 | 0 | 1 | 0 | 0 |
10     |  0 |  0 |  0 | 1 | 0 | 1 | 0 |
AND    |  0 |  0 |  0 | 0 | 0 | 0 | 0 |
OR     |  0 |  0 |  1 | 1 | 1 | 1 | 0 |
---
    FFT - read as array and ouput as array
    Memory Corruption - happens while pointer manipulation
    Memory Leak - allocates memory and should deallocate (malloc(), free())
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
## Linux Commands
#### General Commands
    ls: List directory contents
    cd: Change directory
    pwd: Print working directory
    history: Command history
    alias: Create command aliases
#### Creation Empty Files/Folders
    mkdir: Create a directory
    touch: Create a file
#### Copy/Move/Remove Files
    cp: Copy files and directories
    mv: Move or rename files and directories
    rm: Remove files and directories
#### Searching & Finding & Displaying
    find: Search for files and directories
    grep: Search for patterns in files
    cat: Concatenate and display files
    less: View file contents page by page
    head: Display the first lines of a file
    tail: Display the last lines of a file
    tr: Translate characters
    In: Create links between files
    cut: Select portions of lines from files
    tee: Redirect output to multiple files or commands
    sort: Sort lines in a text file
    cut: Extract sections from lines of files
    wc: Word, line, character, and byte count
#### Editors
    vi/vim: Text editor
    nano: Text editor
#### Zip/Unzip Commands
    tar: Archive and compress files
    gzip: Compress files
    gunzip: Decompress files
#### Download and Transfer
    wget: Download files from the web
    curl: Transfer data to or from a server/Perform HTTP requests
#### Shell/Hosts
    ssh: Secure shell remote login
    scp: Securely copy files between hosts
    ssh-keygen: Generate SSH key pairs
    ssh-agent: Manage SSH keys in memory
    source: Execute commands from a file in the current shell
#### Permission Edits
    chmod: Change file permissions
    chown: Change file ownership
    chgrp: Change group ownership
#### Processes in Kernel
    ps: Display running processes
    top: Monitor system resources and processes
    kill: Terminate processes
    Isof: List open files and processes
    awk: Pattern scanning and processing language
#### Storage/System Viewers
    df: Display disk space usage
    du: Estimate file and directory space usage
    free: Display memory usage
    mkfs: Create a file system
    mount: Mount a file system
    umount: Unmount a file system
#### Network Configs
    uname: Print system information
    ifconfig: Configure network interfaces
    ping: Test network connectivity
    netstat: Network statistics
    iptables: Firewall administration
    nc: Netcat -networking utility
#### System Calls
    systemctl: Manage system services
    journalctl: Query the system journal
    crontab: Schedule cron jobs
#### Users and Password
    useradd: Create a user account
    passwd: Change user password
    su: Switch user
    SuQo: Execute a command as another user
    usermod: Modify user account
    groupadd:Create a group
    groupmod: Modify a group
    id: Print user and group information
#### File Synchronization
    rsync: Synchronize files and directories
    diff: Compare files line by line
    patch: Apply a patch to files
#### Domain & DNS
    whois: Lookup domain registration details
    dig: DNS lookup utility
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
## Google Test (Unit Testing)

#### Main Function

    int main(int argc, char **argv) {
        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }

#### String Inequality Check
    
    try {
        if(stringOne!=stringTwo){
            throw 1;
        }
        bool return_value = func(stringOne, stringTwo);
        ASSERT_FALSE(return_value);
    }
    catch (int ex){
        std::cout<<"Error"<<std::endl;
        FAIL();
    }

#### String Concatenation Check

    try {
        if(strlen(stringOne) + strlen(stringTwo) > SIZE) {
            throw 1;
        }
        bool return_value = func(stringOne, stringTwo);
        ASSERT_TRUE(return_value);
        ASSERT_STREQ("HelloWorld", stringOne);
    }
    catch(int ex){
        std::cout<<"Error"<<std::endl;
        FAIL();
    }

#### Normal Exception Handling
    try {
        if(val < 0) {
            throw std::invalid_argument("STATEMENT_FALSE");
        }
        ...
    }
    catch(const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
---
## Linked List
    -> Dynamically allocated nodes
    -> Node - one date, one link
---
## Binary Search Tree

#### Creating Structure to execute a code
    typedef struct Node {
        int data;
        struct Node* left;
        struct Node* right;
    } Node;

#### 1. Recursive Method
    A function is said to be recursive if it calls itself during its execution
    
    Node* searchRecursive(Node* root, int key) {
        if (root == NULL || root->data == key) {
            return root;
        }

        if (key < root->data) {
            return search(root->left, key);
        } else {
            return search(root->right, key);
        }
    }

#### 2. Iterative Method
    An iterative approach involves using loops to repeatedly execute a set of statements until a certain condition is met.
    
    Node* searchIterative(Node* root, int key) {
        while (root != NULL && root->data != key) {
            if (key < root->data) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return root;
    }
---
## Data alignment in Memory

    Header - <stdalign.h>
    Data alignment depends on larger size of available variable.

    Example:
    int         |   4 + 4
    char        |   1 + 7
    double      |   8

    -> double is the base memory alignment order
---
## Segmented Memory Architecture
    For 16-bit x86

    Four registers are used to refer to the respective segments:
        1) DS → data segment
        2) CS → code segment
        3) SS → stack segment
        4) ES → extra segment

    A logical address on this architecture is written segment:offset.
    
    Near pointers refer (as only offset) to point the current segment.
    
    Far pointers use segment info and an offset to point across segments.
         So, to use them, DS or CS must be changed to the specified value, the memory will be dereferenced and then the original value of DS/CS restored. 
         Note that pointer arithmetic on them doesn't modify the segment portion of the pointer, so overflowing the offset will just wrap it around.
    
    Huge pointers, which are normalized to have the highest possible segment for a given address (contrary to far pointers).

    On 32-bit and 64-bit architectures, memory models are using segments differently, or not at all.
---