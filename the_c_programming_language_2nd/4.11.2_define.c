#include <stdio.h>
#define PRINT printf("test define \
    22222222 \
    33333333\n")
#define int_a int a = 3
int main() {
    PRINT;
    int_a;
    printf("a:%d\n", a);
    return 0;
}
