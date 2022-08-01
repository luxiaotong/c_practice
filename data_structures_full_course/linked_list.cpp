#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head;

void Insert(Node **head, int x) {
    struct Node *temp = (Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = *head;
    *head = temp;
}

void Print(Node *head) {
    printf("List:");
    while (head != NULL) {
        printf(" %d", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    printf("Enter the List size:");
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter a number:");
        scanf("%d", &x);
        Insert(&head, x);
        Print(head);
    }
}