#include <stdio.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int IsEmpty() {
    return (front == -1 && rear == -1);
}

int IsFull() {
    return (rear + 1 == front);
}

void EnQueue(int x) {
    if (IsFull()) {
        printf("enqueue %d error: queue is full\n", x);
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

void PrintQueue() {
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    for (int i = 0; i < MAX_SIZE; i++) {
        EnQueue(i + 1);
    }
    PrintQueue();
    for (int i = 0; i < MAX_SIZE / 2; i++) {
        DeQueue();
    }
    PrintQueue();
    for (int i = 0; i < MAX_SIZE / 2; i++) {
        EnQueue((i + 1) * 10);
    }
    PrintQueue();
    return 0;
}