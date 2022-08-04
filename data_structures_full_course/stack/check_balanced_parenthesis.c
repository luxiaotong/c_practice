#include <stdio.h>
#include <string.h>

char stack[101];
int top = -1;

int IsEmpty() {
    return top == -1;
}

void Push(char c) {
    stack[++top] = c;
}

void Pop() {
    if (IsEmpty()) {
        printf("stack error");
        return;
    }
    top--;
}

char Top() {
    if (IsEmpty()) {
        printf("stack error");
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

int checkBalancedParenthesis(char *s, int n) {
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            Push(s[i]);
        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            char c = Top();
            if ((c == '(' && s[i] == ')') || (c == '[' && s[i] == ']') || (c == '{' && s[i] == '}')) {
                Pop();
                continue;
            }
            break;
        }
    }
    return IsEmpty();
}

int main() {
    int rst;
    char ss[][10] = {
        "()",
        "[({})]",
        "[)]",
        "[[[[",
    };
    int n = sizeof(ss) / sizeof(ss[0]);
    printf("n: %d\n", n);
    for (int i = 0; i < n; i++) {
        char *s = ss[i];
        printf("s: %s\t", s);
        rst = checkBalancedParenthesis(s, strlen(s));
        printf("rst: %d\n", rst);
    }
}