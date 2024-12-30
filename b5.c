#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findMax(Node* node) {
    if (node == NULL) {
        return -1; 
    }

    int result = node->data;
    int leftResult = findMax(node->left);
    int rightResult = findMax(node->right);

    if (leftResult > result) {
        result = leftResult;
    }
    if (rightResult > result) {
        result = rightResult;
    }
    return result;
}

int main() {
    Node* node = createNode(1);
    node->left = createNode(2);
    node->right = createNode(3);
    node->left->left = createNode(4);
    node->left->right = createNode(5);
    node->right->left = createNode(6);
    node->right->right = createNode(7);

    int max = findMax(node);
    printf("Gia tri lon nhat trong cay la: %d\n", max); 

}