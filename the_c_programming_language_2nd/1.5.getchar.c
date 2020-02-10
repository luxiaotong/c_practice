#include <stdio.h>

int main(){
    /*
    int c;
    c = getchar();

    while(c!=EOF){
        putchar(c);
        c = getchar();
    }
    */

    // e 1-6
    //printf("c!=EOF: %d\n", c!=EOF);

    // e 1-7
    //printf("EOF: %d\n", EOF);

    /*
    // e 1-8
    int c;
    int ns;
    int nt;
    int nn;
    for(ns=0, nt=0, nn=0;(c=getchar())!=EOF;)
        if(c==' ')
            ns++;
        else if(c== '\t')
            nt++;
        else if(c== '\n')
            nn++;
    printf("ns: %d\n", ns);
    printf("nt: %d\n", nt);
    printf("nn: %d\n", nn);
    */

    /*
    // e 1-9
    int c;
    int ns;
    for(ns=0;(c=getchar())!=EOF;)
        if(c!=' ')
            if(ns==0)
                putchar(c);
            else {
                printf(" ");
                putchar(c);
                ns = 0;
            }
        else
            ns++;
    */

    // e 1-10
    int c;
    while((c = getchar()) != EOF){
        if(c == '\t'){
            printf("\\t");
        } else if(c == '\b'){
            printf("\\b");
        } else if(c == '\\'){
            printf("\\\\");
        } else {
            putchar(c);
        }
    }

    return 0;
}
