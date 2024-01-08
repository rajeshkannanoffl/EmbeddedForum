#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int calculateSize(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + calculateSize(root->left) + calculateSize(root->right);
    }
}

int main() {
    // Create an empty binary tree (no nodes, root is NULL)
    struct Node* root = NULL;

    // Calculate the size of the empty binary tree
    int size = calculateSize(root);

    printf("Size of the empty binary tree: %d\n", size);

    return 0;
}