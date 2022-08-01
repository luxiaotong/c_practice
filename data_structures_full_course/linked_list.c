#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head;

void Print();

// Insert an integer at beginning of list
void Insert(int x) {
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

// Insert an integer at n'th position of list
void InsertN(int data, int n) {
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (n == 1) {
        temp->next = head;
        head = temp;
        return;
    }
    struct Node *temp2 = head;
    for (int i = 0; i < n - 2; i++) {
        temp2 = temp2->next;
    }
    printf("n: %d, data: %d\n", n, temp2->data);
    temp->next = temp2->next;
    temp2->next = temp;
}

// Insert an integer at end of list
void InsertEnd(int x) {
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        return;
    }
    struct Node *temp2 = head;
    while (temp2->next != NULL) {
        temp2 = temp2->next;
    }
    temp2->next = temp;
}

// Delete node at n'th position
void Delete(int n) {
    struct Node *temp = head;
    if (n == 1) {
        head = head->next;
        free(temp);
        return;
    }
    for (int i = 0; i < n - 2; i++) {
        temp = temp->next;
    }
    printf("n: %d, data: %d\n", n, temp->data);
    struct Node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
    return;
}

// Reverse a list - iterative version
void Reverse() {
    if (head == NULL || head->next == NULL) {
        return;
    }
    struct Node *temp0, *temp1, *temp2;
    temp0 = NULL;
    temp1 = head;
    while (temp1 != NULL) {
        temp2 = temp1->next;
        temp1->next = temp0;
        temp0 = temp1;
        temp1 = temp2;
    }
    head = temp0;
}

// Reverse a list - recursive version
void Reverse2(struct Node *p) {
    if (p->next == NULL) {
        head = p;
        return;
    }
    Reverse2(p->next);
    struct Node *q = p->next;
    q->next = p;
    p->next = NULL;
    return;
}

// Print list - recursive version
void ReversePrint(struct Node *p) {
    if (p == NULL) {
        return;
    }
    ReversePrint(p->next);
    printf("%d ", p->data);
}

// Print all elements in the lsit
void Print() {
    struct Node *temp = head;
    printf("List:");
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    head = NULL;
    // printf("Enter the List size:");
    // int n, x;
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++) {
    //     printf("Enter a number:");
    //     scanf("%d", &x);
    //     Insert(x);
    //     Print();
    // }

    // InsertN(2, 1);  // 2
    // InsertN(3, 2);  // 2, 3
    // InsertN(4, 1);  // 4, 2, 3
    // InsertN(5, 2);  // 4, 5, 2, 3
    // InsertN(6, 3);  // 4, 5, 6, 2, 3
    // Print();

    // InsertEnd(2);
    // InsertEnd(4);
    // InsertEnd(6);
    // InsertEnd(5);  // 2, 4, 6, 5
    // Delete(3);     // 2, 4, 5
    // Print();
    // Delete(1);  // 4, 5
    // Print();

    // InsertEnd(2);
    // InsertEnd(4);
    // InsertEnd(6);
    // InsertEnd(5);  // 2, 4, 6, 5
    // Print();
    // Reverse();
    // Print();

    InsertEnd(2);
    InsertEnd(4);
    InsertEnd(6);
    InsertEnd(5);  // 2, 4, 6, 5
    Print();
    ReversePrint(head);
    printf("\n");
    Reverse2(head);
    Print();
}