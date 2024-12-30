#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof( Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int countLeaves( Node* node) {
    if (node == NULL) {
        return 0;
    }

    if (node->left == NULL && node->right == NULL) {
        return 1; 
    } else {
        return countLeaves(node->left) + countLeaves(node->right);
    }
}

int main() {
    Node* node = createNode(1);
    node->left = createNode(2);
    node->right = createNode(3);
    node->left->left = createNode(4);
    node->left->right = createNode(5);
    node->right->left = createNode(6);
    node->right->right = createNode(7);
    printf("So luong la trong cay la: %d\n", countLeaves(node));
    return 0;
}