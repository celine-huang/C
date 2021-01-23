#include <stdio.h>

int sum(int n){
    if(n == 1)
        return 1;
    else
        return (n * n + sum(n - 1));
}

int main(void){
    int n;
    scanf("%d", &n);
    printf("%d\n", sum(n));
    return 0;
}
