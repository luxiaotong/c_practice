#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

#define max(a, b)               \
    ({                          \
        __typeof__(a) _a = (a); \
        __typeof__(b) _b = (b); \
        _a > _b ? _a : _b;      \
    })

#define min(a, b)               \
    ({                          \
        __typeof__(a) _a = (a); \
        __typeof__(b) _b = (b); \
        _a < _b ? _a : _b;      \
    })

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

// Insert - iterative version
void Insert(int x) {
    if (root == NULL) {
        root = GetNewNode(x);
        return;
    }
    struct Node *p = root;
    while (1) {
        if (x <= p->data) {
            if (p->left != NULL) {
                p = p->left;
                continue;
            } else {
                p->left = GetNewNode(x);
                return;
            }
        } else {
            if (p->right != NULL) {
                p = p->right;
                continue;
            } else {
                p->right = GetNewNode(x);
                return;
            }
        }
    }
}

// Search - iterative version
int Search(int x) {
    if (root == NULL) {
        return 0;
    }
    struct Node *p = root;
    while (1) {
        if (x < p->data) {
            if (p->left == NULL) {
                break;
            }
            p = p->left;
        } else if (x > p->data) {
            if (p->right == NULL) {
                break;
            }
            p = p->right;
        } else {
            return 1;
        }
    }
    return 0;
}

int FindMin() {
    if (root == NULL) {
        return 0;
    }
    struct Node *p = root;
    while (p->left != NULL) {
        p = p->left;
    }
    return p->data;
}

int FindMax() {
    if (root == NULL) {
        return 0;
    }
    struct Node *p = root;
    while (p->right != NULL) {
        p = p->right;
    }
    return p->data;
}

// Insert2 - recursive version
struct Node *Insert2(struct Node *node, int x) {
    if (node == NULL) {
        node = GetNewNode(x);
        return node;
    }
    if (x <= node->data) {
        node->left = Insert2(node->left, x);
    } else {
        node->right = Insert2(node->right, x);
    }
    return node;
}

// Search2 - recursive version
int Search2(struct Node *node, int x) {
    if (node == NULL) {
        return 0;
    }
    if (x < node->data) {
        return Search2(node->left, x);
    } else if (x > node->data) {
        return Search2(node->right, x);
    } else {
        return 1;
    }
}

int Height(struct Node *node) {
    if (node == NULL) {
        return -1;
    }
    return max(Height(node->left), Height(node->right)) + 1;
}

int FindMin2(struct Node *node) {
    if (node == NULL) {
        return 0;
    }
    struct Node *p = node;
    while (p->left != NULL) {
        p = p->left;
    }
    return p->data;
}

struct Node *Delete(struct Node *node, int x) {
    if (node == NULL) return NULL;
    if (x < node->data) {
        node->left = Delete(node->left, x);
    } else if (x > node->data) {
        node->right = Delete(node->right, x);
    } else {
        if (node->left == NULL && node->right == NULL) {
            free(node);
            node = NULL;
            return node;
        } else if (node->left == NULL) {
            struct Node *p = node;
            free(p);
            p = NULL;
            return node->right;
        } else if (node->right == NULL) {
            struct Node *p = node;
            free(p);
            p = NULL;
            return node->left;
        } else {
            node->data = FindMin2(node->right);
            node->right = Delete(node->right, node->data);
            return node;
        }
    }
    return node;
}

int main() {
    Insert(20);
    Insert(30);
    Insert(15);
    printf("search(15): %d\n", Search(15));
    printf("search(16): %d\n", Search(16));
    printf("find min: %d\n", FindMin());
    printf("find max: %d\n", FindMax());

    root2 = Insert2(root2, 12);
    root2 = Insert2(root2, 5);
    root2 = Insert2(root2, 3);
    root2 = Insert2(root2, 7);
    root2 = Insert2(root2, 1);
    root2 = Insert2(root2, 9);
    root2 = Insert2(root2, 15);
    root2 = Insert2(root2, 13);
    root2 = Insert2(root2, 17);
    root2 = Insert2(root2, 19);
    printf("Height: %d\n", Height(root2));
    printf("search(15): %d\n", Search2(root2, 15));
    root2 = Delete(root2, 15);
    printf("search(15): %d\n", Search2(root2, 15));
    printf("search(13): %d\n", Search2(root2, 13));
    printf("search(17): %d\n", Search2(root2, 17));
    printf("search(19): %d\n", Search2(root2, 19));

    return 0;
}