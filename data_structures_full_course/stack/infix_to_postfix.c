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

int HigherPriority(char c, char ori) {
    if ((c == '*' || c == '/' || c == '+' || c == '-') && (ori == '+' || ori == '-')) {
        return 1;
    }
    return 0;
}

const char *InfixtoPostfix(char *s) {
    int n = strlen(s);
    char *rst = malloc(n + 1);
    rst[n] = '\0';
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (IsOperand(s[i])) {
            // printf("s[i]: %c", s[i]);
            rst[j++] = s[i];
        } else if (s[i] == '(') {
            Push(s[i]);
        } else if (s[i] == ')') {
            while (!IsEmpty() && Top() != '(') {
                rst[j++] = Top();
                Pop();
            }
            Pop();
        } else if (IsOperator(s[i])) {
            // printf("operator s[i]: %c\t", s[i]);
            // PrintStack();
            if (IsEmpty()) {
                Push(s[i]);
            } else if (Top() == '(' || HigherPriority(s[i], Top())) {
                Push(s[i]);
            } else {
                while (!IsEmpty() && !HigherPriority(s[i], Top())) {
                    rst[j++] = Top();
                    Pop();
                }
                Push(s[i]);
            }
            // PrintStack();
        }
    }
    // PrintStack();
    while (!IsEmpty()) {
        rst[j++] = Top();
        Pop();
    }
    return rst;
}

int main() {
    char ss[][MAX_SIZE] = {
        "1+2*3",
        "1+2+3",
        "1+2*3+4",
        "(1+2+4)*3",
    };
    int n = sizeof(ss) / sizeof(ss[0]);
    for (int i = 0; i < n; i++) {
        printf("infix: %s\n", ss[i]);
        const char *rst = InfixtoPostfix(ss[i]);
        printf("postfix: %s\n", rst);
    }
}
