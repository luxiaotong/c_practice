#include <stdio.h>

int main() {
    int *t1[10];
    int t = 1;
    t1[0] = &t;

    int t10[10] = {1, 2, 3};
    int(*t2)[] = &t10;
    int i = 0;
    for (i = 0; i < 10; i++) {
        printf("%d: %d\n", i, (*t2)[i]);
    }
    return 0;
}