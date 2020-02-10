#include <stdio.h>
int a = 1;
void extern2();

int main() {
    extern2();
    printf("a:%d\n", a);
    return 0;
}
