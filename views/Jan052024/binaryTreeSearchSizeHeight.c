#include <stdio.h>
#include <stdlib.h>

// Define a typedef for the struct Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to find the size (number of nodes) of the binary tree
int size(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + size(root->left) + size(root->right);
    }
}

// Function to find the height of the binary tree
int height(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}

// Function to search for a key in the binary tree
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main() {
    Node* root = NULL;
    int keys[] = {10, 5, 15, 3, 7, 12, 18};

    // Insert keys into the binary tree
    for (size_t i = 0; i < sizeof(keys) / sizeof(keys[0]); i++){
        root = insert(root, keys[i]);
    }

    printf("Size of the binary tree: %d\n", size(root));
    printf("Height of the binary tree: %d\n", height(root));

    int keyToSearch;
    printf("Enter the key to search in binary tree: ");
    scanf("%d", &keyToSearch);

    Node* result = search(root, keyToSearch);
    if (result != NULL) {
        printf("Key is found in the binary tree. (Key: %d)\n", keyToSearch);
    } else {
        printf("Key not found in the binary tree.(Key: %d)\n", keyToSearch);
    }

    return 0;
}







/*
        10
      /  \
     5    15
    / \   / \
   3   7 12  18
 
*/