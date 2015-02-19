#include <stdio.h>
#include "my_util.h"

void parray(int *array, int len)
{
    int i = 0;
    for ( i = 0; i < len; i ++ ) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return;
}
