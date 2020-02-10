#include <stdio.h>
int main() {
    int lower = -6;
    int upper = 100;
    int step = 11;

    float celsius = lower;
    float fahr = 0;

    printf("----C to F:----\n");
    while(celsius <= upper){
        fahr = (9.0/5.0)*celsius+32;
        printf("%3.0f\t\%6.2f\n", celsius, fahr);
        celsius += step;
    }

    return 0;
}
