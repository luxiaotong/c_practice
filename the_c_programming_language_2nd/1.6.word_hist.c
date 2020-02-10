#include <stdio.h>
#define IN 0
#define OUT 1
int main(){
    int c;
    int state = OUT;
    int i,nc;

    int nw_arr[10], nw_arr_rev[10];
    for(i=0;i<10;i++){
        nw_arr[i] = 0;
    }

    i = nc = 0;
    while((c=getchar())!=EOF){
        if(c==' ' || c=='\t' || c=='\n'){
            if(state==IN){
                //printf("nc:%d\n", nc);
                nw_arr[i++] = nc;
                nc = 0;
                state = OUT;
            }
        }else{
            nc++;
            state = IN;
        }
        //printf("%d\n",nw_arr[i]);
    }
    printf("result:\n");
    /*
    for(i=0;i<10;i++){
        printf("%d\n",nw_arr[i]);
    }
    */
    for(i=0;i<10;i++){
        nw_arr_rev[i] = 20 - nw_arr[i];
    }
    for(i=0;i<10;i++){
        printf("%d\n",nw_arr_rev[i]);
    }
    for(int j=0;j<20;j++){
        for(i=0;i<10;i++){
            if(nw_arr_rev[i]>0){
                printf("   \t");
            }else{
                printf("###\t");
            }
            nw_arr_rev[i] -= 1;
        }
        printf("\n");
    }
    for(i=0;i<10;i++){
        printf(" %d \t", i);
    }
    printf("\n");
    return 0;
}
