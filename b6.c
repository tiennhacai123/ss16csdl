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

Node* insertNode(Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }

    if (data < node->data) {
        node->left = insertNode(node->left, data);
    } else if (data > node->data) {
        node->right = insertNode(node->right, data);
    }
    return node;
}

int greaterThanX(Node* node, int x) {
    if (node == NULL) {
        return 0;
    }

    int count = 0;
    if (node->data > x) {
        count++;
    }

    count += greaterThanX(node->left, x);
    count += greaterThanX(node->right, x);
    return count;
}

int main() {
    Node* node = NULL;
    int n, x, value;
	node = insertNode(node, 3);
	node = insertNode(node, 2);
	node = insertNode(node, 5);
	node = insertNode(node, 4);
	node = insertNode(node, 6);
    printf("Nhap gia tri X: ");
    scanf("%d", &x);
    int count = greaterThanX(node, x);
    printf("So luong nut co gia tri lon hon %d la: %d\n", x, count);
    return 0;
}