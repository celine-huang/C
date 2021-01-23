#include <stdio.h>
int main(){
    int a, b, c, d, e, surface, volume;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    surface = 2*(a*b + b*c + a*c + 4*d*((a-2*e) + (b-2*e) + (c-2*e)));
    volume = a*b*c - 2*d*((a-2*e)*(b-2*e) + (b-2*e)*(c-2*e) + (a-2*e)*(c-2*e));
    printf("%d\n%d\n", surface, volume);
    return 0;
}
