#include <stdio.h>
int main() {
    float fahr, celsius;
    celsius = 0;
    printf("----F to C (Desc):----\n");
    //e 1-5
    for(fahr=300;fahr>=0;fahr-=20){
        celsius = (5.0/9.0)*(fahr-32);
        printf("%3.0f\t\%6.2f\n", fahr, celsius);
    }

    return 0;
}
