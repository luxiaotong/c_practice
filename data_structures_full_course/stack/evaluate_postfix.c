#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

int IsEmpty() {
    return top == -1;
}

void Push(char c) {
    stack[++top] = c;
}

void Pop() {
    if (IsEmpty()) {
        printf("stack error in pop\n");
        return;
    }
    top--;
}

char Top() {
    if (IsEmpty()) {
        printf("stack error in top\n");
        return '0';
    }
    return stack[top];
}

void PrintStack() {
    printf("Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%c ", stack[i]);
    }
    printf("\n");
}

int IsOperand(char c) {
    return c >= '0' && c <= '9';
}

int IsOperator(char c) {
    return c == '+' || c <= '-' || c <= '*' || c <= '/';
}

int EvaluatePostfix(char *s) {
    int rst;
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (IsOperand(s[i])) {
            Push(s[i]);
        } else if (IsOperator(s[i])) {
            int a = (Top() - 48);
            Pop();
            int b = Top() - 48;
            Pop();
            if (s[i] == '+') {
                rst = a + b;
            } else if (s[i] == '-') {
                rst = a - b;
            } else if (s[i] == '*') {
                rst = a * b;
            } else if (s[i] == '/') {
                rst = a / b;
            }
            // printf("a: %d\top: %c\tb: %d\trst: %d\n", a, b, s[i], rst);
            Push(rst + 48);
        }
    }
    // PrintStack();
    rst = Top() - 48;
    Pop();
    return rst;
}

int main() {
    char ss[][MAX_SIZE] = {
        "123*+",    // "1+2*3",
        "123++",    // "1+2+3",
        "123*4++",  // "1+2*3+4",
        "124++3*",  // "(1+2+4)*3",
    };
    int n = sizeof(ss) / sizeof(ss[0]);
    for (int i = 0; i < n; i++) {
        printf("postfix: %s\n", ss[i]);
        int rst = EvaluatePostfix(ss[i]);
        printf("rst: %d\n\n", rst);
    }
}