#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

struct Node *GetNewNode(char x) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node *queue[MAX_SIZE];
int front = -1;
int rear = -1;

int IsEmpty() {
    return (front == -1 && rear == -1);
}

int IsFull() {
    return (rear + 1 == front);
}

void EnQueue(struct Node *x) {
    if (IsFull()) {
        printf("enqueue %p error: queue is full\n", x);
        return;
    }
    if (IsEmpty()) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        queue[(rear + 1) % MAX_SIZE] = x;
        rear++;
    }
}

void DeQueue() {
    if (IsEmpty()) {
        printf("dequeue error: queue is empty\n");
        return;
    }
    queue[front % MAX_SIZE] = 0;
    if (front == rear) {
        front = rear = -1;
        return;
    }
    front++;
}

struct Node *Front() {
    if (IsEmpty()) {
        return NULL;
    }
    return queue[front];
}

void PrintQueue() {
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%c ", queue[i]->data);
    }
    printf("\n");
}

// Insert
void Insert() {
    root = GetNewNode('F');

    root->left = GetNewNode('D');
    root->right = GetNewNode('J');

    root->left->left = GetNewNode('B');
    root->left->right = GetNewNode('E');

    root->right->left = GetNewNode('G');
    root->right->right = GetNewNode('K');

    root->left->left->left = GetNewNode('A');
    root->left->left->right = GetNewNode('C');

    root->right->left->right = GetNewNode('I');
}

void LevelOrder() {
    if (root == NULL) {
        return;
    }
    EnQueue(root);
    printf("Traversal in Level Order: ");
    while (!IsEmpty()) {
        struct Node *p = Front();
        printf("%c ", p->data);
        DeQueue();
        if (p->left != NULL) {
            EnQueue(p->left);
        }
        if (p->right != NULL) {
            EnQueue(p->right);
        }
    }
    printf("\n");
}

// recursive version
void Preorder(struct Node *p) {
    if (p == NULL) return;
    printf("%c ", p->data);
    Preorder(p->left);
    Preorder(p->right);
}

// recursive version
void Inorder(struct Node *p) {
    if (p == NULL) return;
    Inorder(p->left);
    printf("%c ", p->data);
    Inorder(p->right);
}

// recursive version
void Postorder(struct Node *p) {
    if (p == NULL) return;
    Postorder(p->left);
    Postorder(p->right);
    printf("%c ", p->data);
}

// iterative version
void Preorder2(struct Node *p) {
    if (p == NULL) return;
    printf("%c ", p->data);

    // Preorder(p->left);
    // Preorder(p->right);
}

int main() {
    Insert();
    LevelOrder();
    printf("Traversal in Preorder: ");
    Preorder(root);
    printf("\n");
    printf("Traversal in Inorder: ");
    Inorder(root);
    printf("\n");
    printf("Traversal in Postorder: ");
    Postorder(root);
    printf("\n");
    return 0;
}