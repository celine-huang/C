#include <stdio.h>
#include <assert.h>
#define pi 3.1415926

int main(void){
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    assert(a > 0 && a <= 1000 && b > 0 && b <= 1000 && c <= a + b);
    double area = 0;
    if(c > 0)
        area += c * c * pi * 0.75;
    if(c > a)
        area += (c - a) * (c - a) * pi * 0.25;
    if(c > b)
        area += (c - b) * (c - b) * pi * 0.25;
    printf("%f\n", area);
    return 0;
}
