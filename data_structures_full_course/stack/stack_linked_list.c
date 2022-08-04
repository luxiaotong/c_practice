#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void Push(int x) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = x;
    node->next = top;
    top = node;
}

void Pop() {
    if (top == NULL) return;
    struct Node* temp = top;
    top = top->next;
    free(temp);
}

int main() {
}