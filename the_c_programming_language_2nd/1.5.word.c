#include <stdio.h>
#define IN 1
#define OUT 0

int main() {
    // e 1-12
    int c;
    int state = OUT;
    while((c=getchar())!=EOF){
        if(c == '\t' || c == ' ' || c == '\n'){
            if(state == IN){
                printf("\n");
            }
        }else{
            state = IN;
            putchar(c);
        }
    }
    return 0;
}
