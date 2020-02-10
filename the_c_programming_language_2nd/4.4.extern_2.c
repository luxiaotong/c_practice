#include <stdio.h>
extern int a;
void extern2(){
    a = 2;
    printf("extern:%d\n",a);
}
