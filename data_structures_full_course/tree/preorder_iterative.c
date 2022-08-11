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

struct Node *A[MAX_SIZE];
int top = -1;

int IsEmpty() {
    return top == -1;
}

void Push(struct Node *x) {
    if (top == MAX_SIZE - 1) {
        printf("Error: stack overflow\n");
        return;
    }
    A[++top] = x;
}

void Pop() {
    if (IsEmpty()) {
        printf("Error: No element to pop\n");
        return;
    }
    top--;
}

struct Node *Top() {
    return A[top];
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

// iterative version
void Preorder() {
    printf("Traversal in Preorder: ");
    if (root == NULL) return;

    printf("%c ", root->data);
    if (root->right != NULL) Push(root->right);
    if (root->left != NULL) Push(root->left);

    while (!IsEmpty()) {
        struct Node *p = Top();
        Pop();
        printf("%c ", p->data);
        if (p->right != NULL) Push(p->right);
        if (p->left != NULL) Push(p->left);
    }
    printf("\n");
}

int main() {
    Insert();
    Preorder();
    return 0;
}