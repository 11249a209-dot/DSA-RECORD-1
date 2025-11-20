#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue structure for BFS
struct Queue {
    struct Node* nodes[100];
    int front;
    int rear;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = 0;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    q->nodes[q->rear++] = node;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    return q->nodes[q->front++];
}

// BFS / Level-order traversal
void bfs(struct Node* root) {
    if (root == NULL) return;

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);

    printf("BFS (Level-order) traversal: ");
    while (!isEmpty(&q)) {
        struct Node* curr = dequeue(&q);
        printf("%d ", curr->data);

        if (curr->left != NULL)
            enqueue(&q, curr->left);
        if (curr->right != NULL)
            enqueue(&q, curr->right);
    }
    printf("\n");
}

int main() {
    // Sample binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    bfs(root);

    return 0;
}
