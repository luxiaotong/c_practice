#include <stdio.h>
int main() {
    int lower = 0;
    int upper = 300;
    int step = 20;

    float fahr = lower;
    float celsius = 0;

    printf("----F to C:----\n");
    while(fahr <= upper){
        celsius = (5.0/9.0)*(fahr-32);
        printf("%3.0f\t\%6.2f\n", fahr, celsius);
        fahr += step;
    }
    return 0;
}
