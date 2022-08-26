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

void timeval_sub(struct timeval *out, struct timeval *in)
{       
    if( (out->tv_usec -= in->tv_usec) < 0 )
    {   
        --out->tv_sec;
        out->tv_usec += 1000000;
    }
    out->tv_sec -= in->tv_sec;

    return;
}
