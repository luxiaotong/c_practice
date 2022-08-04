#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head;

struct Node *GetNewNode(int x) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = x;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void InsertAtHead(int x) {
    struct Node *node = GetNewNode(x);
    if (head == NULL) {
        head = node;
        return;
    }
    head->prev = node;
    node->next = head;
    head = node;
}

void InsertAtTail(int x);

void Print() {
    struct Node *p = head;
    printf("Forword: ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void ReversePrint() {
    struct Node *p = head;
    if (p == NULL) return;
    while (p->next != NULL) {
        p = p->next;
    }
    printf("Reverse: ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("\n");
}

int main() {
    head = NULL;
    InsertAtHead(2);
    InsertAtHead(4);
    InsertAtHead(6);
    InsertAtHead(8);
    Print();
    ReversePrint();
    return 0;
}