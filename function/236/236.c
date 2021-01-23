#include <stdio.h>

int gcd(int a, int b);

int main(void){
    int lcm;
    scanf("%d", &lcm);
    int n;
    while(scanf("%d", &n) != EOF){
        lcm = lcm * n / gcd(n, lcm);
    }
    printf("%d\n", lcm);
    return 0;
}

int gcd(int a, int b){
    int temp;
    while(a % b != 0){
        temp = a % b;
        a = b;
        b = temp;
    }
    return b;
}
