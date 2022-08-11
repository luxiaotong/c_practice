#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;
struct Node *root2 = NULL;

struct Node *GetNewNode(int x) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void Insert() {
    root = GetNewNode(7);
    root->left = GetNewNode(4);
    root->right = GetNewNode(9);
    root->left->left = GetNewNode(1);
    root->left->right = GetNewNode(6);

    root2 = GetNewNode(10);
    root2->left = GetNewNode(5);
    root2->right = GetNewNode(16);
    root2->left->left = GetNewNode(4);
    root2->left->right = GetNewNode(7);
    root2->left->left->left = GetNewNode(1);
    root2->left->right->right = GetNewNode(11);
}

int IsBST(struct Node *node, int min, int max) {
    if (node == NULL) {
        return 1;
    } else if (node->data > min &&
               node->data < max &&
               IsBST(node->left, min, node->data) &&
               IsBST(node->right, node->data, max)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Insert();
    printf("is bst: %d\n", IsBST(root, -2 ^ 31, 2 ^ 31 - 1));
    printf("is bst: %d\n", IsBST(root2, -2 ^ 31, 2 ^ 31 - 1));
    return 0;
}