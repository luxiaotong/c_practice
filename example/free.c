#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = malloc(sizeof(int));
    *p = 10;
    printf("address: %p, value: %d\n", p, *p);
    free(p);
    p = NULL;
    printf("address: %p\n", p);
}