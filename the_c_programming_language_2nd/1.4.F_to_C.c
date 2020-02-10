#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

int main() {
    float fahr, celsius;
    celsius = 0;
    printf("----F to C (Asc):----\n");
    for(fahr=LOWER;fahr<=UPPER;fahr+=STEP){
        celsius = (5.0/9.0)*(fahr-32);
        printf("%3.0f\t\%6.2f\n", fahr, celsius);
    }

    return 0;
}
