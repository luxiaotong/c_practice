#include <stdio.h>
#define MAXLEN 1000 //每行字符串最大长度

int getline2(char line[]);
void reverse(char line[], int n);

int main(){
    int n = 0;
    char line[MAXLEN];
    
    while(1){
        n = getline2(line);
        if(n == 1)
            break;

        // e 1-19
        printf("old line:%s\n", line);
        reverse(line, n);
        printf("new line:%s\n", line);
    }

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

    return i;
}

void reverse(char line[], int n) {
    int tmp;
    int i = 0;
    int j = n-2;
    while(i<j){
        tmp = line[i];
        line[i] = line[j];
        line[j] = tmp;
        i++;
        j--;
    }
}
