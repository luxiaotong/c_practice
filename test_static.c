#include <stdio.h>

int main() {

    for( int i = 0; i < 5; i ++ ) {
        if ( i % 2 == 0 ) {
            static int count = 0;
            count ++;
            printf("count: %d\n", count);
        } 
    }
    return 0;
}
