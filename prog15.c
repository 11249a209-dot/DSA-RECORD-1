#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Preorder DFS: Root -> Left -> Right
void preorderDFS(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderDFS(root->left);
        preorderDFS(root->right);
    }
}

// Inorder DFS: Left -> Root -> Right
void inorderDFS(struct Node* root) {
    if (root != NULL) {
        inorderDFS(root->left);
        printf("%d ", root->data);
        inorderDFS(root->right);
    }
}

// Postorder DFS: Left -> Right -> Root
void postorderDFS(struct Node* root) {
    if (root != NULL) {
        postorderDFS(root->left);
        postorderDFS(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    // Sample binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Preorder DFS: ");
    preorderDFS(root);
    printf("\n");

    printf("Inorder DFS: ");
    inorderDFS(root);
    printf("\n");

    printf("Postorder DFS: ");
    postorderDFS(root);
    printf("\n");

    return 0;
}
