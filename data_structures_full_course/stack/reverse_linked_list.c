#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *node_stack[101];
int top = -1;

int IsEmpty() {
    return top == -1;
}

void Push(struct Node *p) {
    node_stack[++top] = p;
}

void Pop() {
    if (IsEmpty()) {
        printf("stack error");
        return;
    }
    top--;
}

struct Node *Top() {
    if (IsEmpty()) {
        printf("stack error");
        return NULL;
    }
    return node_stack[top];
}

void PrintStack() {
    printf("Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", node_stack[i]->data);
    }
    printf("\n");
}

void Insert(int x) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = x;
    node->next = NULL;
    if (head == NULL) {
        head = node;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

void Reverse() {
    struct Node *temp = head;
    while (temp != NULL) {
        Push(temp);
        temp = temp->next;
    }
    struct Node *p = NULL;
    if (!IsEmpty()) {
        p = Top();
        Pop();
        head = p;
    }
    PrintStack();
    while (!IsEmpty()) {
        p->next = Top();
        Pop();
        p = p->next;
    }
    p->next = NULL;
}

void Print() {
    printf("List: ");
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(8);
    Print();
    Reverse();
    Print();
}
