#include <stdio.h>
int main(){
    int i = 0;
    int j = 0;
    for(i=0;i<10;i++){
        printf("i1:%d\n", i);
        for(j=0;j<10;j++){
            printf("j:%d\n", j);
            break;
        }
        printf("i2:%d\n", i);
    }
}
