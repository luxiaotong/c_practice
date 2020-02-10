#include <stdio.h>
#define MAXLEN 1000 //每行字符串最大长度

int getline2(char line[]);
int copy(char from[], char to[]);
int trim(char line[], int n);

int main(){
    int n = 0;
    char line[MAXLEN];
    int max_len = 0;
    char max_ans[MAXLEN];
    
    while(1){
        n = getline2(line);
        if(n == 1)
            break;
        if(n > max_len){
            max_len = n;
            copy(line, max_ans);
        }

        /*
        // e 1-17
        if(n >= 80) {
            printf("length more than 80(length:%d):\n%s", n, line);
        }
        */
    }
    printf("max line is: %s\n", max_ans);

    // e 1-16
    printf("max length is: %d\n", max_len);

    return 0;
}

int getline2(char line[]){
    int c, i;
    for(i=0;(c=getchar())!=EOF&&i<MAXLEN-1;i++){
        if(c == '\n'){
            break;
        }
        line[i] = c;
    }
    line[++i]='\0';

    // e 1-18
    i = trim(line, i);

    return i;
}

int copy(char from[], char to[]) {
    int i;
    for(i = 0;i<MAXLEN && from[i]!='\0';i++){
        to[i] = from[i];
    }
    to[i+1] = '\0';
    return i+1;
}

int trim(char line[], int n){
    int i, c;
    for(i = n-1;i>=0;i--){
        c = line[i];
        if(c == ' '||c=='\t'){
            line[i]='\0';
            n--;
        }else{
            break;
        }
    }
    return n;
}
