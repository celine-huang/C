#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    printf("%.1f\n%.1f\n", (- b - sqrt(b * b - 4 * a * c)) / (2 * a), (- b + sqrt(b * b - 4 * a * c)) / (2 * a));
    return 0;
}
