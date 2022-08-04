#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front;
struct Node *rear;

int IsEmpty() {
    return (front == NULL && rear == NULL);
}

void EnQueue(int x) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = x;
    p->next = NULL;
    if (IsEmpty()) {
        front = rear = p;
    } else {
        rear->next = p;
        rear = rear->next;
    }
}

void DeQueue() {
    if (IsEmpty()) {
        printf("dequeue error: empty\n");
        return;
    }
    struct Node *p = front;
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }
    free(p);
}

void PrintQueue() {
    if (IsEmpty()) {
        printf("print queue error: empty\n");
        return;
    }
    struct Node *p = front;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    for (int i = 0; i < 10; i++) {
        EnQueue(i + 1);
    }
    PrintQueue();
    for (int i = 0; i < 10; i++) {
        DeQueue();
    }
    PrintQueue();
    return 0;
}
