#include <stdio.h>
int main(){
    int x, first, second, third;
    scanf("%d", &x);
    first = x/100;
    second = (x%100)/10;
    third = x%10;
    printf("%d\n%d\n%d\n", first, second, third);
    return 0;
}
