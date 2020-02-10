#include <stdio.h>
float ftoc(float fahr);
int main() {
    int lower = 0;
    int upper = 300;
    int step = 20;
    float fahr = lower;

    printf("----F to C:----\n");
    while(fahr <= upper){
        printf("%3.0f\t\%6.2f\n", fahr, ftoc(fahr));
        fahr += step;
    }
    return 0;
}

float ftoc(float fahr){
    return (5.0/9.0)*(fahr-32);
}
